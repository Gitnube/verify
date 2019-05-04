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
};

#endif // ALARMCLOCK_TEST_H
