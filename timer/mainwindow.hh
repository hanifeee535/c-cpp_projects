// mainwindow.hh
#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include <QMainWindow>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QTimer* getTimer() const;

private slots:
    void updateTime();
    void startTimer();
    void stopTimer();
    void resetTimer();

private:
    Ui::MainWindow *ui;
    QTimer* timer;
    int minutes;
    int seconds;
};

#endif // MAINWINDOW_HH
