#ifndef GET_SET2_H
#define GET_SET2_H
#include "get_set.h"
#include <QList>

class get_set2
{
public:
    get_set2();
    void setId(int);
    void setNome(QString);
    void setGenero(QString);
    void setAltor(QString);
    void setEditora(QString);
    void setStatus(QString);
    void setIdioma(QString);
    void setCapa(QString);
    void setAno(int);
    void setCapi(QList<get_set>);
    int getId();
    QString getNome();
    QString getGenero();
    QString getAltor();
    QString getEditora();
    QString getStatus();
    QString getIdioma();
    QString getCapa();
    int getAno();    
    QList<get_set> getCapi();

private:
    QString nome;
    QString altor;
    QString editora;
    QString status;
    QString idioma;
    QString genero;
    QString capa;
    int ano;
    int id;
    QList<get_set> capi;

};

#endif // GET_SET2_H
