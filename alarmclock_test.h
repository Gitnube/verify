#ifndef ALARMCLOCK_TEST_H
#define ALARMCLOCK_TEST_H

#include <QObject>
#include <QtTest/QtTest>
#include <QTest>

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
    void setSoundFileNameAlarmMp4Test();
    void setSoundFileNameOtherAlarmMp4Test();
    void repeatSetSoundFileNameOtherAlarmMp4Test();
    void setSoundFileNameAlarmGifTest();
    void setSoundFileNameOtherAlarmGifTest();
    void setTime12Test();
    void getPlayingStateTest();
    void getPlayingStateActiveAlarmTest();
    void getPlayingStateWithoutTimeout();
    void getPlayingStateDuring1SecTest();
    void getPlayingStateDuring1_5SecTest();
    void getPlayingStateDuring1_6SecTest();
    void setPlayingDuration1SecTest();
    void setPlayingDuration2SecTest();
};

#endif // ALARMCLOCK_TEST_H
