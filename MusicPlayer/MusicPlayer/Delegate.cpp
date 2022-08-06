#include "Delegate.h"

Delegate::Delegate(QObject *parent)
	: QItemDelegate(parent)
{}

Delegate::~Delegate()
{}

void Delegate::paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const
{
	/// ÖØÐ´»æÖÆº¯Êý ///
	////QItemDelegate::paint(painter, option, index);
	//if (index.isValid() && index.column() == 3)
	//{
	//	if (option.state.testFlag(QStyle::State_MouseOver))  // Êó±êÐü¸¡×´Ì¬
	//	{
	//		//_ctrlWgt = new MusicViewCtrlWgt;
	//
	//	}
	//}

	QStyleOptionViewItem opt(option);
	opt.state &= ~QStyle::State_HasFocus;

	MusicView* view = qobject_cast<MusicView*>(opt.styleObject);
	QTableView::SelectionBehavior behavior = view->selectionBehavior();
	QModelIndex hoverIndex = view->hoverIndex();

	if (!(option.state & QStyle::State_Selected) && behavior != QTableView::SelectItems)
	{
		if (behavior == QTableView::SelectRows && hoverIndex.row() == index.row())
			opt.state |= QStyle::State_MouseOver;
		if (behavior == QTableView::SelectColumns && hoverIndex.column() == index.column())
			opt.state |= QStyle::State_MouseOver;
	}
	QItemDelegate::paint(painter, opt, index);
}

//QSize Delegate::sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const
//{
//	/// ÖØÐ´³ß´ç¿ØÖÆº¯Êý ///
//	QItemDelegate::sizeHint(option, index);
//	return QSize();
//}

QWidget* Delegate::createEditor(QWidget * parent, const QStyleOptionViewItem & option, const QModelIndex & index) const
{
	/// ÖØÐ´±à¼­º¯Êý ///
	if (index.isValid() && index.column() == 3)
	{
		_ctrlWgt = new MusicViewCtrlWgt(parent);
		_ctrlWgt->installEventFilter(const_cast<Delegate*> (this));
		return _ctrlWgt;
	}
	else {
		return nullptr;
	}
	//return nullptr;
}

MuiscStyledItemDelegate::MuiscStyledItemDelegate()
{

}

void MuiscStyledItemDelegate::paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
	QStyleOptionViewItem opt(option);
	opt.state &= ~QStyle::State_HasFocus;

	MusicView* view = qobject_cast<MusicView*>(opt.styleObject);
	
	QTableView::SelectionBehavior behavior = view->selectionBehavior();
	QModelIndex hoverIndex = view->hoverIndex();

	if (!(option.state & QStyle::State_Selected) && behavior != QTableView::SelectItems)
	{
		if (behavior == QTableView::SelectRows && hoverIndex.row() == index.row())
		{
			opt.state |= QStyle::State_MouseOver;
		}
		if (behavior == QTableView::SelectColumns && hoverIndex.column() == index.column())
		{
			opt.state |= QStyle::State_MouseOver;
		}
	}
	QStyledItemDelegate::paint(painter, opt, index);
}
