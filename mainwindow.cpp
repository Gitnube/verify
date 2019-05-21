#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFileDialog"

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

void MainWindow::on_timeTE_userTimeChanged(const QTime &time)
{
    alarm.setTime(time);
}

void MainWindow::on_soundFileNameSelect_clicked()
{
    QString fileName;
    fileName = QFileDialog::getOpenFileName(
                this,
                "Выберите мелодию будильника...",
                QDir::currentPath(),
                tr("Mp3 Files (*.mp3)")
                );
    alarm.setSoundFileName(fileName);
    ui->soundFileNameValue->setText(fileName);
}

void MainWindow::on_pushButton_clicked()
{
    alarm.launch();
}
