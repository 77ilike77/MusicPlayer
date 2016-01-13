#ifndef PLAYLISTDELEGATE_H
#define PLAYLISTDELEGATE_H

#include <QItemDelegate>
#include <QSize>

class PlayListDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    PlayListDelegate(QObject *parent = 0);

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

#endif // PLAYLISTDELEGATE_H
