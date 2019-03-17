#include "mainwindow.h"
#include <QApplication>
#include <QTextCodec>

int main(int argc, char *argv[])
{
   // Q_INIT_RESOURCE(resources);

   /*     QStringList paths = QCoreApplication::libraryPaths();
        paths.append(".");
        paths.append("imageformats");
        paths.append("platforms");*/
    QTextCodec *codec = QTextCodec::codecForName("CP1251");
    QTextCodec::setCodecForLocale(codec);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
