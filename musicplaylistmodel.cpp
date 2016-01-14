#include "musicplaylistmodel.h"
#include <QMediaPlaylist>
#include <QFileInfo>

MusicPlayListModel::MusicPlayListModel(QObject *parent) : QAbstractListModel(parent), _mediaplay_list(0)
{
}

void MusicPlayListModel::setPlaylist(QMediaPlaylist *playlist)
{
    if (_mediaplay_list) {
        disconnect(_mediaplay_list, SIGNAL(mediaAboutToBeInserted(int,int)), this, SLOT(beginInsertItems(int,int)));
        disconnect(_mediaplay_list, SIGNAL(mediaInserted(int,int)), this, SLOT(endInsertItems()));
        disconnect(_mediaplay_list, SIGNAL(mediaAboutToBeRemoved(int,int)), this, SLOT(beginRemoveItems(int,int)));
        disconnect(_mediaplay_list, SIGNAL(mediaRemoved(int,int)), this, SLOT(endRemoveItems()));
        disconnect(_mediaplay_list, SIGNAL(mediaChanged(int,int)), this, SLOT(changeItems(int,int)));
    }
    beginResetModel();
    _mediaplay_list = playlist;

    if (_mediaplay_list) {
        connect(_mediaplay_list, SIGNAL(mediaAboutToBeInserted(int,int)), this, SLOT(beginInsertItems(int,int)));
        connect(_mediaplay_list, SIGNAL(mediaInserted(int,int)), this, SLOT(endInsertItems()));
        connect(_mediaplay_list, SIGNAL(mediaAboutToBeRemoved(int,int)), this, SLOT(beginRemoveItems(int,int)));
        connect(_mediaplay_list, SIGNAL(mediaRemoved(int,int)), this, SLOT(endRemoveItems()));
        connect(_mediaplay_list, SIGNAL(mediaChanged(int,int)), this, SLOT(changeItems(int,int)));
    }
    endResetModel();
}

QHash<int, QByteArray> MusicPlayListModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[Number] = "number";
    roles[Name] = "name";
    roles[Duration] = "duration";
    return roles;
}

int MusicPlayListModel::rowCount(const QModelIndex & parent) const
{
    return _mediaplay_list && !parent.isValid() ? _mediaplay_list->mediaCount() : 0;
}

QVariant MusicPlayListModel::data(const QModelIndex & index, int role) const
{
    if (index.isValid())
    {
        QMediaContent item = _mediaplay_list->media(index.row());
        if (item == NULL)
        {
            return QVariant();
        }
        if (role == Number)
        {
            return index.row() + 1;
        }
        if (role == Name)
        {
            QUrl location = item.canonicalUrl();
            return QFileInfo(location.path()).fileName();
        }
        if (role == Duration)
        {
            return 0;
        }
    }
    return QVariant();
}

void MusicPlayListModel::beginInsertItems(int start, int end)
{
    beginInsertRows(QModelIndex(), start, end);
}

void MusicPlayListModel::endInsertItems()
{
    endInsertRows();
}

void MusicPlayListModel::beginRemoveItems(int start, int end)
{
    beginRemoveRows(QModelIndex(), start, end);
}

void MusicPlayListModel::endRemoveItems()
{
    endRemoveRows();
}

void MusicPlayListModel::changeItems(int start, int end)
{
    emit dataChanged(index(start,0), index(end,1));
}
