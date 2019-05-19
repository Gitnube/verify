#ifndef ALARMCLOCK_H
#define ALARMCLOCK_H

#include "QString"
#include "QTime"
#include "QMediaPlayer"

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
    QMediaPlayer::State getPlayingState();
private:
    QString soundFileName;
    QTime alarmTime;
};

#endif // ALARMCLOCK_H
