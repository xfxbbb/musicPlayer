#pragma once
// 解析音乐文件类
#include <QObject>
#include <QFile>
#include <QtMultimedia/QMediaPlayer>

/*
TEXT:歌词作者
*TCOP:版权(Copyright)
*TDAT:日期
*TPE1:艺术家相当于ID3v1的Artist
USLT:歌词
*TT1:内容组描述
TCON:流派(风格)
TBPM:每分钟节拍数
TRCK:音轨（曲号）
*TKEY:最初关键字
*TMED:煤体类型
*TOLY:原歌词作者
*TPOS:作品集部分
*TRSN:Inteneti电台名称
*/

struct SongInfo {
	QString _name;  // 歌曲名称
	QString _author;  // 歌手
	QString _time;  // 歌曲时长
	QString _path;  // 歌曲路径
	QString _ImgFlag{"0"};  // 是否有图片 默认false无
	QString _imgPath;  // 图片路径
	QString _imgType;  // 图片类型
	QString _showList;  // 列表显示
};

// 音乐信息格式头 标签头+标签帧1头帧+标签帧1内容1+标签帧2头帧+标签帧2内容+....+ 最后音乐正式内容
// 前10位
struct Info_tab { 
	char _format[3];  // 格式
	char _version;  // 版本
	char _unuse[2];  
	char _headerSize[4];
};

struct Info_head{
	char _FrameID[4];  // 四个字符标识一个帧
	char _size[4];  // 帧内容的大小,不包括帧头 不能小于1
	char Flags[2];  // 存放标志
};

class CProcessMusicInfo  : public QObject
{
	Q_OBJECT

public:
	CProcessMusicInfo(QObject *parent);
	~CProcessMusicInfo();
	SongInfo _musicInfo;
	QMediaPlayer* _tempMP;
	bool processMusic(QString path);  // 处理音乐信息
signals:
	void signal_musicProcessAccess(SongInfo info);  // 处理完成信号

};
