#ifndef CONEXAO_H
#define CONEXAO_H
#include <QtSql>


class Conexao
{
public:
    Conexao();
    bool status();
private:
    QSqlDatabase db;
};

#endif // CONEXAO_H
