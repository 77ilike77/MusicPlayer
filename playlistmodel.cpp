#include "playlistmodel.h"
#include <QMediaPlaylist>
#include <QFileInfo>

PlayListModel::PlayListModel(QObject *parent)
    : QAbstractItemModel(parent), m_playlist(0)
{
}

void PlayListModel::setPlaylist(QMediaPlaylist *playlist)
{
    if (m_playlist) {
        disconnect(m_playlist, SIGNAL(mediaAboutToBeInserted(int,int)), this, SLOT(beginInsertItems(int,int)));
        disconnect(m_playlist, SIGNAL(mediaInserted(int,int)), this, SLOT(endInsertItems()));
        disconnect(m_playlist, SIGNAL(mediaAboutToBeRemoved(int,int)), this, SLOT(beginRemoveItems(int,int)));
        disconnect(m_playlist, SIGNAL(mediaRemoved(int,int)), this, SLOT(endRemoveItems()));
        disconnect(m_playlist, SIGNAL(mediaChanged(int,int)), this, SLOT(changeItems(int,int)));
    }
    beginResetModel();
    m_playlist = playlist;

    if (m_playlist) {
        connect(m_playlist, SIGNAL(mediaAboutToBeInserted(int,int)), this, SLOT(beginInsertItems(int,int)));
        connect(m_playlist, SIGNAL(mediaInserted(int,int)), this, SLOT(endInsertItems()));
        connect(m_playlist, SIGNAL(mediaAboutToBeRemoved(int,int)), this, SLOT(beginRemoveItems(int,int)));
        connect(m_playlist, SIGNAL(mediaRemoved(int,int)), this, SLOT(endRemoveItems()));
        connect(m_playlist, SIGNAL(mediaChanged(int,int)), this, SLOT(changeItems(int,int)));
    }
    endResetModel();
}

int PlayListModel::rowCount(const QModelIndex &parent) const
{
    return m_playlist && !parent.isValid() ? m_playlist->mediaCount() : 0;
}

int PlayListModel::columnCount(const QModelIndex &parent) const
{
    return !parent.isValid() ? 2 : 0;
}

QModelIndex PlayListModel::index(int row, int column, const QModelIndex &parent) const
{
    return m_playlist && !parent.isValid()
            && row >= 0 && row < m_playlist->mediaCount()
            && column >= 0 && column < 2
        ? createIndex(row, column)
        : QModelIndex();
}

QModelIndex PlayListModel::parent(const QModelIndex &child) const
{
    Q_UNUSED(child);

    return QModelIndex();
}

QVariant PlayListModel::data(const QModelIndex &index, int role) const
{
    if (index.isValid() && role == Qt::DisplayRole) {
        QVariant value = m_data[index];
        if (!value.isValid()) {
            if (index.column() == 0) {
                QUrl location = m_playlist->media(index.row()).canonicalUrl();
                return QFileInfo(location.path()).fileName();
            }
            else if (index.column() == 1)
            {
                return index.row();
            }
        }
        return value;
    }
    return QVariant();
}

bool PlayListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    Q_UNUSED(role);
    m_data[index] = value;
    emit dataChanged(index, index);
    qDebug("setData");
    return true;
}

void PlayListModel::beginInsertItems(int start, int end)
{
    beginInsertRows(QModelIndex(), start, end);
    qDebug("beginInsertItems at %d,%d",start ,end);
}

void PlayListModel::endInsertItems()
{
    endInsertRows();
    qDebug("endInsertItems");
}

void PlayListModel::beginRemoveItems(int start, int end)
{
    beginRemoveRows(QModelIndex(), start, end);
    qDebug("beginRemoveItems at %d,%d");
}

void PlayListModel::endRemoveItems()
{
    endRemoveRows();
    qDebug("endRemoveItems");
}

void PlayListModel::changeItems(int start, int end)
{
    emit dataChanged(index(start,0), index(end,1));
    qDebug("changeItems");
}
