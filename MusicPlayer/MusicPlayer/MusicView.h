#pragma once
// “Ù¿÷¡–±Ì¿‡ TableView
#include <QTableView>
#include <QModelIndex>
#include <QMouseEvent>
class MusicView  : public QTableView
{
	Q_OBJECT

public:
	MusicView(QWidget*parent);
	~MusicView();
	QModelIndex hoverIndex() const;
Q_SIGNALS:
	void signal_right_clicked();
	void signal_left_clicked();
protected:
	virtual void mouseMoveEvent(QMouseEvent* event) Q_DECL_OVERRIDE;
	virtual void mousePressEvent(QMouseEvent* event) Q_DECL_OVERRIDE;
private:
	int m_HoverRow{-1};
	int m_HoverColumn{-1};
};
