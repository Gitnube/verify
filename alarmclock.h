#ifndef ALARMCLOCK_H
#define ALARMCLOCK_H

#include "QString"
#include "QTime"
#include "QMediaPlayer"
#include "QDir"
#include "QTimer"
#include "QMediaPlaylist"

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
    /*!
    Возвращает состояние воспроизведения мелодии (проигрывается, остановлено, приостановлено)
    \return состояние воспроизведения
    */
    QMediaPlayer::State getPlayingState() const;
    /*!
      Включает будильник, настраивает таймеры на воспроизведение заданной мелодии в заданное время
      с указанной продолжительностью
    */
    void launch();
    void setPlayingDuration(int secs);
private:
    QString soundFileName;
    QTime alarmTime;
    QMediaPlayer player;
    int duration;
};

#endif // ALARMCLOCK_H
