#ifndef GET_SET2_H
#define GET_SET2_H
#include <QString>


class get_set2
{
public:
    get_set2();
    QString getTitulo();
    QString getCaminho();
    void setTitulo(QString);
    void setCaminho(QString);

private:
    QString titulo;
    QString caminho;
};

#endif // GET_SET2_H
