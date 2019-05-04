#ifndef ALARMCLOCK_H
#define ALARMCLOCK_H

#include "QString"

class AlarmClock
{
public:
    AlarmClock();
    void setSoundFileName(QString fileName);
    QString getSoundFileName();
};

#endif // ALARMCLOCK_H
