#pragma once
#include <QObject>
#include <QItemDelegate>
#include <QTableView>
#include "MusicView.h"
#include "MusicViewCtrlWgt.h"
#include <QStyledItemDelegate>

class Delegate  : public QItemDelegate
{
	Q_OBJECT

public:
	Delegate(QObject *parent);
    Delegate() {}
    ~Delegate();

    // 重写绘制函数
    void paint(QPainter* painter,const QStyleOptionViewItem& option,const QModelIndex& index) const override;

    // 重写尺寸控制函数
    /*QSize sizeHint(const QStyleOptionViewItem& option,const QModelIndex& index) const override;*/

    // 重写编辑函数
    QWidget* createEditor(QWidget* parent,const QStyleOptionViewItem& option,const QModelIndex& index) const override;

private:
     mutable MusicViewCtrlWgt* _ctrlWgt;
};

class MuiscStyledItemDelegate : public QStyledItemDelegate
{
public:
    MuiscStyledItemDelegate();

public:
    virtual void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const Q_DECL_OVERRIDE;
};

