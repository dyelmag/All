#include "conexao.h"

conexao::conexao()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("db/animeDB.db");

}
bool conexao::status(){
    if(!db.open())
        return false;
    else
        return true;
}
