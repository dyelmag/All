#include "get_set2.h"

get_set2::get_set2()
{

}

QString get_set2::getCaminho(){
    return caminho;
}

QString get_set2::getTitulo(){
    return titulo;
}

void get_set2::setCaminho(QString c){
    caminho = c;
}


void get_set2::setTitulo(QString c){
    titulo = c;
}
