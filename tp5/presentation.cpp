#include "presentation.h"
#include "qdebug.h"
#include "modele.h"
#include "ampoulevue.h"
#include <QTimer>

presentation::presentation() {}

ampouleVue *presentation::getVue() const
{
    return _vue;
}

Modele *presentation::getModele() const
{
    return _modele;
}

void presentation::setVue(ampouleVue * nVue)
{
    _vue = nVue;
}

void presentation::setModele(Modele * nMod)
{
    _modele = nMod;
}

void presentation::demanderAllumer()
{
    _modele->allumer();
    _vue->majInterface(_modele->getEtat());
    QTimer::singleShot(5000, this, &presentation::demanderEteindre);
}

void presentation::demanderEteindre()
{
    _modele->eteindre();
    _vue->majInterface(_modele->getEtat());
}
