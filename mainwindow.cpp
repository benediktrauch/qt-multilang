#include "mainwindow.h"
#include "ui_mainwindow.h"

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


    ui->setupUi(this);

    QIcon icon_1(":/icons/icon_1_de_DE.png");
    ui->comboBox->addItem(icon_1, "Deutsch", QVariant("de_DE"));

    QIcon icon_2(":/icons/icon_1_en_US.png");
    ui->comboBox->addItem(icon_2, "English", QVariant("en_US"));

    QIcon icon_3(":/icons/icon_1_ch_CN.png");
    ui->comboBox->addItem(icon_3, "Chinese", QVariant("ch_CN"));

    QIcon icon_4(":/icons/icon_1_ar_SA.png");
    ui->comboBox->addItem(icon_4, "Arabisch", QVariant("ar_SA"));
}

MainWindow::~MainWindow()
{
    delete ui;

}
