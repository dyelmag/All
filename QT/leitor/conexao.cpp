#include "conexao.h"

Conexao::Conexao()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/Dyel/Videos/QT/Leitor/db/LeitorDB.db");
}

bool Conexao::status(){
    if(!db.open())
        return false;
    else
        return true;
}
