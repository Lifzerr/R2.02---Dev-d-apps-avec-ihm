#include "ampoulevue.h"
#include "modele.h"
#include "presentation.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Variables
    ampouleVue w;
    Modele* mod = new Modele();
    presentation* pres = new presentation();

    // Associations
    pres->setModele(mod);
    pres->setVue(&w);
    w.setPres(pres);

    // Affichage fenetre
    w.show();
    return a.exec();
}
