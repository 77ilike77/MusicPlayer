#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QMediaPlaylist>

class MusicPlayer : public QObject
{
    Q_OBJECT

    Q_ENUMS(QMediaPlayer::State)
    Q_ENUMS(QMediaPlayer::MediaStatus)
    Q_ENUMS(QMediaPlayer::Error)

    Q_PROPERTY(QMediaPlayer::State state READ state NOTIFY stateChanged)
    Q_PROPERTY(QMediaPlayer::MediaStatus status READ status NOTIFY statusChanged)
    Q_PROPERTY(QMediaPlayer::Error error READ error NOTIFY errorChanged)

public:
    static MusicPlayer* getInstance();

    Q_INVOKABLE void play();
    Q_INVOKABLE void pause();
    Q_INVOKABLE void stop();

    Q_INVOKABLE void next();

    Q_INVOKABLE void add(QList<QUrl> filePath);

    QMediaPlayer::State state();
    QMediaPlayer::MediaStatus status();
    QMediaPlayer::Error error();

private:
    static MusicPlayer* mMusicPlayer;
    QMediaPlayer* mQMediaPlayer;
    QMediaPlaylist* mList;

    explicit MusicPlayer(QObject *parent = 0);

signals:
    void stateChanged();
    void statusChanged();
    void errorChanged();

    void currentIndexChanged(int index);
    void playbackModeChanged(QMediaPlaylist::PlaybackMode mode);
    void currentMediaChanged(const QMediaContent&);
    void mediaAboutToBeInserted(int start, int end);
    void mediaInserted(int start, int end);
    void mediaAboutToBeRemoved(int start, int end);
    void mediaRemoved(int start, int end);
    void mediaChanged(int start, int end);
    void loaded();
    void loadFailed();

public slots:
};

#endif // MUSICPLAYER_H
