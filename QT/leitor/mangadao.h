#ifndef MANGADAO_H
#define MANGADAO_H
#include "get_set2.h"


class MangaDao
{
public:
    MangaDao();
    void InsereM(get_set2);
    void InsereC(QList<get_set>);
    void InsereP(QStringList);
    void Altera(get_set2);
    bool getStatus();
    get_set Info(int);
    QList<get_set2> getLista();
    QList<get_set> getListaC(int id);
    QStringList getPaginas(int id);
    void salvaListaEP(QList<get_set2> lista);
    void Remove(int);
    int Last(QString);
};

#endif // MANGADAO_H
