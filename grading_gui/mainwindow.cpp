// mainwindow.cpp

#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Connect signals and slots
    connect(ui->calculatePushButton, SIGNAL(clicked()), this, SLOT(calculateGrade()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::calculateGrade()
{
    // Read input values from spin boxes
    unsigned int n = ui->spinBox->value();
    unsigned int g = ui->spinBox_2->value();
    unsigned int p = ui->spinBox_3->value(); // Use spinBox_3 for P points
    unsigned int e = ui->spinBox_4->value(); // Use spinBox_4 for Exam grade

    // Calculate total grade
    unsigned int totalGrade = calculate_total_grade(n, g, p, e);

    // Format results
    QString result = "W-Score: " + QString::number(score_from_weekly_exercises(n, g)) + "\n";
    result += "P-Score: " + QString::number(score_from_projects(p)) + "\n";
    result += "Total Grade: " + QString::number(totalGrade);

    // Display results in text browser
    ui->textBrowser->setText(result);
}


