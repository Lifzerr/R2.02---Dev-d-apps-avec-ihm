#ifndef CONVERTISSEURTEMP_H
#define CONVERTISSEURTEMP_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QErrorMessage>
#include <QPushButton>

class convertisseurTemp : public QWidget
{
    Q_OBJECT

public:
    convertisseurTemp(QWidget *parent = nullptr);
    ~convertisseurTemp();
    QLabel *_titre;
    QLabel *_legendeDeg;
    QLabel *_legendeFar;
    QLabel *_resultatConvert;
    QPushButton *_btnQuitter;
    QPushButton *_btnConvert;
    QPushButton *_btnReset;
    QLineEdit *_valueToConvert;
    QErrorMessage *_errorMessage;
};
#endif // CONVERTISSEURTEMP_H
