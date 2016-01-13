#ifndef PLAYLISTMODEL_H
#define PLAYLISTMODEL_H

#include <QAbstractListModel>

QT_BEGIN_NAMESPACE
class QMediaPlaylist;
QT_END_NAMESPACE

class PlayListModel : public QAbstractItemModel
{
    Q_OBJECT
    Q_ENUMS(Qt::ItemDataRole)
public:
    PlayListModel(QObject *parent = 0);

    void setPlaylist(QMediaPlaylist *playlist);

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const;
    QModelIndex parent(const QModelIndex &child) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::DisplayRole);

private:
    QMediaPlaylist *m_playlist;
    QMap<QModelIndex, QVariant> m_data;

private slots:
    void beginInsertItems(int start, int end);
    void endInsertItems();
    void beginRemoveItems(int start, int end);
    void endRemoveItems();
    void changeItems(int start, int end);
};

#endif // PLAYLISTMODEL_H
