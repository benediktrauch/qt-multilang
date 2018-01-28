#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // tr(string); für pluralität
    // ui->label->setText(tr("Ich sehe %n Stern(e), "", value));
    //
    // QLocale ar(QLocale::Arabic);
    // ui->horizontalLayout->setDirection(QBoxLayout::RightToLeft)
    // ui->formLayout->setDirection(QBoxLayout::RightToLeft)
    //
    // iec für Currency

    // QLocale::setDefault(m_currentLocale);
    // items to combobox
    // QIcon icon_1(":/images/icon_1.png");
    // QVariant
    // ui->languageCombo->addItem(icon_1, "Deutsch", QVariant("de_DE"));

    // ui->retranslateUi(this);

    // index itemData(index).toString();

    // translator löschen, dann laden der neuen sprache, neuen translator installieren
    // m_currentLocal und default Local auf neuen letzen

    // ui->translateUi

    // QApplication::setLayoutDirection(m_currentlocal.textDirection())
    // retranslate(); für manuelles aktualisieren der Labels

    // QVariant
    // ui->languageCombo->addItem(icon_1, "Deutsch", QVariant("de_DE"));

    // QLocale::setDefault(m_currentLocale);
    // items to combobox

    // Initial installation of translator
    m_currentTranslate.load("translation_de_DE");
    QApplication::installTranslator(&m_currentTranslate);

    this->setDate(QDateTime::currentDateTimeUtc().toString(Qt::DefaultLocaleShortDate).chopped(6));
    this->setEnteredText("...");
    this->setFloatNumber(0.0);
    this->setIntNumber(0);
    ui->setupUi(this);

    this->setCurrentLocale(QLocale::German);
    QLocale::setDefault(QLocale::German);

    QIcon icon_1(":/icons/icon_1_de_DE.png");
    ui->comboBox->addItem(icon_1, "Deutsch", QVariant("de_DE"));
    ui->menuSprache->addAction(icon_1, "Deutsch");

    QIcon icon_2(":/icons/icon_1_en_US.png");
    ui->comboBox->addItem(icon_2, "English | USA", QVariant("en_US"));
    ui->menuSprache->addAction(icon_2, "English | USA");

    QIcon icon_3(":/icons/icon_1_ch_CN.png");
    ui->comboBox->addItem(icon_3, "中国 | 中华人民共和国", QVariant("zh_CN"));
    ui->menuSprache->addAction(icon_3, "中国 | 中华人民共和国");

    QIcon icon_4(":/icons/icon_1_ar_SA.png");
    ui->comboBox->addItem(icon_4, "العربية | المملكة العربية السعودية", QVariant("ar_SA"));
    ui->menuSprache->addAction(icon_4, "العربية | المملكة العربية السعودية");

    // Retranslate to make sure everything is correctly translated
    ui->retranslateUi(this);
    QApplication::setLayoutDirection(m_currentLocale.textDirection());
    retranslate();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::retranslate()
{
    qDebug() << "retranslate";

    ui->date_label->setText(tr("Gewähltes Datum: ") + this->date());

    ui->number_input_text->setText(tr("Du hast %1 Liter %2 getrunken.").arg(m_currentLocale.toString(floatNumber()), enteredText()));

    ui->slider_label->setText(tr("In meinem Haus wohnt %Ln Mensch(en).", "", this->intNumber()));

    ui->calendarWidget->setLocale(m_currentLocale);
}

QString MainWindow::date() const
{
    return m_date;
}

void MainWindow::setDate(const QString &date)
{
    m_date = date;
}

QString MainWindow::enteredText() const
{
    return m_enteredText;
}

void MainWindow::setEnteredText(const QString &enteredText)
{
    m_enteredText = enteredText;
}

float MainWindow::floatNumber() const
{
    return m_floatNumber;
}

void MainWindow::setFloatNumber(float floatNumber)
{
    m_floatNumber = floatNumber;
}

int MainWindow::intNumber() const
{
    return m_intNumber;
}

void MainWindow::setIntNumber(int intNumber)
{
    m_intNumber = intNumber;
}

QLocale MainWindow::currentLocale() const
{
    return m_currentLocale;
}

void MainWindow::setCurrentLocale(const QLocale &currentLocale)
{
    m_currentLocale = currentLocale;
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    // initialize countryCode variable
    QString countryCode = QLocale::system().name();
    countryCode = ui->comboBox->itemData(index).toString();

    QApplication::removeTranslator(&m_currentTranslate);

    m_currentTranslate.load("translation_" + countryCode);
    QApplication::installTranslator(&m_currentTranslate);

    this->setCurrentLocale(QLocale(countryCode));
    QLocale::setDefault(m_currentLocale);

    ui->retranslateUi(this);

    QApplication::setLayoutDirection(m_currentLocale.textDirection());
    retranslate();
}



void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
       setEnteredText(arg1);
       retranslate();
}

void MainWindow::on_calendarWidget_clicked(const QDate &date)
{
    this->setDate(date.toString(Qt::DefaultLocaleLongDate));
    retranslate();
}

void MainWindow::on_doubleSpinBox_valueChanged(double arg1)
{
    setFloatNumber(arg1);
    retranslate();
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    setIntNumber(value);
    retranslate();
}
