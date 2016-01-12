#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QBuffer>
#include <QFileInfo>

class MusicPlayer : public QMainWindow
{
    Q_OBJECT
    Q_PROPERTY(QMediaPlayer::State state READ state)

public:
    Q_INVOKABLE void play();
    Q_INVOKABLE void pause();
    static MusicPlayer* getInstance();
    QMediaPlayer::State state();

private:
    static MusicPlayer* mMusicPlayer;
    QMediaPlayer* mQMediaPlayer;
    explicit MusicPlayer(QWidget *parent = 0);

signals:

public slots:
};

#endif // MUSICPLAYER_H
