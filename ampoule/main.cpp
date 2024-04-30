#include "ampoulevue.h"
#include "modele.h"
#include "presentation.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    // Composants dee l'application
    QApplication a(argc, argv);
    AmpouleVue w;
    Modele* m = new Modele();
    presentation* p = new presentation();

    // Création du MVP
    p->setModel(m);
    p->setVue(&w);
    w.setPresentation(p);

    // Atribuer un etat par défaut
    p->demanderEteindre();

    // Faire tourner l'app
    w.show();
    return a.exec();
}
