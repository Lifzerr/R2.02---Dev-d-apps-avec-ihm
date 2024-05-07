#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    // Connexions
    QObject::connect(ui->okBtn, SIGNAL(clicked()), this, SLOT(quitter()));
}

Dialog::~Dialog()
{
    delete ui;
}


Ui::Dialog* Dialog::getUi()
{
    return ui;
}

void Dialog::setLabel(string result)
{
    QString qResult = QString::fromStdString(result);
    ui->ResultText->setText(qResult);
}

void Dialog::quitter()
{
    ~this;
}
