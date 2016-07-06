#ifndef GET_SET_H
#define GET_SET_H
#include <QString>
#include <QStringList>

class get_set
{
public:
    get_set();
    void setID(int);
    void setImg(QStringList);
    void setTitulo(QString);
    int getID();
    QStringList getImg();
    QString getTitulo();

private:
    int id;
    QStringList img;
    QString titulo;
};

#endif // GET_SET_H
