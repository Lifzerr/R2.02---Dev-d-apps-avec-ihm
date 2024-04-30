#include "convertisseurtemp.h"

convertisseurTemp::convertisseurTemp(QWidget *parent)
    : QWidget(parent)
{
    // Fenêtre


    // Textes
    _titre = new QLabel;
    _titre->setFont(QFont("Arial",14,QFont::Bold));
    _titre->setText(Qstring("Convertisseur de températures"));
    _titre->setGeometry();

    _legendeDeg = new QLabel;
    _legendeFar = new QLabel;
    _resultatConvert = new QLabel;

    // Boutons
    _btnQuitter = new QPushButton;
    _btnConvert = new QPushButton;
    _btnQuitter = new QPushButton;

    // Zone de saisie
    _valueToConvert = new QLineEdit;

    // Message d'erreur
    _errorMessage = new QErrorMessage;
}

convertisseurTemp::~convertisseurTemp() {}
