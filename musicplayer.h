#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QListView>
#include "musicplaylistmodel.h"

class MusicPlayer : public QObject
{
    Q_OBJECT

    Q_ENUMS(QMediaPlayer::State)
    Q_ENUMS(QMediaPlayer::MediaStatus)
    Q_ENUMS(QMediaPlayer::Error)
    Q_ENUMS(MusicPlayer::PlaybackMode)

    Q_PROPERTY(QMediaPlayer::State state READ state NOTIFY stateChanged)
    Q_PROPERTY(QMediaPlayer::MediaStatus status READ status NOTIFY statusChanged)
    Q_PROPERTY(QMediaPlayer::Error error READ error NOTIFY errorChanged)

    Q_PROPERTY(int currentIndex READ currentIndex NOTIFY currentIndexChanged)
    Q_PROPERTY(qint64 currentPosition READ currentPosition NOTIFY currentPositionChanged)
    Q_PROPERTY(qint64 currentDuration READ currentDuration NOTIFY currentDurationChanged)
    Q_PROPERTY(QMediaPlaylist::PlaybackMode mode READ mode NOTIFY modeChanged)

public:
    enum PlaybackMode {
        CurrentItemInLoop = QMediaPlaylist::CurrentItemInLoop,
        Loop = QMediaPlaylist::Loop,
        Random = QMediaPlaylist::Random
    };

    static MusicPlayer* getInstance();

    Q_INVOKABLE void play();
    Q_INVOKABLE void play(int index);
    Q_INVOKABLE void pause();
    Q_INVOKABLE void stop();

    Q_INVOKABLE void next();
    Q_INVOKABLE void previous();

    Q_INVOKABLE void seek(qint64 pos);
    Q_INVOKABLE bool isSeekable();

    Q_INVOKABLE void changePlaybackMode(QMediaPlaylist::PlaybackMode mode);
    Q_INVOKABLE void changePlaybackMode();
    Q_INVOKABLE QMediaPlaylist::PlaybackMode mode();

    Q_INVOKABLE void add(QList<QUrl> filePath);
    Q_INVOKABLE void remove(int index);

    int currentIndex() const;
    qint64 currentPosition() const;
    qint64 currentDuration() const;

    QMediaPlayer::State state();
    QMediaPlayer::MediaStatus status();
    QMediaPlayer::Error error();

    void setPlayListModel(QListView* playlist);

    MusicPlayListModel *playlistModel;

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

    void modeChanged(QMediaPlaylist::PlaybackMode mode);
    void currentPositionChanged(qint64 position);
    void currentDurationChanged(qint64 position);

public slots:
};

#endif // MUSICPLAYER_H
