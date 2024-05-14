#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSqlQuery>
#include <QTableWidgetItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Ajout des colonnes à la table


    // Instancier la base de données
    bd = new Database();

    // Ouvrir la base de données
    bd->openDataBase();
    if (bd->openDataBase())
    {
        qDebug() << "Connexion à la base de données réussie.";

        // Exemple de requête SQL
        QSqlQuery query;
            if (query.exec("SELECT Reference, Descriptif, PrixHT, Libelle FROM Article "
                           "JOIN Categorie C ON Article.CodeCategorie = C.CodeCategorie;")) {
                // Définir les entêtes de colonnes
                QStringList headers;
                headers << "Référence" << "Descriptif" << "Prix HT" << "Catégorie";
                ui->tableWidget->setColumnCount(4);
                ui->tableWidget->setHorizontalHeaderLabels(headers);

                // Remplir le QTableWidget avec les résultats de la requête
                int row = 0;
                while (query.next()) {
                    ui->tableWidget->insertRow(row);
                    for (int column = 0; column < 4; ++column) {
                        QTableWidgetItem *item = new QTableWidgetItem(query.value(column).toString());
                        ui->tableWidget->setItem(row, column, item);
                    }
                    ++row;
                }
            } else {
                qDebug() << "Erreur lors de l'exécution de la requête SQL:";
            }
    }

    // Fermer la base de données
    bd->closeDataBase();
}

MainWindow::~MainWindow()
{
    delete ui;
}

