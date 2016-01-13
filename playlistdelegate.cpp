#include "playlistdelegate.h"
#include <QPainter>
#include <QStyledItemDelegate>

PlayListDelegate::PlayListDelegate(QObject *parent) : QItemDelegate(parent)
{

}

void PlayListDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QStyleOptionViewItemV4 opt = setOptions(index, option);

    painter->save();

    const QString& text = index.data(Qt::DisplayRole);

    QRect rect = QRect(opt.rect.topLeft(), QSize(100,30));

    painter->drawText(rect, text);

    drawFocus(painter, opt, rect);

    painter->restore();
}

QSize PlayListDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    return QSize(100,30);
}
