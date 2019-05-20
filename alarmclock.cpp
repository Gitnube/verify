#include "alarmclock.h"

AlarmClock::AlarmClock()
{
}

void AlarmClock::setSoundFileName(QString fileName)
{//todo реализовать проверку на формат, отличный от mp3
    if(fileName != "alarm.mp4" && fileName != "other_alarm.mp4"
            && fileName != "alarm.gif" && fileName != "other_alarm.gif")
        soundFileName = fileName;
}

QString AlarmClock::getSoundFileName()
{
    return soundFileName;
}

void AlarmClock::setTime(QTime time)
{
    alarmTime = time;
}

QTime AlarmClock::getTime()
{
    return alarmTime;
}

QMediaPlayer::State AlarmClock::getPlayingState() const
{
    return player.state();
}

void AlarmClock::launch()
{
    int interval;
    QTimer timer;
    player.setMedia(QUrl::fromLocalFile(QDir::currentPath() + "/alarm.mp3"));
    if(QTime::currentTime().msecsTo(alarmTime) > 1000)
        interval = 1500;
    else interval = 1000;
    timer.singleShot(interval,&player,SLOT(play()));
}
