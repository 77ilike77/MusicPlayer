#ifndef MUSICANALYST_H
#define MUSICANALYST_H

#include <QAudioProbe>
#include <QMediaPlayer>

class MusicAnalyst : public QObject
{
    Q_OBJECT
public:
    explicit MusicAnalyst(QObject *parent = 0);
    void setMediaPlayer(QMediaPlayer *player);

private:
    QAudioProbe *_mQAudioProbe;
    QMediaPlayer *_mQMediaPlayer;

private slots:
    void audioBufferProbed(QAudioBuffer buffer);
};

#endif // MUSICANALYST_H
