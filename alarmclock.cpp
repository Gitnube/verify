#include "alarmclock.h"

AlarmClock::AlarmClock()
{

}

void AlarmClock::setSoundFileName(QString fileName)
{//todo реализовать метод setSoundFileName
    if(fileName == "alarm.mp3")
        fileNameType = true;
    else fileNameType = false;
}

QString AlarmClock::getSoundFileName()
{//todo реализовать метод getSoundFileName
    if(fileNameType)
        return "alarm.mp3";
    else return "other_alarm.mp3";
}
