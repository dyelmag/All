#include "animedao.h"
#include "conexao.h"
#include <QDebug>

AnimeDao::AnimeDao()
{

}
bool AnimeDao::getStatus(){
    conexao c;
    return c.status();
}

int AnimeDao::Last(){
    QSqlQuery qry;
    int i = 0;
    qry.exec("select max(animeID) from animes");
    while(qry.next())
        i = qry.value(0).toInt();
    return i;
}

void AnimeDao::Insere(get_set a){
    QSqlQuery qry;
    qry.prepare("INSERT INTO animes(nome, nome2, genero, statusV, statusA, anoL, nEP, autor, diretor, pasta, capa, estudio, sinopsia, audio, legenda, origem, temporada) "
                "VALUES (:n1, :n2, :g, :sV, :sA, :y, :n, :a, :d, :p, :c, :e, :s, :au, :l, :o, :t)");
    qry.bindValue(":n1", a.getNome1());
    qry.bindValue(":n2", a.getNome2());
    qry.bindValue(":g", a.getGenero());
    qry.bindValue(":sV", a.getS1());
    qry.bindValue(":sA", a.getS2());
    qry.bindValue(":y", a.getAno());
    qry.bindValue(":n", a.getEp());
    qry.bindValue(":a", a.getAutor());
    qry.bindValue(":d", a.getDiretor());
    qry.bindValue(":p", a.getPasta());
    qry.bindValue(":c", a.getCapa());
    qry.bindValue(":e", a.getEstudio());
    qry.bindValue(":s", a.getDesc());
    qry.bindValue(":au", a.getAudio());
    qry.bindValue(":l", a.getLegenda());
    qry.bindValue(":o", a.getOrigem());
    qry.bindValue(":t", a.getTemporada());
    qry.exec();


}

QList<get_set> AnimeDao::getLista(){
    QList<get_set> lista;
    QSqlQuery qry;
    qry.exec("select * from animes order by nome");
    while(qry.next()){
        get_set g;
        //g = new get_set();
        g.setId(qry.value(0).toInt());
        g.setNome1(qry.value(1).toString());
        g.setNome2(qry.value(2).toString());
        g.setGenero(qry.value(3).toString());
        g.setS1(qry.value(4).toString());
        g.setS2(qry.value(5).toString());
        g.setAno(qry.value(6).toInt());
        g.setEp(qry.value(7).toInt());
        g.setAutor(qry.value(8).toString());
        g.setDiretor(qry.value(9).toString());
        g.setPasta(qry.value(10).toString());
        g.setCapa(qry.value(11).toString());
        g.setEstudio(qry.value(12).toString());
        g.setDesc(qry.value(13).toString());
        g.setAudio(qry.value(14).toString());
        g.setLeg(qry.value(15).toString());
        g.setOrigem(qry.value(16).toString());
        g.setTemporada(qry.value(17).toInt());
        lista.append(g);
    }
    return lista;
}

QList<get_set2> AnimeDao::getListaEP(int id){
    QList<get_set2> lista;
    QSqlQuery qry;
    QString a = "select * from tbEP e where e.animeID = "+QString::number(id);
    qry.exec(a);
    while(qry.next()){
        get_set2 g;
        g.setCaminho(qry.value(1).toString());
        g.setTitulo(qry.value(2).toString());
        lista.append(g);
    }
    return lista;
}

void AnimeDao::salvaListaEP(QList<get_set2> lista){
    int id = Last();
    QSqlQuery qry;
    for(int i = 0 ; i < lista.length() ; i++){
        qry.prepare("INSERT INTO tbEP(animeID, localizacao, titulo) VALUES (:ID, :n1, :n2)");
        qry.bindValue(":ID", id);
        qry.bindValue(":n1", lista[i].getCaminho());
        qry.bindValue(":n2", lista[i].getTitulo());
        qry.exec();
    }

}

get_set AnimeDao::Info(int id){
    get_set g;
    QSqlQuery qry;
    QString a = "select * from animes e where e.animeID = "+QString::number(id);
    qry.exec(a);
    while(qry.next()){
        g.setNome1(qry.value(1).toString());
        g.setNome2(qry.value(2).toString());
        g.setGenero(qry.value(3).toString());
        g.setS1(qry.value(4).toString());
        g.setS2(qry.value(5).toString());
        g.setAno(qry.value(6).toInt());
        g.setEp(qry.value(7).toInt());
        g.setAutor(qry.value(8).toString());
        g.setDiretor(qry.value(9).toString());
        g.setPasta(qry.value(10).toString());
        g.setCapa(qry.value(11).toString());
        g.setEstudio(qry.value(12).toString());
        g.setDesc(qry.value(13).toString());
        g.setAudio(qry.value(14).toString());
        g.setLeg(qry.value(15).toString());
        g.setOrigem(qry.value(16).toString());
        g.setTemporada(qry.value(17).toInt());
    }
    return g;
}

void AnimeDao::Remove(int id){
    QSqlQuery qry;
    QString a, b;
    a = "DELETE FROM animes WHERE animeID = "+QString::number(id);
    b = "DELETE FROM tbEP WHERE animeID = "+QString::number(id);
    qry.exec(a);
    qry.exec(b);
}
