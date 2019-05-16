#ifndef ALARMCLOCK_H
#define ALARMCLOCK_H

#include "QString"
#include "QTime"

class AlarmClock
{
public:
    AlarmClock();
    /*!
    Устанавливает название файла мелодии будильника
    \param fileName название файла мелодии
    */
    void setSoundFileName(QString fileName);
    /*!
    Возвращает название файла мелодии будильника
    \return название файла мелодии
    */
    QString getSoundFileName();
    void setTime(QTime time);
    QTime getTime();
private:
    bool fileNameType;
};

#endif // ALARMCLOCK_H
