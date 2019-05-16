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

QTEST_MAIN(AlarmClock_test)
