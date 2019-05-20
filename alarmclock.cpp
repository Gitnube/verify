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
    QTimer timer;
    player.setMedia(QUrl::fromLocalFile(QDir::currentPath() + "/alarm.mp3"));
    timer.singleShot(1000,&player,SLOT(play()));
}
