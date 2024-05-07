#include "dialog.h"
#include "ui_dialog.h"
#include <QInputDialog>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    _nombreEnfants = 0;

    // Connections
    QObject::connect(ui->btnOk, SIGNAL(clicked(bool)), this, SLOT(okTriggered()));
    QObject::connect(ui->btnQuit, SIGNAL(clicked(bool)), this, SLOT(close()));
}

Dialog::~Dialog()
{
    delete ui;
}

int Dialog::getNbEnfants() const
{
    return _nombreEnfants;
}

void Dialog::okTriggered()
{
    _nom = ui->label->text();
    _prenom = ui->label_2->text();
    bool ok;

    // Vérification du résultat
    if(ui->radioButton->isChecked())
    {
        _nombreEnfants = QInputDialog::getInt(nullptr, "Fenetre de dialogue",
                                                    "Nombre d'enfants", 0, 0, 100, 1, &ok);
        accept();
    }
}


