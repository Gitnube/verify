#include "alarmclock_test.h"
#include "alarmclock.h"

AlarmClock_test::AlarmClock_test(QObject *parent) : QObject(parent)
{

}

void AlarmClock_test::alarmClockExisting()
{
    AlarmClock *ac = new AlarmClock();
    QVERIFY(ac != nullptr);
}

void AlarmClock_test::setSoundFileNameAlarmTest()
{
    QString fileName = "alarm.mp3";
    QString res;
    AlarmClock *ac = new AlarmClock();
    ac->setSoundFileName(fileName);
    res = ac->getSoundFileName();
    QCOMPARE(res,fileName);
}

void AlarmClock_test::setSoundFileNameAlarm2Test()
{
    QString fileName = "other_alarm.mp3";
    QString res;
    AlarmClock *ac = new AlarmClock();
    ac->setSoundFileName(fileName);
    res = ac->getSoundFileName();
    QCOMPARE(res,fileName);
}

void AlarmClock_test::setTime0Test()
{
    QTime time = QTime(0,0);
    QTime res;
    AlarmClock *ac = new AlarmClock();
    ac->setTime(time);
    res = ac->getTime();
    QCOMPARE(res,time);
}

void AlarmClock_test::setTime7_30Test()
{
    QTime time = QTime(7,30);
    QTime res;
    AlarmClock *ac = new AlarmClock();
    ac->setTime(time);
    res = ac->getTime();
    QCOMPARE(res,time);
}

void AlarmClock_test::setSoundFileNameAlarm3Test()
{
    QString fileName;
    QString res;
    fileName = "alarmalarm.mp3";
    AlarmClock *ac = new AlarmClock();
    ac->setSoundFileName(fileName);
    res = ac->getSoundFileName();
    QCOMPARE(res,fileName);
}

void AlarmClock_test::setSoundFileNameAlarmMp4Test()
{
    QString fileName, oldFileName;
    QString res;
    fileName = "alarm.mp4";
    AlarmClock *ac = new AlarmClock();
    oldFileName = ac->getSoundFileName();
    ac->setSoundFileName(fileName);
    res = ac->getSoundFileName();
    QCOMPARE(res,oldFileName);
}

void AlarmClock_test::setSoundFileNameOtherAlarmMp4Test()
{
    QString fileName, oldFileName;
    QString res;
    fileName = "other_alarm.mp4";
    AlarmClock *ac = new AlarmClock();
    oldFileName = ac->getSoundFileName();
    ac->setSoundFileName(fileName);
    res = ac->getSoundFileName();
    QCOMPARE(res,oldFileName);
}

void AlarmClock_test::repeatSetSoundFileNameOtherAlarmMp4Test()
{
    QString fileName, oldFileName;
    QString res;
    AlarmClock *ac = new AlarmClock();
    fileName = "alarm.mp3";
    ac->setSoundFileName(fileName);
    oldFileName = ac->getSoundFileName();
    fileName = "other_alarm.mp4";
    ac->setSoundFileName(fileName);
    res = ac->getSoundFileName();
    QCOMPARE(res,oldFileName);
}

void AlarmClock_test::setSoundFileNameAlarmGifTest()
{
    QString fileName, oldFileName;
    QString res;
    AlarmClock *ac = new AlarmClock();
    fileName = "alarm.mp3";
    ac->setSoundFileName(fileName);
    oldFileName = ac->getSoundFileName();
    fileName = "alarm.gif";
    ac->setSoundFileName(fileName);
    res = ac->getSoundFileName();
    QCOMPARE(res,oldFileName);
}

void AlarmClock_test::setSoundFileNameOtherAlarmGifTest()
{
    QString fileName, oldFileName;
    QString res;
    AlarmClock *ac = new AlarmClock();
    fileName = "alarm.mp3";
    ac->setSoundFileName(fileName);
    oldFileName = ac->getSoundFileName();
    fileName = "other_alarm.gif";
    ac->setSoundFileName(fileName);
    res = ac->getSoundFileName();
    QCOMPARE(res,oldFileName);
}

void AlarmClock_test::setTime12Test()
{
    QTime time = QTime(12,00);
    QTime res;
    AlarmClock *ac = new AlarmClock();
    ac->setTime(time);
    res = ac->getTime();
    QCOMPARE(res,time);
}

void AlarmClock_test::getPlayingStateTest()
{
    AlarmClock *ac = new AlarmClock();
    QCOMPARE(ac->getPlayingState(),QMediaPlayer::StoppedState);
}

void AlarmClock_test::getPlayingStateActiveAlarmTest()
{
    AlarmClock *ac = new AlarmClock();
    ac->setTime(QTime::currentTime().addSecs(1));
    ac->setSoundFileName("alarm.mp3");
    ac->launch();
    QTRY_COMPARE_WITH_TIMEOUT(ac->getPlayingState(),QMediaPlayer::PlayingState,2000);
}

void AlarmClock_test::getPlayingStateWithoutTimeout()
{
    AlarmClock *ac = new AlarmClock();
    ac->setTime(QTime::currentTime().addSecs(1));
    ac->setSoundFileName("alarm.mp3");
    ac->launch();
    QCOMPARE(ac->getPlayingState(),QMediaPlayer::StoppedState);
}

void AlarmClock_test::getPlayingStateDuring1SecTest()
{
    QTime time;
    time = QTime::currentTime().addSecs(1);
    AlarmClock *ac = new AlarmClock();
    ac->setTime(time);
    ac->setSoundFileName("alarm.mp3");
    ac->launch();
    QTest::qWait(QTime::currentTime().msecsTo(time)-5);
    QCOMPARE(ac->getPlayingState(),QMediaPlayer::StoppedState);
}

void AlarmClock_test::getPlayingStateDuring1_5SecTest()
{
    QTime time;
    time = QTime::currentTime().addMSecs(1500);
    AlarmClock *ac = new AlarmClock();
    ac->setTime(time);
    ac->setSoundFileName("alarm.mp3");
    ac->launch();
    QTest::qWait(QTime::currentTime().msecsTo(time)-5);
    QCOMPARE(ac->getPlayingState(),QMediaPlayer::StoppedState);
}

void AlarmClock_test::getPlayingStateDuring1_6SecTest()
{
    QTime time;
    time = QTime::currentTime().addMSecs(1600);
    AlarmClock *ac = new AlarmClock();
    ac->setTime(time);
    ac->setSoundFileName("alarm.mp3");
    ac->launch();
    QTest::qWait(QTime::currentTime().msecsTo(time)-5);
    QCOMPARE(ac->getPlayingState(),QMediaPlayer::StoppedState);
}

void AlarmClock_test::setPlayingDuration1SecTest()
{
    QTime time;
    time = QTime::currentTime().addMSecs(1000);
    AlarmClock *ac = new AlarmClock();
    ac->setTime(time);
    ac->setSoundFileName("alarm1.mp3");
    ac->setPlayingDuration(1);
    ac->launch();
    QTest::qWait(QTime::currentTime().msecsTo(time)+1005);
    QCOMPARE(ac->getPlayingState(),QMediaPlayer::StoppedState);
}

QTEST_MAIN(AlarmClock_test)
