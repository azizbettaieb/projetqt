#include "connection.h"
#include <QDebug>

Connection::Connection(){}
bool Connection ::createconection()
{
    db = QSqlDatabase::addDatabase("QODBC");
    bool test=false;

    db.setDatabaseName("Source_Projet2AXE"); // Remplacez par le nom de votre pilote et base de données
    db.setUserName("aziz");  // Nom d'utilisateur de la base de données
    db.setPassword("esprit18");  // Mot de passe de la base de données
    if (db.open()){

        test=true;
    }
    if (!db.open()) {
        qDebug() << "Database error:" << db.lastError().text();
        return false;
    }
    return test;


}
void Connection::closeconection(){db.close() ;     }
