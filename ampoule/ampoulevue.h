#ifndef AMPOULEVUE_H
#define AMPOULEVUE_H

#include <QWidget>
#include "modele.h"

QT_BEGIN_NAMESPACE
namespace Ui {  class AmpouleVue;  }
QT_END_NAMESPACE

class presentation;
class AmpouleVue : public QWidget
{
    Q_OBJECT

public:
    // Constructeur, destructeur
    AmpouleVue(QWidget *parent = nullptr);
    ~AmpouleVue();

    // Méthodes
    void setPresentation(presentation* p);
    presentation* getPresentation();
    void majInterface(Modele::UnEtat);

public slots:
    // Gestion de l'image
    demanderAllumer();
    demanderEteindre();

private:
    // Design
    Ui::AmpouleVue *ui;

    // Attributs
    presentation* _pres;

};
#endif // AMPOULEVUE_H
