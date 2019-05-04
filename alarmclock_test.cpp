#include "alarmclock_test.h"
#include "alarmclock.h"

AlarmClock_test::AlarmClock_test(QObject *parent) : QObject(parent)
{

}

void AlarmClock_test::AlarmClockExisting()
{
    AlarmClock *ac = new AlarmClock();
    QVERIFY(ac != nullptr);
}

QTEST_MAIN(AlarmClock_test)
