#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "alarmclock.h"

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void updateInfoLabel();

private slots:
    void on_soundFileNameLE_textChanged(const QString &arg1);

    void on_timeTE_userTimeChanged(const QTime &time);

private:
    Ui::MainWindow *ui;
    AlarmClock alarm;
};

#endif // MAINWINDOW_H
