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
    /*!
    Устанавливает время запуска мелодии будильника
    \param time время запуска мелодии
    */
    void setTime(QTime time);
    /*!
    Возвращает время запуска мелодии будильника
    \return время запуска мелодии
    */
    QTime getTime();
private:
    QString soundFileName;
    bool timeType;
};

#endif // ALARMCLOCK_H
