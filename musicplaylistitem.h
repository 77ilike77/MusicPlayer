#ifndef MUSICPLAYLISTITEM_H
#define MUSICPLAYLISTITEM_H

#include <QString>
#include <QTime>

class MusicPlayListItem
{
public:
    MusicPlayListItem();
    MusicPlayListItem(int index, QString name, QTime duration)
    {
        this->_index = index;
        this->_name = name;
        this->_duration = duration;
    }

    int index() const;
    QString name() const;
    QTime duration() const;

private:
    int _index;
    QString _name;
    QTime _duration;
};

#endif // MUSICPLAYLISTITEM_H
