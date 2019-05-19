#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_soundFileNameLE_textChanged(const QString &arg1)
{
    alarm.setSoundFileName(arg1);
    updateInfoLabel();
}

void MainWindow::updateInfoLabel()
{
    ui->alarmInfoLabel->setText(
                "Параметры будильника: мелодия - "
                + alarm.getSoundFileName()
                + ", время - "
                + alarm.getTime().toString()
                );
}

void MainWindow::on_timeTE_userTimeChanged(const QTime &time)
{
    alarm.setTime(time);
    updateInfoLabel();
}
