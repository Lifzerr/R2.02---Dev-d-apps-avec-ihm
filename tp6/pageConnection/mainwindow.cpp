#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Connections
    QObject::connect(ui->connectButton, SIGNAL(clicked(bool)), this, SLOT(demandeConnexion()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::demandeConnexion()
{
    // Récupération des champs
    QString user = ui->userLIneEdit->text();
    QString password = ui->pwLineEdit->text();

    // Vérification de l'égalité des champs
    if(user == password && user == "moi")
    {
        _dialog = new Dialog(this);
        _dialog->show();
        QMessageBox::information(this, "Connexion", "Connexion réussie");
    }
    else
    {
        QMessageBox::information(this, "Connexion", "Connexion échouée");
    }

    // Nettoyer les zones de saisie
    ui->userLIneEdit->clear();
    ui->pwLineEdit->clear();

}
