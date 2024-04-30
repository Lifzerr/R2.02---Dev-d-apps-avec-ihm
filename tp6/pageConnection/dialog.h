#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <iostream>
using namespace std;

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    Ui::Dialog* getUi();
    void setLabel(string);

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
