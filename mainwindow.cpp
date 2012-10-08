/*****************************************************************************
clock-app-with-qtimer, A basic clock timer with QTime and QTimer
Copyright (C) 2012 MD: Minhazul Haque;
mdminhazulhaque@gmail.com.

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*****************************************************************************/

#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer.setInterval(1000);
    connect(&timer, SIGNAL(timeout()), this, SLOT(updateTime()));
    ui->timeEdit->setTime(QTime::currentTime());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateTime()
{
    clock = clock.addSecs(1);
    ui->label->setText(clock.toString("hh:mm:ss"));
}

void MainWindow::on_pushButton_clicked()
{
    timer.stop();
    clock.setHMS(ui->timeEdit->time().hour(), ui->timeEdit->time().minute(), ui->timeEdit->time().second());
    timer.start();
}
