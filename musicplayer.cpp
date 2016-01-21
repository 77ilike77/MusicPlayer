#include "musicplayer.h"

MusicPlayer* MusicPlayer::mMusicPlayer = NULL;

MusicPlayer::MusicPlayer(QObject *parent) : QObject(parent)
{
    mQMediaPlayer = new QMediaPlayer();
    mQMediaPlayer->setVolume(100);

    mList = new QMediaPlaylist();
    mList->setPlaybackMode(QMediaPlaylist::Loop);
    mQMediaPlayer->setPlaylist(mList);

    playlistModel = new MusicPlayListModel(this);
    playlistModel->setPlaylist(mList);

    connect(mQMediaPlayer, SIGNAL(stateChanged(QMediaPlayer::State)), SIGNAL(stateChanged()));
    connect(mQMediaPlayer, SIGNAL(mediaStatusChanged(QMediaPlayer::MediaStatus)), SIGNAL(statusChanged()));
    connect(mQMediaPlayer, SIGNAL(error(QMediaPlayer::Error)), SIGNAL(errorChanged()));
    connect(mList, SIGNAL(currentIndexChanged(int)), SIGNAL(currentIndexChanged(int)));
    connect(mList, SIGNAL(playbackModeChanged(QMediaPlaylist::PlaybackMode)), SIGNAL(modeChanged(QMediaPlaylist::PlaybackMode)));
    connect(mQMediaPlayer, SIGNAL(positionChanged(qint64)), SIGNAL(currentPositionChanged(qint64)));
    connect(mQMediaPlayer, SIGNAL(durationChanged(qint64)), SIGNAL(currentDurationChanged(qint64)));

    mMusicAnalyst = new MusicAnalyst();
    mMusicAnalyst->setMediaPlayer(mQMediaPlayer);
}

void MusicPlayer::play()
{
    mQMediaPlayer->play();
}

void MusicPlayer::play(int index)
{
    if (mList->media(index) != NULL)
    {
//        mQMediaPlayer->stop();
        mList->setCurrentIndex(index);
        mQMediaPlayer->play();
    }
}

void MusicPlayer::pause()
{
    mQMediaPlayer->pause();
}

void MusicPlayer::stop()
{
    mQMediaPlayer->stop();
}

void MusicPlayer::next()
{
    mList->next();
}

void MusicPlayer::previous()
{
    mList->previous();
}

void MusicPlayer::seek(qint64 pos)
{
    mQMediaPlayer->setPosition(pos);
}

bool MusicPlayer::isSeekable()
{
    return mQMediaPlayer->isSeekable();
}

void MusicPlayer::changePlaybackMode(QMediaPlaylist::PlaybackMode mode)
{
    mList->setPlaybackMode(mode);
}

void MusicPlayer::changePlaybackMode()
{
    switch (mList->playbackMode()) {
    case MusicPlayer::CurrentItemInLoop:
        changePlaybackMode(QMediaPlaylist::Loop);
        break;
    case MusicPlayer::Loop:
        changePlaybackMode(QMediaPlaylist::Random);
        break;
    case MusicPlayer::Random:
        changePlaybackMode(QMediaPlaylist::CurrentItemInLoop);
        break;
    default:
        break;
    }
}

QMediaPlaylist::PlaybackMode MusicPlayer::mode()
{
    return mList->playbackMode();
}

void MusicPlayer::add(QList<QUrl> filePath)
{
    for (int i = 0; i < filePath.length(); i++)
    {
        mList->addMedia(filePath.at(i));
    }
}

void MusicPlayer::remove(int index)
{
    mList->removeMedia(index);
    qDebug("remove %d", index);
}

int MusicPlayer::currentIndex() const
{
    return mList->currentIndex();
}

qint64 MusicPlayer::currentPosition() const
{
    return mQMediaPlayer->position();
}

qint64 MusicPlayer::currentDuration() const
{
    return mQMediaPlayer->duration();
}

QMediaPlayer::State MusicPlayer::state()
{
    return mQMediaPlayer->state();
}

QMediaPlayer::MediaStatus MusicPlayer::status()
{
    return mQMediaPlayer->mediaStatus();
}

QMediaPlayer::Error MusicPlayer::error()
{
    return mQMediaPlayer->error();
}

MusicPlayer* MusicPlayer::getInstance()
{
    if (!mMusicPlayer) {
        mMusicPlayer = new MusicPlayer();
    }
    return mMusicPlayer;
}
