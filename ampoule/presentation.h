#ifndef PRESENTATION_H
#define PRESENTATION_H

#include "modele.h"

class AmpouleVue;

class presentation : public QObject
{
    Q_OBJECT
public:
    // Constructeur
    explicit presentation(QObject *parent = nullptr);

    // Méthodes
    void setModel(Modele* m);
    void setVue(AmpouleVue* v);
    Modele* getModel();
    AmpouleVue* getVue();

    // Gestion de l'état
    void demanderAllumer();
    void demanderEteindre();
private:
    // Attributs
    Modele* _model;
    AmpouleVue* _vue;

};

#endif // PRESENTATION_H
