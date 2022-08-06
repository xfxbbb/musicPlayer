#pragma once
// 底部界面类
#include <QWidget>
#include "ui_BottomWgt.h"
#include "PublicData.h"
#include "SongListSmallWgt.h"
#include <QLabel>
#include "VolumeWgt.h"
#include <SkiaViewQtAdapter.hpp>
#include "LiveDate.h"

// 继承SkiaView
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
	bool _pressed{ false };  // 按下状态
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
	void slots_startBtn_clicked();  // 播放按钮槽函数
	void slots_voiceBtn_clicked(); // 音量调整槽函数
private:
	Ui::CBottomWgtClass ui;

	MySample _sample;

	LiveData<int> lv_data;
};
