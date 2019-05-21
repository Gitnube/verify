#include "alarmclock.h"

AlarmClock::AlarmClock()
{
    duration = -1;
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
    QTimer timer,timerStop;
    QMediaPlaylist *playlist;
    playlist = new QMediaPlaylist();
    playlist->addMedia(QUrl::fromLocalFile(soundFileName));
    player.setPlaylist(playlist);
    timer.singleShot(QTime::currentTime().msecsTo(alarmTime),&player,SLOT(play()));
    if(duration != -1)
    {
        playlist->setPlaybackMode(QMediaPlaylist::Loop);
        timerStop.singleShot(QTime::currentTime().msecsTo(alarmTime.addSecs(duration)),&player,SLOT(stop()));
    }
}

void AlarmClock::setPlayingDuration(int secs)
{
    duration = secs;
}
