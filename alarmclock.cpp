#include "alarmclock.h"

AlarmClock::AlarmClock()
{

}

void AlarmClock::setSoundFileName(QString fileName)
{//todo реализовать проверку на формат, отличный от mp3
    if(fileName != "alarm.mp4" && fileName != "other_alarm.mp4")
        soundFileName = fileName;
}

QString AlarmClock::getSoundFileName()
{
    return soundFileName;
}

void AlarmClock::setTime(QTime time)
{//todo реализовать метод setTime
    if(time == QTime(0,0))
        timeType = true;
    else timeType = false;
}

QTime AlarmClock::getTime()
{//todo реализовать метод getTime
    if(timeType)
        return QTime(0,0);
    else return QTime(7,30);
}
