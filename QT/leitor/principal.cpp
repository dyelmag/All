#include "principal.h"
#include "ui_principal.h"
#include <QFileDialog>
#include <QLabel>
#include <QDebug>
#include "addedit.h"
#include "leitor.h"


Principal::Principal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Principal)
{
    ui->setupUi(this);
    this->setWindowTitle("Leitor de Mangá");
    MangaDao a;
    if(a.getStatus() == true){
        ui->statusBar->showMessage("Conectado!!!");
    }
    preencheTB(a.getLista());
    QPixmap pixmap1("C:/Users/Dyel/Videos/QT/Leitor/icon/add.png");
    QPixmap pixmap2("C:/Users/Dyel/Videos/QT/Leitor/icon/conf.png");
    QPixmap pixmap3("C:/Users/Dyel/Videos/QT/Leitor/icon/del.png");
    QPixmap pixmap4("C:/Users/Dyel/Videos/QT/Leitor/icon/Sair.png");
    QPixmap pixmap5("C:/Users/Dyel/Videos/QT/Leitor/icon/pasta.png");
    QIcon ButtonIcon(pixmap1);
    QIcon ButtonIcon1(pixmap2);
    QIcon ButtonIcon2(pixmap3);
    QIcon ButtonIcon3(pixmap4);
    QIcon ButtonIcon4(pixmap5);
    ui->add->setIcon(ButtonIcon);
    ui->add->setIconSize(pixmap1.rect().size());
    ui->add->setStyleSheet(styleSheet().append(QString("border-image:url(C:/Users/Dyel/Videos/QT/Leitor/icon/1.png);")));
    ui->alterar->setIcon(ButtonIcon1);
    ui->alterar->setIconSize(pixmap1.rect().size());
    ui->alterar->setStyleSheet(styleSheet().append(QString("border-image:url(C:/Users/Dyel/Videos/QT/Leitor/icon/1.png);")));
    ui->deletar->setIcon(ButtonIcon2);
    ui->deletar->setIconSize(pixmap1.rect().size());
    ui->deletar->setStyleSheet(styleSheet().append(QString("border-image:url(C:/Users/Dyel/Videos/QT/Leitor/icon/1.png);")));
    ui->sair->setIcon(ButtonIcon3);
    ui->sair->setIconSize(pixmap1.rect().size());
    ui->sair->setStyleSheet(styleSheet().append(QString("border-image:url(C:/Users/Dyel/Videos/QT/Leitor/icon/1.png);")));
    ui->abrir->setIcon(ButtonIcon4);
    ui->abrir->setIconSize(pixmap1.rect().size());
    ui->abrir->setStyleSheet(styleSheet().append(QString("border-image:url(C:/Users/Dyel/Videos/QT/Leitor/icon/1.png);")));
}

Principal::~Principal()
{
    delete ui;
}

/*
*/

void Principal::preencheTB(QList<get_set2> lista){
    id = new int[lista.length()];
    ui->tbw->setColumnCount(1);
    QStringList titulos;
    titulos << "Mangás";
    ui->tbw->setHorizontalHeaderLabels(titulos);
    ui->tbw->setColumnWidth(0,600);
    ui->tbw->verticalHeader()->hide();
    ui->tbw->setRowCount(0);
    for(int i = 0 ; i < lista.length() ; i++){
       ui->tbw->insertRow(i);
       ui->tbw->setRowHeight(i, 200);
       id[i] = lista[i].getId();
       QLabel *l = new QLabel();
       QLabel *l1 = new QLabel();
       QLabel *l2 = new QLabel();
       QHBoxLayout *lh = new QHBoxLayout();
       lh->addWidget(l);
       lh->addWidget(l2);
       l1->setLayout(lh);
       QString file = lista[i].getCapa();
       QPixmap capa(file);
       l->setPixmap(capa.scaled(200,200, Qt::KeepAspectRatio));
       l->setFixedSize(200, 200);
       l2->setFixedSize(400, 200);
       l2->setEnabled(false);
       l2->setText("<font size=7>"+lista[i].getNome()+"</font><br>"+"<font size=5>"
                   "Genero: "+lista[i].getGenero()+"<br>"+
                   "Altor: "+lista[i].getAltor()+"<br>"+
                   "Editora: "+lista[i].getEditora()+"<br>"+
                   "Status: "+lista[i].getStatus()+"<br>"+
                   "Ano: "+QString::number(lista[i].getAno())+"<br>"+
                   "Idioma: "+lista[i].getIdioma()+"</font>");
       ui->tbw->setCellWidget(i,0,l1);
       l2->setAlignment(Qt::AlignTop);

    }
}

void Principal::on_actionAbrir_triggered()
{

}

void Principal::on_tbw_clicked(const QModelIndex &index)
{
    r = index.row();
}

void Principal::on_add_clicked()
{
    addEdit a;
    a.exec();
    MangaDao m;
    preencheTB(m.getLista());

}

void Principal::on_abrir_clicked()
{
    Leitor l;
    MangaDao m;
    l.p(m.getLista()[r].getCapi());
    l.exec();
}
