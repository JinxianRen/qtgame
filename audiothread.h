#ifndef AUDIOTHREAD_H
#define AUDIOTHREAD_H

#include <QtCore>
#include <QObject>

#include <QSoundEffect>
#include <QThread>

class AudioThread: public QObject
{
    Q_OBJECT

public:
    AudioThread(QObject *parent = nullptr);
    ~AudioThread();

    signals:
        void doPlay();

    public slots:
        void play(int i);

    private:
        QSoundEffect effect;
        QThread thread;

};

#endif // AUDIOTHREAD_H
