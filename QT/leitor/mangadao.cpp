#include "mangadao.h"
#include "conexao.h"

MangaDao::MangaDao()
{

}

bool MangaDao::getStatus(){
    Conexao c;
    return c.status();
}

void MangaDao::InsereM(get_set2 a){
    QSqlQuery qry;
    qry.prepare("INSERT INTO Mangas(nome, altor, genero, editora, status, ano, idioma, capa) VALUES(:n, :a, :g, :e, :s, :an, :i, :c)");
    qry.bindValue(":n", a.getNome());
    qry.bindValue(":a", a.getAltor());
    qry.bindValue(":g", a.getGenero());
    qry.bindValue(":e", a.getEditora());
    qry.bindValue(":s", a.getStatus());
    qry.bindValue(":an", a.getAno());
    qry.bindValue(":i", a.getIdioma());
    qry.bindValue(":c", a.getCapa());
    qry.exec();

}

void MangaDao::InsereC(QList<get_set> a){
    QSqlQuery qry;
    int c = Last("Mangas");
    qry.prepare("INSERT INTO Capitulo(mangaID, titulo) "
                "VALUES (:i, :t)");
    for(int i = 0 ; i < a.length() ; i++){
        qry.bindValue(":i", c);
        qry.bindValue(":t", a[i].getTitulo());
        qry.exec();
        InsereP(a[i].getImg());
    }
}

void MangaDao::InsereP(QStringList a){
    QSqlQuery qry;
    int c = Last("Capitulo");
    qry.prepare("INSERT INTO paginas(ID, end) "
                "VALUES (:i, :e)");
    for(int i = 0 ; i < a.length() ; i++){
        qry.bindValue(":i", c);
        qry.bindValue(":e", a[i]);
        qry.exec();
    }

}

int MangaDao::Last(QString db){
    QSqlQuery qry;
    int i = 0;
    qry.exec("select max(ID) from "+db);
    while(qry.next())
        i = qry.value(0).toInt();
    return i;
}

QList<get_set2> MangaDao::getLista(){
    QList<get_set2> lista;
    QSqlQuery qry;
    qry.exec("select * from Mangas order by nome");
    while(qry.next()){
        get_set2 g;
        int id = qry.value(0).toInt();
        g.setId(id);
        g.setNome(qry.value(1).toString());
        g.setAltor(qry.value(2).toString());
        g.setGenero(qry.value(3).toString());
        g.setEditora(qry.value(4).toString());
        g.setStatus(qry.value(5).toString());
        g.setAno(qry.value(6).toInt());
        g.setIdioma(qry.value(7).toString());
        g.setCapa(qry.value(8).toString());
        g.setCapi(getListaC(id));
        lista.append(g);
    }
    return lista;
}

QList<get_set> MangaDao::getListaC(int id){
    QList<get_set> lista;
    QSqlQuery qry;
    qry.exec("select * from Capitulo e where e.mangaID = "+QString::number(id));
    while(qry.next()){
        get_set g;
        int id = qry.value(0).toInt();
        g.setID(id);
        g.setTitulo(qry.value(2).toString());
        g.setImg(getPaginas(id));
        lista.append(g);
    }
    return lista;
}

QStringList MangaDao::getPaginas(int id){
    QStringList lista;
    QSqlQuery qry;
    qry.exec("select * from paginas e where e.ID = "+QString::number(id));
    while(qry.next()){
        lista.append(qry.value(1).toString());
    }
    return lista;
}
