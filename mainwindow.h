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

private slots:

    void on_timeTE_userTimeChanged(const QTime &time);

    void on_soundFileNameSelect_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    AlarmClock alarm;
};

#endif // MAINWINDOW_H
