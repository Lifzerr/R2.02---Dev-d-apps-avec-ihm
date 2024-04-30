#ifndef CONVERTISSEURTEMP_H
#define CONVERTISSEURTEMP_H

#include <QWidget>
#include <QPushButton>
#include <QErrorMessage>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QMenu>

class ConvertisseurTemp : public QWidget
{
    Q_OBJECT

public:
    ConvertisseurTemp(QWidget *parent = nullptr);
    ~ConvertisseurTemp();
private:
    // Boutons
    QPushButton *_leave;
    QPushButton *_erase;
    QPushButton *_convert;

    // Textes
    QLabel *_mainTitle;
    QLabel *_titleDeg;
    QLabel *_titleFaren;
    QLabel *_resultFaren;

    // Boite de saisie
    QLineEdit *_valueToConvert;

    // Message d'erreur
    QMessageBox *_errorMessage;

 public slots:
    void convert();
    void eraseText();
};
#endif // CONVERTISSEURTEMP_H
