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
{//todo воспроизводить выбранную мелодию
    QTimer timer,timerStop;
    player.setMedia(QUrl::fromLocalFile(QDir::currentPath() + "/alarm.mp3"));
    timer.singleShot(QTime::currentTime().msecsTo(alarmTime),&player,SLOT(play()));
    if((soundFileName == "alarm1.mp3" || soundFileName == "alarm2.mp3") && fDuration)
        timerStop.singleShot(1000,&player,SLOT(stop()));
}

void AlarmClock::setPlayingDuration(int secs)
{
    if(secs == 1)
        fDuration = true;
    else fDuration = false;
}
