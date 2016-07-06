#ifndef CONEXAO_H
#define CONEXAO_H
#include <QtSql>

class conexao
{
public:
    conexao();
    bool status();
private:
    QSqlDatabase db;
};

#endif // CONEXAO_H
