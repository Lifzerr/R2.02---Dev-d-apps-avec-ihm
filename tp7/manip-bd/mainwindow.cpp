#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSqlQuery>
#include <QTableWidgetItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Instancier la base de données
    bd = new Database();

    // Ouvrir la base de données
    bd->openDataBase();
    if (bd->openDataBase())
    {
        ui->label_2->setText(" ");
        qDebug() << "Connexion à la base de données réussie.";

        // Effectuer la requête 1
        // requete1();

        // Effectuer la requête 2
        requete2();

    }
    else
    {
        ui->label_2->setText(QString("Base de données inexistante"));
    }

    // Fermer la base de données
    bd->closeDataBase();

    // Connection du bouton de fermeture
    QObject::connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(close()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::requete1()
{
    // requête SQL n°1
    QSqlQuery query;
        if (query.exec("SELECT Reference, Descriptif, PrixHT, Libelle FROM Article "
                       "JOIN Categorie C ON Article.CodeCategorie = C.CodeCategorie;"))
        {
            // Définir les entêtes de colonnes
            QStringList headers;
            headers << "Référence" << "Descriptif" << "Prix HT" << "Catégorie";
            ui->tableWidget->setColumnCount(4);
            ui->tableWidget->setHorizontalHeaderLabels(headers);

            // Remplir le QTableWidget avec les résultats de la requête
            int row = 0;
            while (query.next())
            {
                ui->tableWidget->insertRow(row);
                for (int column = 0; column < 4; ++column)
                {
                    QTableWidgetItem *item = new QTableWidgetItem(query.value(column).toString());
                    ui->tableWidget->setItem(row, column, item);
                }
                ++row;
            }
        }
        else
        {
            qDebug() << "Erreur lors de l'exécution de la requête SQL:";
        }
}

void MainWindow::etape3()
{
    // Créer les villes à ajouter
    QVariantList paramList;
    paramList.append(64700);
    paramList.append("Hendaye");
    paramList.append(17000);

    // Créer la table villes
    // bd->createDatabase();
    // bd->insertVilles();
    // bd->insertIntoTableVilles(paramList);
}

void MainWindow::requete2()
{
    QSqlQuery query;
    if (query.exec("SELECT * from Villes"))
    {
        QStringList headers;
        headers << "Code Postal" << "Ville" << "Nombre d'habitants";

        ui->tableWidget->setColumnCount(3);
        ui->tableWidget->setHorizontalHeaderLabels(headers);

        // Remplir le QTableWidget avec les résultats de la requête
        int row = 0;
        while (query.next())
        {
            ui->tableWidget->insertRow(row);
            for (int column = 0; column < 3; ++column)
            {
                QTableWidgetItem *item = new QTableWidgetItem(query.value(column).toString());
                ui->tableWidget->setItem(row, column, item);
            }
            ++row;
        }
    }

}

