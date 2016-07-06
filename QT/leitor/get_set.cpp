#include "get_set.h"

get_set::get_set()
{

}

void get_set::setID(int a){
    id = a;
}

void get_set::setImg(QStringList a){
    img = a;
}

void get_set::setTitulo(QString a){
    titulo = a;
}

int get_set::getID(){
    return id;
}

QStringList get_set::getImg(){
    return img;
}

QString get_set::getTitulo(){
    return titulo;
}
