#ifndef MUSICPLAYLISTMODEL_H
#define MUSICPLAYLISTMODEL_H

#include <QObject>
#include <QAbstractListModel>

QT_BEGIN_NAMESPACE
class QMediaPlaylist;
QT_END_NAMESPACE

class MusicPlayListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum MusicPlayListRoles
    {
        Number = Qt::UserRole + 1,
        Name,
        Duration
    };

    MusicPlayListModel(QObject *parent = 0);
    void setPlaylist(QMediaPlaylist *playlist);

    QHash<int, QByteArray> roleNames() const;
    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

private:
    QMediaPlaylist *_mediaplay_list;

private slots:
    void beginInsertItems(int start, int end);
    void endInsertItems();
    void beginRemoveItems(int start, int end);
    void endRemoveItems();
    void changeItems(int start, int end);
};

#endif // MUSICPLAYLISTMODEL_H
