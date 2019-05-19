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

QTEST_MAIN(AlarmClock_test)
