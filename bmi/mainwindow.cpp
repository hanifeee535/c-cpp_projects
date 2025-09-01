// MainWindow.cpp

#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    weight = 0.0;
    height = 0.0;

    connect(ui->countButton, &QPushButton::clicked, this, &MainWindow::calculateBMI);
    connect(ui->closeButton, &QPushButton::clicked, this, &MainWindow::close);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_weightLineEdit_editingFinished()
{
    weight = ui->weightLineEdit->text().toFloat();
}

void MainWindow::on_heightLineEdit_editingFinished()
{
    height = ui->heightLineEdit->text().toFloat();
}

void MainWindow::on_countButton_clicked()
{
    if (height <= 0 || weight <= 0) {
        ui->resultLabel->setText("Cannot count");
        ui->infoTextBrowser->clear();
    } else {
        float bmi = weight / (height * height);
        displayBMI(bmi);
        displayInfo(bmi);
    }
}

void MainWindow::calculateBMI()
{
    // Calculate BMI
    if (height <= 0 || weight <= 0) {
        ui->resultLabel->setText("Cannot count");
        ui->infoTextBrowser->clear();
    } else {
        float bmi = weight / (height * height);
        displayBMI(bmi);
        displayInfo(bmi);
    }
}

void MainWindow::displayBMI(float bmi)
{
    ui->resultLabel->setText(QString::number(bmi));
}

void MainWindow::displayInfo(float bmi)
{
    QString info;
    if (bmi < 18.5)
        info = "Underweight";
    else if (bmi >= 18.5 && bmi <= 25)
        info = "Normal range";
    else
        info = "Overweight";
    ui->infoTextBrowser->setText(info);
}
