#ifndef PRESENTATION_H
#define PRESENTATION_H

#include <QObject>

class Modele;
class ampouleVue;

class presentation : public QObject
{
private:
    ampouleVue* _vue;
    Modele* _modele;

public:
    presentation();

    // Getters
    ampouleVue* getVue() const;
    Modele* getModele() const;

    // Setters
    void setVue(ampouleVue*);
    void setModele(Modele*);

    // Autres méthodes

public:
    void demanderAllumer();
    void demanderEteindre();
};

#endif // PRESENTATION_H
