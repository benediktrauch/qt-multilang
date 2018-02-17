#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QDebug>

// If translation is not working, you might forgott to copy language files into build folder

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // Initial installation of translator
    m_currentTranslate.load("translation_de_DE");
    QApplication::installTranslator(&m_currentTranslate);

    // Setting initial numbers

    this->setEnteredText("...");
    this->setFloatNumber(0.0);
    this->setIntNumber(0);
    ui->setupUi(this);

    this->setDate(ui->calendarWidget->selectedDate().toString(Qt::DefaultLocaleLongDate));

    this->setCurrentLocale(QLocale::German);
    QLocale::setDefault(QLocale::German);

    // Adding countries to combobox and menu bar

    // Deutschland
    QIcon icon_1(":/icons/icon_1_de_DE.png");
    ui->comboBox->addItem(icon_1, "Deutsch", QVariant("de_DE"));

    action_DE = new QAction(tr("Deutsch | Deutschland"), this);
    action_DE->setIcon(icon_1);
    ui->menuSprache->addAction(action_DE);

    // USA
    QIcon icon_2(":/icons/icon_1_en_US.png");
    ui->comboBox->addItem(icon_2, "English | USA", QVariant("en_US"));

    action_US = new QAction(tr("English | USA"), this);
    action_US->setIcon(icon_2);
    ui->menuSprache->addAction(action_US);

    // China
    QIcon icon_3(":/icons/icon_1_ch_CN.png");
    ui->comboBox->addItem(icon_3, "中国 | 中华人民共和国", QVariant("zh_CN"));

    action_CN = new QAction(tr("中国 | 中华人民共和国"), this);
    action_CN->setIcon(icon_3);
    ui->menuSprache->addAction(action_CN);

    // Saudi-Arabien
    QIcon icon_4(":/icons/icon_1_ar_SA.png");
    ui->comboBox->addItem(icon_4, "العربية | المملكة العربية السعودية", QVariant("ar_SA"));

    action_AR = new QAction(tr("العربية | المملكة العربية السعودية"), this);
    action_AR->setIcon(icon_4);
    ui->menuSprache->addAction(action_AR);


    // Retranslate to make sure everything is correctly translated
    ui->retranslateUi(this);
    QApplication::setLayoutDirection(m_currentLocale.textDirection());
    ui->doubleSpinBox->setLocale(m_currentLocale);
    retranslate();

    // Connection for menubar countries
    connect(action_DE, SIGNAL(triggered()), this, SLOT(on_de_selected()));
    connect(action_US, SIGNAL(triggered()), this, SLOT(on_us_selected()));
    connect(action_CN, SIGNAL(triggered()), this, SLOT(on_cn_selected()));
    connect(action_AR, SIGNAL(triggered()), this, SLOT(on_ar_selected()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::retranslate()
{
    ui->date_label->setText(tr("Gewähltes Datum: ") + ui->calendarWidget->selectedDate().toString(Qt::DefaultLocaleLongDate));

    ui->number_input_text->setText(tr("Du hast %1 Liter %2 getrunken.").arg(m_currentLocale.toString(floatNumber()), enteredText()));

    ui->slider_label->setText(tr("In meinem Haus wohnt %Ln Mensch(en).", "", this->intNumber()));

    ui->image_label->setStyleSheet("image: url(:/images/bread_ar.jpg);");

    if (m_currentLocale == QLocale::English)
    {
        ui->image_label->setStyleSheet("image: url(:/images/bread_us.jpg);");
    } else if (m_currentLocale == QLocale::German)
    {
        ui->image_label->setStyleSheet("image: url(:/images/bread_de.jpg);");
    } else if (m_currentLocale == QLocale::Chinese)
    {
        ui->image_label->setStyleSheet("image: url(:/images/bread_ch.jpg);");
    }

    ui->doubleSpinBox->setLocale(m_currentLocale);
    ui->lineEdit->setLayoutDirection(m_currentLocale.textDirection());
    ui->calendarWidget->setLocale(m_currentLocale);
    //ui->retranslateUi(this);
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
    retranslate();
    this->setDate(date.toString(Qt::DefaultLocaleLongDate));
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

void MainWindow::on_de_selected()
{
    QApplication::removeTranslator(&m_currentTranslate);

    m_currentTranslate.load("translation_de_DE");
    QApplication::installTranslator(&m_currentTranslate);

    this->setCurrentLocale(QLocale("de_DE"));
    QLocale::setDefault(m_currentLocale);

    ui->retranslateUi(this);

    QApplication::setLayoutDirection(m_currentLocale.textDirection());

    ui->comboBox->setCurrentIndex(0);
    retranslate();
}

void MainWindow::on_us_selected()
{
    QApplication::removeTranslator(&m_currentTranslate);

    m_currentTranslate.load("translation_en_US");
    QApplication::installTranslator(&m_currentTranslate);

    this->setCurrentLocale(QLocale("en_US"));
    QLocale::setDefault(m_currentLocale);

    ui->retranslateUi(this);

    QApplication::setLayoutDirection(m_currentLocale.textDirection());

    ui->comboBox->setCurrentIndex(1);
    retranslate();
}

void MainWindow::on_cn_selected()
{
    QApplication::removeTranslator(&m_currentTranslate);

    m_currentTranslate.load("translation_zh_CN");
    QApplication::installTranslator(&m_currentTranslate);

    this->setCurrentLocale(QLocale("zh_CN"));
    QLocale::setDefault(m_currentLocale);

    ui->retranslateUi(this);

    QApplication::setLayoutDirection(m_currentLocale.textDirection());

    ui->comboBox->setCurrentIndex(2);
    retranslate();
}


void MainWindow::on_ar_selected()
{
    QApplication::removeTranslator(&m_currentTranslate);

    m_currentTranslate.load("translation_ar_SA");
    QApplication::installTranslator(&m_currentTranslate);

    this->setCurrentLocale(QLocale("ar_SA"));
    QLocale::setDefault(m_currentLocale);

    ui->retranslateUi(this);

    QApplication::setLayoutDirection(m_currentLocale.textDirection());

    ui->comboBox->setCurrentIndex(3);
    retranslate();
}
