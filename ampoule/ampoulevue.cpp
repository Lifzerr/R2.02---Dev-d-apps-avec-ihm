#include "ampoulevue.h"
#include "ui_ampoulevue.h"
#include "presentation.h"

AmpouleVue::AmpouleVue(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AmpouleVue)
{
    ui->setupUi(this);
    // Connexions
    QObject::connect(ui->allumer, SIGNAL(clicked()), this, SLOT(demanderAllumer()));
    QObject::connect(ui->eteindre, SIGNAL(clicked()), this, SLOT(demanderEteindre()));
}

AmpouleVue::~AmpouleVue()
{
    delete ui;
}

void AmpouleVue::setPresentation(presentation *p)
{
    _pres = p;
}

presentation* AmpouleVue::getPresentation()
{
    return _pres;
}

void AmpouleVue::majInterface(Modele::UnEtat etat)
{
    switch(etat)
    {
        case Modele::allume:
            ui->image->setText("Allumé");
            break;
        case Modele::eteint:
            ui->image->setText("Eteint");
            break;
    }
}

AmpouleVue::demanderAllumer()
{
    this->getPresentation()->demanderAllumer();
}


AmpouleVue::demanderEteindre()
{
    this->getPresentation()->demanderEteindre();
}


