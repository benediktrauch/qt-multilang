#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTranslator>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    // QLocale m_currentLocale;
    QTranslator m_currentTranslate;

    void retranslate();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
