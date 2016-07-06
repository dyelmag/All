#include "get_set2.h"

get_set2::get_set2()
{
    id = 0;
    nome = "";
    altor = "";
    editora = "";
    status = "";
    idioma = "";
    capa = "";
    ano = 0;
}

void get_set2::setId(int a){
    id = a;
}

void get_set2::setNome(QString a){
    nome = a;
}

void get_set2::setGenero(QString a){
    genero = a;
}

void get_set2::setAltor(QString a){
    altor = a;
}

void get_set2::setEditora(QString a){
    editora = a;
}

void get_set2::setStatus(QString a){
    status = a;
}

void get_set2::setIdioma(QString a){
    idioma = a;
}

void get_set2::setCapa(QString a){
    capa = a;
}

void get_set2::setAno(int a){
    ano = a;
}

void get_set2::setCapi(QList<get_set> a){
    capi = a;
}

int get_set2::getId(){
    return id;
}

QString get_set2::getNome(){
    return nome;
}

QString get_set2::getGenero(){
    return genero;
}

QString get_set2::getAltor(){
    return altor;
}

QString get_set2::getEditora(){
    return editora;
}

QString get_set2::getStatus(){
    return status;
}

QString get_set2::getIdioma(){
    return idioma;
}

QString get_set2::getCapa(){
    return capa;
}

int get_set2::getAno(){
    return ano;
}

QList<get_set> get_set2::getCapi(){
    return capi;
}
