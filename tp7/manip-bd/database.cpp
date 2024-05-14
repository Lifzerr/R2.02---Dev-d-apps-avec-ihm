#include "database.h"
#include "mainwindow.h"

#include <QSqlQuery>

Database::Database()
{

}

bool Database::openDataBase()
{
    // Définir les paramètres de connexion à la base de données
    mydb = QSqlDatabase::addDatabase(CONNECT_TYPE);
    mydb.setDatabaseName(DATABASE_NAME);
    if (!mydb.open()) {
        qDebug() << "Impossible d'ouvrir la base de données:" ;
        return false;
   }

   qDebug() << "Connexion à la base de données réussie.";
   return true;

}

void Database::closeDataBase()
{
    // Fermer la connexion à la base de données
    mydb.close();
    qDebug() << "Connexion à la base de données fermée.";
}

bool Database::restoreDataBase()
{
    if (!mydb.isValid()) {
        qDebug() << "La base de données n'est pas valide.";
        return false;
    }

    // Vérifier si la base de données existe déjà
    if (mydb.tables().contains("Villes")) {
        qDebug() << "La table 'Villes' existe déjà.";
        return true;
    }

    // Créer la table 'Villes' si elle n'existe pas
    QSqlQuery query;
    if (query.exec("CREATE TABLE Villes (id INT PRIMARY KEY, nom TEXT)")) {
        qDebug() << "La table 'Villes' a été créée avec succès.";
        return true;
    } else {
        qDebug() << "Erreur lors de la création de la table 'Villes':" << query.lastError().text();
        return false;
    }
}
