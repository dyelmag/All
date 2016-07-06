#include "get_set.h"

get_set::get_set()
{

}
int get_set::getId(){
    return id;
}

QString get_set::getNome1(){
    return nome1;
}

QString get_set::getNome2(){
    return nome2;
}

QString get_set::getGenero(){
    return genero;
}

QString get_set::getS1(){
    return s1;
}

QString get_set::getS2(){
    return s2;
}

int get_set::getAno(){
    return ano;
}

int get_set::getEp(){
    return ep;
}

int get_set::getTemporada(){
    return temporada;
}

QString get_set::getAutor(){
    return autor;
}

QString get_set::getDiretor(){
    return diretor;
}

QString get_set::getPasta(){
    return pasta;
}

QString get_set::getCapa(){
    return capa;
}

QString get_set::getEstudio(){
    return estudio;
}

QString get_set::getDesc(){
    return desc;
}

QString get_set::getLegenda(){
    return legenda;
}

QString get_set::getAudio(){
    return audio;
}

QString get_set::getOrigem(){
    return origem;
}

QStringList get_set::getEp2(){
    return lEP;
}

void get_set::setId(int a){
    id = a;
}

void get_set::setNome1(QString a){
    nome1 = a;
}

void get_set::setNome2(QString a){
    nome2 = a;
}

void get_set::setGenero(QString a){
    genero = a;
}

void get_set::setS1(QString a){
    s1 = a;
}

void get_set::setS2(QString a){
    s2 = a;
}

void get_set::setAno(int a){
    ano = a;
}

void get_set::setEp(int a){
    ep = a;
}

void get_set::setTemporada(int a){
    temporada = a;
}

void get_set::setAutor(QString a){
    autor = a;
}

void get_set::setDiretor(QString a){
    diretor = a;
}

void get_set::setPasta(QString a){
    pasta = a;
}

void get_set::setCapa(QString a){
    capa = a;
}

void get_set::setEstudio(QString a){
    estudio = a;
}

void get_set::setDesc(QString a){
    desc = a;
}

void get_set::setLeg(QString a){
    legenda = a;
}

void get_set::setAudio(QString a){
    audio = a;
}

void get_set::setOrigem(QString a){
    origem = a;
}

void get_set::setEp2(QStringList a){
    lEP = a;
}
