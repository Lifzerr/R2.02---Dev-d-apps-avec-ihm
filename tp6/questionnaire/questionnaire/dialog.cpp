#include "dialog.h"
#include "ui_dialog.h"
#include <QInputDialog>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    // Connections
    QObject::connect(ui->btnOk, SIGNAL(clicked(bool)), this, SLOT(okTriggered()));
    QObject::connect(ui->btnQuit, SIGNAL(clicked(bool)), this, SLOT(close()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::okTriggered()
{
    QString nom = ui->label->text();
    QString prenom = ui->label_2->text();
    bool ok;

    // Vérification du résultat
    if(ui->radioButton->isChecked())
    {
        int numberOfChildren = QInputDialog::getInt(nullptr, "Fenetre de dialogue",
                                                    "Nombre d'enfants", 0, 0, 100, 1, &ok);
    }
}
