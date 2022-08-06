#include "MusicView.h"

MusicView::MusicView(QWidget *parent)
	: QTableView(parent)
{
    setMouseTracking(true);
    setSelectionBehavior(SelectRows);
}

MusicView::~MusicView()
{}

QModelIndex MusicView::hoverIndex() const
{
	return model()->index(m_HoverRow, m_HoverColumn);
}

void MusicView::mouseMoveEvent(QMouseEvent* event)
{
    QTableView::mouseMoveEvent(event);

    QModelIndex index = indexAt(event->pos());
    int oldHoverRow = m_HoverRow;
    int oldHoverColumn = m_HoverColumn;
    m_HoverRow = index.row();
    m_HoverColumn = index.column();

    if (selectionBehavior() == SelectRows && oldHoverRow != m_HoverRow)
    {
        for (int i = 0; i < model()->columnCount(); ++i)
        {
            update(model()->index(m_HoverRow, i));
        }
    }
    if (selectionBehavior() == SelectColumns && oldHoverColumn != m_HoverColumn)
    {
        for (int i = 0; i < model()->rowCount(); ++i) 
        {
            update(model()->index(i, m_HoverColumn));
            update(model()->index(i, oldHoverColumn));       // �����в�������ˢ�£����������update�����Ǳ����
        }
    }
}

void MusicView::mousePressEvent(QMouseEvent* event)
{
    QTableView::mousePressEvent(event);

    if (event->button() == Qt::RightButton)
    {
        emit signal_right_clicked();
    }
    else if (event->button() == Qt::LeftButton)
    {
        emit signal_left_clicked();
        return ;
    }

}
