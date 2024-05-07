#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Connexions
    QObject::connect(ui->startBtn, SIGNAL(clicked()), this, SLOT(demandeDemarrage()));

    // Rendre les labels invisibles
    ui->nom->hide();
    ui->prenom->hide();
    ui->nbEnf->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::demandeDemarrage()
{
    // Ouverture de la fenêtre de dialogue
    _dlg = new Dialog();
    _dlg->exec();

    // Changement des données
    ui->nom->show();
    ui->prenom->show();
    ui->nbEnf->show();
    ui->label_2->setText(_dlg->getNom());
    ui->label_4->setText(_dlg->getPrenom());
    ui->label_6->setText(QString::number(_dlg->getNbEnfants()));

}


