#include "mainwindow.h"
#include <QApplication>
#include <QTextCodec>

int main(int argc, char *argv[])
{
    QTextCodec *codec = QTextCodec::codecForName("CP1251");
    QTextCodec::setCodecForLocale(codec);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

   // app.connect( &app, SIGNAL( lastWindowClosed() ), &app, SLOT ( quit() ) );
    return a.exec();
}
