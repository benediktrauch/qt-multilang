#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QLocale>
#include <QBoxLayout>
#include <QTranslator>
#include <QDateTime>
#include <QStringBuilder>

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


    QString date() const;
    void setDate(const QString &date);

    QString enteredText() const;
    void setEnteredText(const QString &enteredText);

    float floatNumber() const;
    void setFloatNumber(float floatNumber);

    int intNumber() const;
    void setIntNumber(int intNumber);

protected:

    QLocale m_currentLocale;
    QTranslator m_currentTranslate;
    QString m_date;
    QString m_enteredText;
    float m_floatNumber;
    int m_intNumber;


private slots:
    void on_comboBox_currentIndexChanged(int index);


    void on_lineEdit_textChanged(const QString &arg1);

    void on_calendarWidget_clicked(const QDate &date);

    void on_doubleSpinBox_valueChanged(double arg1);

    void on_horizontalSlider_valueChanged(int value);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
