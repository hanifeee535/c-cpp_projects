// mainwindow.cpp
#include "mainwindow.hh"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Set background colors for widgets
    ui->lcdNumberSec->setStyleSheet("background-color: lightblue;");
    ui->lcdNumberMin->setStyleSheet("background-color: lightgreen;");
    ui->startButton->setStyleSheet("background-color: lightgray;");
    ui->stopButton->setStyleSheet("background-color: lightgray;");
    ui->resetButton->setStyleSheet("background-color: lightgray;");
    ui->closeButton->setStyleSheet("background-color: lightgray;");

    // Initialize minutes and seconds
    minutes = 0;
    seconds = 0;

    // Create and connect timer
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateTime);

    // Connect button clicks to slots
    connect(ui->startButton, &QPushButton::clicked, this, &MainWindow::startTimer);
    connect(ui->stopButton, &QPushButton::clicked, this, &MainWindow::stopTimer);
    connect(ui->resetButton, &QPushButton::clicked, this, &MainWindow::resetTimer);
    connect(ui->closeButton, &QPushButton::clicked, this, &MainWindow::close);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateTime()
{
    // Increment seconds and update LCD numbers
    seconds++;
    if (seconds == 60) {
        minutes++;
        seconds = 0;
    }
    ui->lcdNumberSec->display(seconds);
    ui->lcdNumberMin->display(minutes);
}

void MainWindow::startTimer()
{
    if (!timer->isActive()) {
        timer->start(1000); // Start timer with interval of 1 second
    }
}

void MainWindow::stopTimer()
{
    if (timer->isActive()) {
        getTimer()->stop();
    }
}

void MainWindow::resetTimer()
{
    stopTimer();
    minutes = 0;
    seconds = 0;
    ui->lcdNumberSec->display(seconds);
    ui->lcdNumberMin->display(minutes);
}

QTimer* MainWindow::getTimer() const {
    return timer;
}
