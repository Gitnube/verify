#ifndef ALARMCLOCK_TEST_H
#define ALARMCLOCK_TEST_H

#include <QObject>
#include <QtTest/QtTest>

class AlarmClock_test : public QObject
{
    Q_OBJECT
public:
    explicit AlarmClock_test(QObject *parent = nullptr);

signals:

private slots:
    void alarmClockExisting();
    void setSoundFileNameAlarmTest();
    void setSoundFileNameAlarm2Test();
    void setTime0Test();
    void setTime7_30Test();
    void setSoundFileNameAlarm3Test();
};

#endif // ALARMCLOCK_TEST_H
