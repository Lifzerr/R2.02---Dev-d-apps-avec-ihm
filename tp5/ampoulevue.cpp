#include "ampoulevue.h"
#include "ui_ampoulevue.h"

ampouleVue::ampouleVue(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ampouleVue)
{
    ui->setupUi(this);

    // Image
    ui->label->setPixmap(QPixmap::fromImage(QImage(":/new/prefix1/ampouleAllumee2.PNG")));

    // Connexions
    QObject::connect(ui->radioButton, SIGNAL(clicked()), this, SLOT(demanderAllumer()));
    QObject::connect(ui->radioButton_2, SIGNAL(clicked()),this, SLOT(demanderEteindre()));
}

ampouleVue::~ampouleVue()
{
    delete ui;
}

presentation *ampouleVue::getPres() const
{
    return _pres;
}

void ampouleVue::setPres(presentation * nPres)
{
    _pres = nPres;
}

void ampouleVue::demanderAllumer()
{
    // ui->label->setText("Allumée");
    _pres->demanderAllumer();
}

void ampouleVue::demanderEteindre()
{
    // ui->label->setText("Eteinte");
    _pres->demanderEteindre();
}

void ampouleVue::majInterface(Modele::UnEtat e)
{
    switch(e)
    {
    case Modele::allume:
        ui->label->setPixmap(QPixmap::fromImage(QImage(":/new/prefix1/ampouleAllumee2.PNG")));;
        ui->radioButton->setEnabled(false);
        ui->radioButton_2->setEnabled(true);
        break;
    case Modele::eteint:
        ui->label->setPixmap(QPixmap::fromImage(QImage(":/new/prefix1/ampouleEteinte2.PNG")));;
        ui->radioButton->setEnabled(true);
        ui->radioButton_2->setEnabled(false);
        break;
    default:
        break;
    }

}
