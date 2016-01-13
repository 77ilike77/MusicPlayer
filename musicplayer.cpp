#include "musicplayer.h"

MusicPlayer* MusicPlayer::mMusicPlayer = NULL;

MusicPlayer::MusicPlayer(QObject *parent) : QObject(parent)
{
    mQMediaPlayer = new QMediaPlayer();
    mQMediaPlayer->setVolume(100);

    mList = new QMediaPlaylist();
    mList->setPlaybackMode(QMediaPlaylist::Loop);
    mQMediaPlayer->setPlaylist(mList);

    playlistModel = new PlayListModel(this);
    playlistModel->setPlaylist(mList);


    connect(mQMediaPlayer, SIGNAL(stateChanged(QMediaPlayer::State)), SIGNAL(stateChanged()));
    connect(mQMediaPlayer, SIGNAL(mediaStatusChanged(QMediaPlayer::MediaStatus)), SIGNAL(statusChanged()));
    connect(mQMediaPlayer, SIGNAL(error(QMediaPlayer::Error)), SIGNAL(errorChanged()));
}

void MusicPlayer::play()
{
    mQMediaPlayer->play();
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

void MusicPlayer::add(QList<QUrl> filePath)
{
    for (int i = 0; i < filePath.length(); i++)
    {
        mList->addMedia(filePath.at(i));
    }
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
