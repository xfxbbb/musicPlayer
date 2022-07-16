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
            //qDebug()<<"�ź�";
            int secs = duration / 1000; //ȫ������
            int mins = secs / 60;//��
            secs = secs % 60;//��
            QString durationTime = QString::asprintf("%2d:%2d", mins, secs);
            _musicInfo._time = QString(durationTime);
            //        qDebug()<<m_music_info.mic_name;
            //        qDebug()<<m_music_info.mic_name.length();
            //        qDebug()<<m_music_info.mic_songer.length();
                    //����չʾ����Ϣ
                    //1.ͳһ�������ȣ�17�ַ�������+�ո񣬹�����ȡ+...
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
            //2.ͳһ���ֳ��ȣ�6�ַ�������+�ո񣬹�����ȡ+...
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
	///����������Ϣ///
	// �ȳ�ʼ����Ϣ
	_musicInfo._author = "";
	_musicInfo._name = "";
	_musicInfo._time = "";
	_musicInfo._imgType = "";
	_musicInfo._imgPath = "";
    _musicInfo._path = "";
	
	// mp3IDV2����
    QFile file(path);
    bool isok = file.open(QIODevice::ReadOnly);
    Info_tab tab_info;
    qint64 head_size = 0;       //ͷ����С
    qint64 file_seek = 0;       //�ļ�ָ��
    quint64 len;
    if (isok == false)
    {
        qDebug() << "open error";
        file.close();
        return false;
    }
    //�ļ��򿪳ɹ�
    _musicInfo._path = path;                         //��¼mp3�ļ���·��
    file.read((char*)&tab_info, sizeof(tab_info));
    file_seek = file_seek + 10;
    //�ж��Ƿ�Ϊmp3��IDV2��ʽ
    //qDebug()<<QString(tab_info.format);
    if (QString(tab_info._format) != "ID3\u0003" || (int)tab_info._version != 3)
    {
        qDebug() << "mp3 is not ID3V2 error";
        return false;
    }

    head_size = (tab_info._headerSize[0] & 0xff) << 21 |
        (tab_info._headerSize[1] & 0xff) << 14 |
        (tab_info._headerSize[2] & 0xff) << 7 |
        (tab_info._headerSize[3] & 0xff);   //ÿ8λֻ��ǰ7λ����8λ��Ч��Ϊ0;

    Info_head head_info;
    quint32 size;

    while (file_seek < head_size)
    {
        //��ȡͷ����Ϣ
        len = file.read((char*)&head_info, sizeof(head_info));
        file_seek = file_seek + len;
        size = (head_info._size[0] & 0xff) << 24 | (head_info._size[1] & 0xff) << 16 | (head_info._size[2] & 0xff) << 8 | (head_info._size[3] & 0xff);
        //��"TIT2""TPE1""TALB""TXXX" "TRCK""TPOS""TCON""APIC"
        //qDebug()<<QString(head_info._FrameID);
        if (QString(head_info._FrameID) == "TIT2")        //����
        {
            QTextStream stream(&file);
            stream.seek(file.pos() + 1);
            QString all = stream.readLine((int)(size / 2 - 1)); //unicode���������������ֽ�Ϊһ�����ģ���ӽ���Ϊ�㡣
            QTextCodec* codec = QTextCodec::codecForName("GBK");
            QString name = codec->toUnicode(all.toLocal8Bit().data());
            //qDebug()<<name;
            _musicInfo._name = name;
            file_seek = file_seek + size;
            file.seek(file_seek);
            continue;
        }
        if (QString(head_info._FrameID) == "TPE1")        //����
        {
            QTextStream stream(&file);
            stream.seek(file.pos() + 1);
            QString all = stream.readLine((int)(size / 2 - 1)); //unicode���������������ֽ�Ϊһ�����ģ���ӽ���Ϊ�㡣
            QTextCodec* codec = QTextCodec::codecForName("GBK");
            QString author = codec->toUnicode(all.toLocal8Bit().data());
            //qDebug()<<author;
            _musicInfo._author = author;
            file_seek = file_seek + size;
            file.seek(file_seek);
            continue;
        }

        if (QString(head_info._FrameID) == "APIC")        //ͼƬ
        {
            _musicInfo._ImgFlag = "1";
            file_seek = file_seek + 14;       //ȥ��14λΪ��Ƭ����
            file.seek(file_seek);

            char* piture = (char*)malloc(size);
            file.read((char*)piture, size - 14);
            file_seek = file_seek + size - 14;

            //�ж���Ƭ�Ĵ洢��ʽjpg/png
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
        //������Ϣ����Ҫ
        file_seek = file_seek + size;
        file.seek(file_seek);
    }
    file.close();
    //��ȡ����ʱ�䣺
    _tempMP->setMedia(QUrl(path));   //ָ��ԴΪqrc�ļ�����ȡʱ��
    return true;
}
