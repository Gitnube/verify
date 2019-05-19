#include "alarmclock.h"

AlarmClock::AlarmClock()
{
    isActive = false;
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

QMediaPlayer::State AlarmClock::getPlayingState()
{//todo реализовать getPlayingState
    if(isActive)
        return QMediaPlayer::PlayingState;
    else return QMediaPlayer::StoppedState;
}

void AlarmClock::launch()
{
    isActive = true;
}
