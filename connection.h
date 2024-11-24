#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class Connection
{  QSqlDatabase db;
public:
    Connection();
    bool createconection();
    void closeconection();
};
#endif // CONNECTION_H
