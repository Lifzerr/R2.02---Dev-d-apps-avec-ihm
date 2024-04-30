#include "presentation.h"
#include "ampoulevue.h"


presentation::presentation(QObject *parent)
    : QObject{parent}
{}

void presentation::setModel(Modele *m)
{
    _model = m;
}

void presentation::setVue(AmpouleVue *v)
{
    _vue = v;
}

Modele *presentation::getModel()
{
    return _model;
}

AmpouleVue *presentation::getVue()
{
    return _vue;
}

void presentation::demanderAllumer()
{
    _model->allumer();
    _vue->majInterface(_model->getEtat());
}

void presentation::demanderEteindre()
{
    _model->eteindre();
    _vue->majInterface(_model->getEtat());
}
