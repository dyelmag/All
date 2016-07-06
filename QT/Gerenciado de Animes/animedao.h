#ifndef ANIMEDAO_H
#define ANIMEDAO_H
#include "get_set.h"
#include "get_set2.h"
#include "QStringList"

class AnimeDao
{
public:
    AnimeDao();
    void Insere(get_set);
    void Altera(get_set);
    bool getStatus();
    get_set Info(int);
    QList<get_set> getLista();
    QList<get_set2> getListaEP(int id);
    void salvaListaEP(QList<get_set2> lista);
    void Remove(int);
    int Last();
private:

};

#endif // ANIMEDAO_H
