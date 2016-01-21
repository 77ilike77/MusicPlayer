#include "musicanalyst.h"
#include <QDebug>

MusicAnalyst::MusicAnalyst(QObject *parent) : QObject(parent)
{

}

void MusicAnalyst::setMediaPlayer(QMediaPlayer *player)
{
    _mQMediaPlayer = player;
    _mQAudioProbe = new QAudioProbe();
    _mQAudioProbe->setSource(_mQMediaPlayer);

    connect(_mQAudioProbe, SIGNAL(audioBufferProbed(QAudioBuffer)),
            this, SLOT(audioBufferProbed(QAudioBuffer)));
}

void MusicAnalyst::audioBufferProbed(QAudioBuffer buffer)
{
    if(buffer.format().sampleType() == QAudioFormat::SignedInt){
        QAudioBuffer::S16S *data = buffer.data<QAudioBuffer::S16S>();
        QString s = "";
        for (int i = 0; i < buffer.frameCount(); i++)
        {
            if (i % 50 == 0)
            {
                s += "  " + QString::number(data[i].left);
            }
        }
        qDebug() << s;
    }

    // audio is unsigned int
    else if(buffer.format().sampleType() == QAudioFormat::UnSignedInt){
        QAudioBuffer::S16U *data = buffer.data<QAudioBuffer::S16U>();

    }

    // audio is float type
    else if(buffer.format().sampleType() == QAudioFormat::Float){
        QAudioBuffer::S32F *data = buffer.data<QAudioBuffer::S32F>();
    }
}
