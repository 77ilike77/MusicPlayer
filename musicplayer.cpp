#include "musicplayer.h"

MusicPlayer* MusicPlayer::mMusicPlayer = NULL;

MusicPlayer::MusicPlayer(QWidget *parent) : QMainWindow(parent)
{
    setWindowTitle("Music Player");
    mQMediaPlayer = new QMediaPlayer();
    mQMediaPlayer->setMedia(QUrl("file:///home/jinpei/QT/QtProject/MusicPlayer/Sleep Away.mp3"));
    mQMediaPlayer->setVolume(80);
}


void MusicPlayer::play()
{
    mQMediaPlayer->play();
}

void MusicPlayer::pause()
{
    if (mQMediaPlayer->state() == QMediaPlayer::PlayingState) {
        mQMediaPlayer->pause();
    }
}

QMediaPlayer::State MusicPlayer::state()
{
    return mQMediaPlayer->state();
}

MusicPlayer* MusicPlayer::getInstance()
{
    if (!mMusicPlayer) {
        mMusicPlayer = new MusicPlayer();
    }
    return mMusicPlayer;
}
