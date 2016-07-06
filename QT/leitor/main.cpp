#include "principal.h"
#include <QApplication>
#include <QDebug>
#include <QCommandLineParser>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    /*QStringList l;
    if(argc >= 2){
        for(int i = 1 ; i < argc ; i++){
            l.append(argv[i]);
        }
    }*/
    Principal w;
    w.show();
    //w.preenche(l);

    return a.exec();
}
