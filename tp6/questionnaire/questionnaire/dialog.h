#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    int getNbEnfants() const;
    QString getNom() const;
    QString getPrenom() const;

private:
    Ui::Dialog *ui;

private slots:
    void okTriggered();

    int _nombreEnfants;
    QString _nom;
    QString _prenom;

};

#endif // DIALOG_H
