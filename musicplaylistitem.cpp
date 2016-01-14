#include "musicplaylistitem.h"

MusicPlayListItem::MusicPlayListItem():_index(-1),_duration()
{

}

int MusicPlayListItem::index() const
{
    return this->_index;
}

QString MusicPlayListItem::name() const
{
    return this->_name;
}

QTime MusicPlayListItem::duration() const
{
    return this->_duration;
}
