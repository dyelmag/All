#ifndef DB1_H
#define DB1_H
#include <QString>
#include <QStringList>

class get_set
{
public:
    get_set();
    int getId();
    QString getNome1();
    QString getNome2();
    QString getGenero();
    QString getS1();
    QString getS2();
    int getAno();
    int getEp();
    int getTemporada();
    QString getAutor();
    QString getDiretor();
    QString getPasta();
    QString getCapa();
    QString getEstudio();
    QString getDesc();
    QString getLegenda();
    QString getAudio();
    QString getOrigem();
    QStringList getEp2();
    void setId(int);
    void setNome1(QString);
    void setNome2(QString);
    void setGenero(QString);
    void setS1(QString);
    void setS2(QString);
    void setAno(int);
    void setEp(int);
    void setTemporada(int);
    void setAutor(QString);
    void setDiretor(QString);
    void setPasta(QString);
    void setCapa(QString);
    void setEstudio(QString);
    void setDesc(QString);
    void setLeg(QString);
    void setAudio(QString);
    void setOrigem(QString);
    void setEp2(QStringList);


private:
    QString nome1;
    QString nome2;
    QString genero;
    QString s1;
    QString s2;
    int ano, ep, id, temporada;
    QString autor;
    QString diretor;
    QString pasta;
    QString capa;
    QString estudio;
    QString desc;
    QString legenda;
    QString audio;
    QStringList lEP;
    QString origem;

};

#endif // GET_SET_H
