#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QLocale>
#include <QBoxLayout>
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

    QLocale currentLocale() const;
    void setCurrentLocale(const QLocale &currentLocale);
    void retranslate();


protected:

    QLocale m_currentLocale;
    QTranslator m_currentTranslate;



private slots:
    void on_comboBox_currentIndexChanged(int index);


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
