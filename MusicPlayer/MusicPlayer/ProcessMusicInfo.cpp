#include "ProcessMusicInfo.h"
#include <QTextStream>
#include <QTextCodec>
CProcessMusicInfo::CProcessMusicInfo(QObject *parent)
	: QObject(parent)
{
    _tempMP = new QMediaPlayer;
    connect(_tempMP, &QMediaPlayer::durationChanged, this, [=](qint64 duration) {
        if (duration != 0)
        {
            //qDebug()<<"信号";
            int secs = duration / 1000; //全部秒数
            int mins = secs / 60;//分
            secs = secs % 60;//秒
            QString durationTime = QString::asprintf("%2d:%2d", mins, secs);
            _musicInfo._time = QString(durationTime);
            //        qDebug()<<m_music_info.mic_name;
            //        qDebug()<<m_music_info.mic_name.length();
            //        qDebug()<<m_music_info.mic_songer.length();
                    //设置展示的信息
                    //1.统一歌名长度：17字符，过短+空格，过长截取+...
            QString tempname = _musicInfo._name;
            int nameadd = 17 - _musicInfo._name.length();
            if (nameadd >= 0)
            {
                for (int n = 0; n < nameadd; n++)
                {
                    tempname += " ";
                }
            }
            else
            {
                tempname = tempname.mid(0, 15) + "...";
            }
            //2.统一歌手长度：6字符，过短+空格，过长截取+...
            QString tempsonger = _musicInfo._author;
            int songeradd = 6 - _musicInfo._author.length();
            if (songeradd >= 0)
            {
                for (int n = 0; n < songeradd; n++)
                {
                    tempsonger += " ";
                }
            }
            else
            {
                tempsonger = tempsonger.mid(0, 5) + "...";
            }
            _musicInfo._showList = QString("%1\t%2\t%3").arg(tempname).arg(tempsonger).arg(_musicInfo._time);
            emit signal_musicProcessAccess(_musicInfo);
        }
        });
}

CProcessMusicInfo::~CProcessMusicInfo()
{}

bool CProcessMusicInfo::processMusic(QString path)
{
	///处理音乐信息///
	// 先初始化信息
	_musicInfo._author = "";
	_musicInfo._name = "";
	_musicInfo._time = "";
	_musicInfo._imgType = "";
	_musicInfo._imgPath = "";
    _musicInfo._path = "";
	
	// mp3IDV2解析
    QFile file(path);
    bool isok = file.open(QIODevice::ReadOnly);
    Info_tab tab_info;
    qint64 head_size = 0;       //头部大小
    qint64 file_seek = 0;       //文件指针
    quint64 len;
    if (isok == false)
    {
        qDebug() << "open error";
        file.close();
        return false;
    }
    //文件打开成功
    _musicInfo._path = path;                         //记录mp3文件的路径
    file.read((char*)&tab_info, sizeof(tab_info));
    file_seek = file_seek + 10;
    //判断是否为mp3的IDV2格式
    //qDebug()<<QString(tab_info.format);
    if (QString(tab_info._format) != "ID3\u0003" || (int)tab_info._version != 3)
    {
        qDebug() << "mp3 is not ID3V2 error";
        return false;
    }

    head_size = (tab_info._headerSize[0] & 0xff) << 21 |
        (tab_info._headerSize[1] & 0xff) << 14 |
        (tab_info._headerSize[2] & 0xff) << 7 |
        (tab_info._headerSize[3] & 0xff);   //每8位只用前7位，第8位无效恒为0;

    Info_head head_info;
    quint32 size;

    while (file_seek < head_size)
    {
        //读取头部信息
        len = file.read((char*)&head_info, sizeof(head_info));
        file_seek = file_seek + len;
        size = (head_info._size[0] & 0xff) << 24 | (head_info._size[1] & 0xff) << 16 | (head_info._size[2] & 0xff) << 8 | (head_info._size[3] & 0xff);
        //有"TIT2""TPE1""TALB""TXXX" "TRCK""TPOS""TCON""APIC"
        //qDebug()<<QString(head_info._FrameID);
        if (QString(head_info._FrameID) == "TIT2")        //曲名
        {
            QTextStream stream(&file);
            stream.seek(file.pos() + 1);
            QString all = stream.readLine((int)(size / 2 - 1)); //unicode编码中文是两个字节为一个中文，外加结束为零。
            QTextCodec* codec = QTextCodec::codecForName("GBK");
            QString name = codec->toUnicode(all.toLocal8Bit().data());
            //qDebug()<<name;
            _musicInfo._name = name;
            file_seek = file_seek + size;
            file.seek(file_seek);
            continue;
        }
        if (QString(head_info._FrameID) == "TPE1")        //歌手
        {
            QTextStream stream(&file);
            stream.seek(file.pos() + 1);
            QString all = stream.readLine((int)(size / 2 - 1)); //unicode编码中文是两个字节为一个中文，外加结束为零。
            QTextCodec* codec = QTextCodec::codecForName("GBK");
            QString author = codec->toUnicode(all.toLocal8Bit().data());
            //qDebug()<<author;
            _musicInfo._author = author;
            file_seek = file_seek + size;
            file.seek(file_seek);
            continue;
        }

        if (QString(head_info._FrameID) == "APIC")        //图片
        {
            _musicInfo._ImgFlag = "1";
            file_seek = file_seek + 14;       //去掉14位为照片描述
            file.seek(file_seek);

            char* piture = (char*)malloc(size);
            file.read((char*)piture, size - 14);
            file_seek = file_seek + size - 14;

            //判断照片的存储格式jpg/png
            if (((uchar)piture[0] == 255) && ((uchar)piture[1] == 216)) //0xff 0xd8  ->jpg
            {
                _musicInfo._imgType = "jpg";
            }
            else if (((uchar)piture[0] == 137) && ((uchar)piture[1] == 80)) //0x89 0x50  ->png
            {
                _musicInfo._imgType = "png";
            }
            QString path = QString("../db/Pictures_db/%1.%2").arg(_musicInfo._name).arg(_musicInfo._imgType);
            _musicInfo._imgPath = path;
            QFile testpic(path);
            testpic.open(QIODevice::WriteOnly);
            testpic.write(piture, size - 14);
            testpic.close();
            free(piture);
            continue;
        }
        //其他信息不需要
        file_seek = file_seek + size;
        file.seek(file_seek);
    }
    file.close();
    //读取歌曲时间：
    _tempMP->setMedia(QUrl(path));   //指定源为qrc文件，获取时长
    return true;
}
