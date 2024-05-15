#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>


#define DATABASE_NAME "mbourciez_bd"
#define CONNECT_TYPE "QODBC"

class Database
{
public:
    Database();
    bool openDataBase();
    void closeDataBase();
    bool createDatabase();
    bool insertVilles();
    bool insertIntoTableVilles(const QVariantList &data);

private:
    QSqlDatabase mydb;
};

#endif // DATABASE_H
