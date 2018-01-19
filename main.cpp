#include "mainwindow.h"
#include <QApplication>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;

    translator.load("translation_ar_SA");
    translator.load("translation_de_DE");
    translator.load("translation_en_US");
    translator.load("translation_ch_CN");

    a.installTranslator(&translator);

    MainWindow w;
    w.show();

    return a.exec();
}
