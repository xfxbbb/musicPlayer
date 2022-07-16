#pragma once
// ���������ļ���
#include <QObject>
#include <QFile>
#include <QtMultimedia/QMediaPlayer>

/*
TEXT:�������
*TCOP:��Ȩ(Copyright)
*TDAT:����
*TPE1:�������൱��ID3v1��Artist
USLT:���
*TT1:����������
TCON:����(���)
TBPM:ÿ���ӽ�����
TRCK:���죨���ţ�
*TKEY:����ؼ���
*TMED:ú������
*TOLY:ԭ�������
*TPOS:��Ʒ������
*TRSN:Inteneti��̨����
*/

struct SongInfo {
	QString _name;  // ��������
	QString _author;  // ����
	QString _time;  // ����ʱ��
	QString _path;  // ����·��
	QString _ImgFlag{"0"};  // �Ƿ���ͼƬ Ĭ��false��
	QString _imgPath;  // ͼƬ·��
	QString _imgType;  // ͼƬ����
	QString _showList;  // �б���ʾ
};

// ������Ϣ��ʽͷ ��ǩͷ+��ǩ֡1ͷ֡+��ǩ֡1����1+��ǩ֡2ͷ֡+��ǩ֡2����+....+ ���������ʽ����
// ǰ10λ
struct Info_tab { 
	char _format[3];  // ��ʽ
	char _version;  // �汾
	char _unuse[2];  
	char _headerSize[4];
};

struct Info_head{
	char _FrameID[4];  // �ĸ��ַ���ʶһ��֡
	char _size[4];  // ֡���ݵĴ�С,������֡ͷ ����С��1
	char Flags[2];  // ��ű�־
};

class CProcessMusicInfo  : public QObject
{
	Q_OBJECT

public:
	CProcessMusicInfo(QObject *parent);
	~CProcessMusicInfo();
	SongInfo _musicInfo;
	QMediaPlayer* _tempMP;
	bool processMusic(QString path);  // ����������Ϣ
signals:
	void signal_musicProcessAccess(SongInfo info);  // ��������ź�

};
