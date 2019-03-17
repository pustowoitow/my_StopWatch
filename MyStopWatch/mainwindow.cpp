#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow),
    mRunning(false), mStartTime(), zero('0'), ms_all(0), ms_saved(0)

{
    ui->setupUi(this);
    connect(ui->StartStopButton, SIGNAL(clicked()), SLOT(start_stop()));
    connect(ui->ResetButton, SIGNAL(clicked()), SLOT(reset()));
    connect(ui->SetFileButton, SIGNAL(clicked()), SLOT(set_file()));

    startTimer(0);
}

void MainWindow::start_stop(void)
{
    if(mRunning==false)
    {
        mStartTime=QTime::currentTime();
        mRunning = true;
        ui->StartStopButton->setText("Стоп");
        ui->ResetButton->setEnabled(false);
    }
    else
    {
        mRunning = false;
        ui->StartStopButton->setText("Старт");
        ui->ResetButton->setEnabled(true);
    }
}

void MainWindow::reset(void)
{
     ms_saved=0;
     ms_all=0;
     ui->MainLabel->setText("00:00:000");
}

void MainWindow::set_file(void)
{
   QString str = QFileDialog::getOpenFileName(0, "Directory Dialog", QDir::currentPath());
   ui->FilePath->setText(str);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_SaveButton_clicked()
{
    if(ui->FilePath->text().isEmpty()) QMessageBox::information(this, "Info", "Выберите файл для сохранения результата!");
    else
    {
        QFile mFile(ui->FilePath->text());
        if (!mFile.open(QFile::WriteOnly | QFile::Text |QFile::Append))
        {
               QMessageBox::information(this, "Error", "Путь неверен!");
                return;
        }
        QTextStream stream(&mFile);
        stream<<ui->MainLabel->text()<<"\n";
        mFile.close();
        if (stream.status() != QTextStream::Ok)
            {
                QMessageBox::information(this, "Error", "Ошибка записи файла!");
            }
        else
            QMessageBox::information(this, "Success", "Успешно!");
    }
}
