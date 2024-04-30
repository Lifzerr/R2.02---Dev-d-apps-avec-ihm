#include "convertisseurtemp.h"
#include <QObject>
#include <QLayout>
#include <QCoreApplication>
#include <QAction>

ConvertisseurTemp::ConvertisseurTemp(QWidget *parent)
    : QWidget(parent)
{
    // Fenêtre
    setWindowTitle(QString("Convertisseur de températures"));

    // Boutons
    _leave = new QPushButton(tr("&Quitter"),this);
    _erase = new QPushButton(tr("&Effacer"), this);
    _convert = new QPushButton(tr("&Convertir"), this);

    // Textes
    _mainTitle = new QLabel(this);
    _mainTitle->setFont(QFont("Arial", 14, QFont::Bold));
    _mainTitle->setText(QString("Convertisseur de températures"));
    _mainTitle->setAlignment(Qt::AlignLeft);

    _titleDeg = new QLabel(this);
    _titleDeg->setText(QString("&degrés Celcius"));
    _titleDeg->setBuddy(_valueToConvert);

    _titleFaren = new QLabel(this);
    _titleFaren->setText(QString("degrés Fahrenheit"));

    _resultFaren = new QLabel(this);
    _resultFaren->setText(QString("---.---"));
    _resultFaren->setFont(QFont("Arial",11));

    // Boite de saisie
    _valueToConvert = new QLineEdit(/*tr("&*.*"),*/this);
    _titleDeg->setBuddy(_valueToConvert);

    // Message d'erreur
    _errorMessage = new QMessageBox(this);
    _errorMessage->setText(QString("Test mv"));

    // Layouts
    QHBoxLayout* titleBox;
    QGridLayout* centralBox;
    QHBoxLayout* buttonBox;
    QHBoxLayout* leaveBox;
    QVBoxLayout* mainPanel;
    QHBoxLayout* fullWindow;

    // Panel central
    titleBox = new QHBoxLayout;
    titleBox->addWidget(_mainTitle);

    centralBox = new QGridLayout;
    centralBox->addWidget(_titleDeg, 0, 0);
    centralBox->addWidget(_titleFaren, 0, 1);
    centralBox->addWidget(_valueToConvert, 1, 0);
    centralBox->addWidget(_resultFaren, 1, 1);

    leaveBox = new QHBoxLayout;
    leaveBox->addWidget(_leave);
    buttonBox = new QHBoxLayout;
    buttonBox->addWidget(_erase);
    buttonBox->addWidget(_convert);
    buttonBox->addStretch(1);
    buttonBox->addLayout(leaveBox);

    mainPanel = new QVBoxLayout;
    mainPanel->addLayout(titleBox);
    mainPanel->addStretch(1);
    mainPanel->addLayout(centralBox);
    mainPanel->addStretch(5);
    mainPanel->addLayout(buttonBox);

    fullWindow = new QHBoxLayout(this);
    fullWindow->addStretch();
    fullWindow->addLayout(mainPanel);
    fullWindow->addStretch();

    // Associer le layout à la fenêtre
    setLayout(fullWindow);

    // Définir l'ordre de tabulation
    setTabOrder(_valueToConvert, _erase);
    setTabOrder(_erase, _convert);
    setTabOrder(_convert, _leave);

    // Connections des boutons
    QObject::connect(_leave, SIGNAL(clicked()), QCoreApplication::instance(), SLOT(quit()));
    QObject::connect(_convert, SIGNAL(clicked()), this, SLOT(convert()));
    QObject::connect(_erase, SIGNAL(clicked()), this, SLOT(eraseText()));
    QObject::connect(_valueToConvert, SIGNAL(returnPressed()), this, SLOT(convert()));

}


ConvertisseurTemp::~ConvertisseurTemp() {}

void ConvertisseurTemp::convert()
{
    // Variables
    QString writtenText = _valueToConvert->text();
    bool checkConversion;

    // Convertir et vérifier
    float CelciusValue = writtenText.toFloat(&checkConversion);
    if(checkConversion)
    {
        float FahrenheitValue = (CelciusValue * 9.0 / 5.0) + 32.0;
        _resultFaren->setText(QString::number(FahrenheitValue));
    }
    else
    {
        _errorMessage->exec();
    }
}

void ConvertisseurTemp::eraseText()
{
    _valueToConvert->clear();
    _resultFaren->setText(QString("---.---"));
}
