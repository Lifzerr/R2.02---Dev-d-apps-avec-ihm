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

bool Database::createDatabase()
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
    if (query.exec("create table Villes (codepostal varchar(5) primary key, nomVille varchar(30), nbHabitants int(10))")) {
        qDebug() << "La table 'Villes' a été créée avec succès.";
        return true;
    } else {
        qDebug() << "Erreur lors de la création de la table 'Villes':";
        return false;
    }
}

bool Database::insertVilles()
{
    QSqlQuery query;

    // Insertion de la ville de pau pour vérifier la connection et l'existence de la table
    if (!query.exec("insert into Villes values('64000', 'Pau', 70000);"))
    {
        return false;
    }
    // Insertions
    // Préparationde la requête
    QString insertions="insert into Villes values(?, ?, ?);";
    query.prepare(insertions);

    // Création de la list des codes postaux
    QVariantList codesPostaux;
    codesPostaux << "33000" << "32000" ;
    query.addBindValue(codesPostaux); // Ajout des paramètres à la requête

    // Création de la liste des noms des villes
    QVariantList nomsVilles;
    nomsVilles << "Bordeaux" << "Auch";
    query.addBindValue(nomsVilles); // Insertion des noms de villes

    // Création de la liste du nombre d'ahbitants
    QVariantList nbHabitants;
    nbHabitants << 300000 << 25000;
    query.addBindValue(nbHabitants); // Insertion des noms dans la requête

    // Exécution de la requête + retour
    if (!query.execBatch())
    {
        return false;
    }

    return true;
}


bool Database::insertIntoTableVilles(const QVariantList &data)
{
    QSqlQuery query;

    // Création de la requête
    QString insertions="insert into Villes "
    " values(:cpVille, :nomVille, :nbHabitants);";

    // Préparation
    query.prepare(insertions);

    // Remplissage des variables avec les valeurs de la QVariantList
    query.bindValue(":cpVille", data[0].toInt());
    query.bindValue(":nomVille", data[1].toString());
    query.bindValue(":nbHabitants", data[2].toInt());

    // Exécution + retour
    if(!query.exec()){
        qDebug() << "Erreur lors de l'insertion : ";
        return false;
    }
    else
    return true;
}
