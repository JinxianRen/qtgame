#include "audiothread.h"
#include "config.h"
#include <QUrl>

AudioThread::AudioThread(QObject *parent):
    QObject(parent)
{
    effect.moveToThread(&thread);
    connect(this, SIGNAL(doPlay()), &effect, SLOT(play()));
    thread.start();
}

AudioThread::~AudioThread()
{
    if(thread.isRunning())
    {
       thread.terminate();
    }
}

void AudioThread::play(int i)
{
        if(i==1)
            effect.setSource(QUrl(GOLD_BGM));
        else if(i==2)
            effect.setSource(QUrl(HURT_BGM));
        else if(i==3)
            effect.setSource(QUrl(BUY_BGM));
        else if(i==4)
            effect.setSource(QUrl(WIN_BGM));
        effect.setLoopCount(1);
        effect.setVolume(0.25f);
        emit this->doPlay();

}

