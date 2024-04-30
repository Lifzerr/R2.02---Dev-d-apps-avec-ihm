#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QObject>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Conexions
    //QObject::connect(ui->_erase, &QPushButton::clicked, this, SLOT(effacer()));
    //QObject::connect(ui->_convert, &QPushButton::clicked, this, SLOT(convertir()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::convertir()
{
    // Variables
    QString writtenText = ui->_valueToConvert->text();
    bool checkConversion;

    // Convertir et vérifier
    float CelciusValue = writtenText.toFloat(&checkConversion);
    if(checkConversion)
    {
        float FahrenheitValue = (CelciusValue * 9.0 / 5.0) + 32.0;
        ui->_result->setText(QString::number(FahrenheitValue));
    }
    /*else
    {
        _errorMessage->exec();
    }*/
}

void MainWindow::effacer()
{
    ui->_valueToConvert->clear();
    ui->_result->setText("---.---");
}
