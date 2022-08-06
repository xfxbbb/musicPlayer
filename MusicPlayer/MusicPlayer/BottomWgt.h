#pragma once
// �ײ�������
#include <QWidget>
#include "ui_BottomWgt.h"
#include "PublicData.h"
#include "SongListSmallWgt.h"
#include <QLabel>
#include "VolumeWgt.h"
#include <SkiaViewQtAdapter.hpp>
#include "LiveDate.h"

// �̳�SkiaView
class MySample : public SkiaUi::SkiaView {
public:
	using SkiaView::SkiaView;

protected:
	void onPaintEvent(SkiaUi::SkiaPaintEvent& evt) override;
	void onMousePressEvent(SkiaUi::SkiaMouseEvent& evt) override;
	void onMouseReleaseEvent(SkiaUi::SkiaMouseEvent& evt) override;
	void onMouseMoveEvent(SkiaUi::SkiaMouseEvent& evt) override;
private:

	float _pass_value{ 0.5 }; //0.0-1.0
	bool _pressed{ false };  // ����״̬
};

class CBottomWgt : public QWidget
{
	Q_OBJECT

public:
	CBottomWgt(QWidget *parent = nullptr);
	~CBottomWgt();
public:

	void init();
	QPushButton* _songListBtn;
	QPushButton* _startBtn;
	QPushButton* _inSongBtn;
	QPushButton* _nextSongBtn;
	QLabel* _musicNameLabel;
	VolumeWgt* _volumeWgt;
Q_SIGNALS:
	void sig_test(QString name, int age, double weight);
public slots:
	void slots_startBtn_clicked();  // ���Ű�ť�ۺ���
	void slots_voiceBtn_clicked(); // ���������ۺ���
private:
	Ui::CBottomWgtClass ui;

	MySample _sample;

	LiveData<int> lv_data;
};
