#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QString>
#include <QMainWindow>
#include <QDateTime>
#include <QTime>
#include <QLabel>
#include <QPushButton>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include "ui_mainwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void start_stop(void);

    void reset(void);

    void set_file(void);



protected:
   void timerEvent(QTimerEvent *)
    {
        if(mRunning)
        {
            ms_all = mStartTime.msecsTo(QTime::currentTime())+ms_saved;
            int h = ms_all / 1000 / 60 / 60;
            int m = (ms_all / 1000 / 60) - (h * 60);
            int s = (ms_all / 1000) - (m * 60);
            int ms = ms_all - (s * 1000) - (m * 60000) - (h * 3600000);
            QString diff = QString("%2:%3:%4").
                                arg(m, 2, 10, zero).
                                arg(s, 2, 10, zero).
                                arg(ms, 3, 10, zero);
            ui->MainLabel->setText(diff);
        }
        else
        {
            ms_saved=ms_all;
        }
    }

private slots:
   void on_SaveButton_clicked();

private:
    Ui::MainWindow *ui;
    bool mRunning;
    QTime mStartTime;
    qint64 ms_all;
    qint64 ms_saved;
    const QChar zero;
};

#endif // MAINWINDOW_H
