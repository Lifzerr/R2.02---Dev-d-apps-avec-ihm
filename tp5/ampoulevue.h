#ifndef AMPOULEVUE_H
#define AMPOULEVUE_H


#include "presentation.h"
#include <QWidget>
#include "modele.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class ampouleVue;
}
QT_END_NAMESPACE


class ampouleVue : public QWidget
{
    Q_OBJECT

public:
    ampouleVue(QWidget *parent = nullptr);
    ~ampouleVue();
    presentation *getPres() const;
    void setPres(presentation *);
    void majInterface(Modele::UnEtat);

private slots:
    void demanderAllumer();
    void demanderEteindre();

private:
    Ui::ampouleVue *ui;
    presentation* _pres;
};
#endif // AMPOULEVUE_H
