#include "principal.h"
#include "ui_principal.h"
#include <QPushButton>
#include <QPalette>
#include "formulario.h"
#include "addedit.h"
#include <QProcess>
#include <QLabel>
#include <QFont>
#include <QLayout>
#include <QFileDialog>
#include <QDesktopServices>
#include "get_set.h"
//#include <QDebug>

Principal::Principal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Principal)
{
    ui->setupUi(this);
    r = -1;
    QPixmap pixmap1("icon/add.png");
    QPixmap pixmap2("icon/conf.png");
    QPixmap pixmap3("icon/del.png");
    QPixmap pixmap4("icon/Sair.png");
    QPixmap pixmap5("icon/pasta.png");
    QPixmap pixmap6("icon/detalhe.png");
    QIcon ButtonIcon(pixmap1);
    QIcon ButtonIcon1(pixmap2);
    QIcon ButtonIcon2(pixmap3);
    QIcon ButtonIcon3(pixmap4);
    QIcon ButtonIcon4(pixmap5);
    QIcon ButtonIcon5(pixmap6);
    ui->add_3->setIcon(ButtonIcon);
    ui->add_3->setIconSize(pixmap1.rect().size());
    ui->add_3->setStyleSheet(styleSheet().append(QString("border-image:url(icon/1.png);")));
    ui->alterar->setIcon(ButtonIcon1);
    ui->alterar->setIconSize(pixmap1.rect().size());
    ui->alterar->setStyleSheet(styleSheet().append(QString("border-image:url(icon/1.png);")));
    ui->deletar->setIcon(ButtonIcon2);
    ui->deletar->setIconSize(pixmap1.rect().size());
    ui->deletar->setStyleSheet(styleSheet().append(QString("border-image:url(icon/1.png);")));
    ui->sair->setIcon(ButtonIcon3);
    ui->sair->setIconSize(pixmap1.rect().size());
    ui->sair->setStyleSheet(styleSheet().append(QString("border-image:url(icon/1.png);")));
    ui->pasta->setIcon(ButtonIcon4);
    ui->pasta->setIconSize(pixmap1.rect().size());
    ui->pasta->setStyleSheet(styleSheet().append(QString("border-image:url(icon/1.png);")));
    AnimeDao a;
    if(a.getStatus() == true){
        ui->statusBar->showMessage("Quantidade de Animes Cadastrados: "+QString::number(a.getLista().length()));
    }
    preencheTabela(a.getLista());
    QPixmap pixmap9("icon/icon.png");
    this->setWindowIcon(pixmap9);

}

Principal::~Principal()
{
    delete ui;
}

void Principal::preencheTabela(QList<get_set> lista){
    id = new int[lista.length()];
    ui->tbw->setColumnCount(1);
    QStringList titulos;
    titulos << "Anime";
    ui->tbw->setHorizontalHeaderLabels(titulos);
    ui->tbw->setColumnWidth(0,660);
    ui->tbw->verticalHeader()->hide();
    ui->tbw->setRowCount(0);
    for(int i = 0 ; i < lista.length() ; i++){
       ui->tbw->insertRow(i);
       ui->tbw->setRowHeight(i, 220);
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
       l2->setFixedSize(460, 200);
       l2->setEnabled(false);
       l2->setText("<font size=6>"+lista[i].getNome1()+"</font><table border=1><br>"+
                   +"__________________________________________________________________________________________<br>"
                   "Nome Alternativo: "+lista[i].getNome2()+"<br>"
                   +"__________________________________________________________________________________________"+
                                                                 "<br>"+
                   "Genero: "+lista[i].getGenero()+"<br>"
                   +"__________________________________________________________________________________________"
                   +"<br>"+lista[i].getS1()+"&nbsp;&nbsp;"+lista[i].getS2()+"&nbsp;&nbsp;"+"Tipo: "+lista[i].getAudio()+
                   "\\"+lista[i].getLegenda()+"<br>"
                   +"__________________________________________________________________________________________"
                   +"<br>Autor: "+lista[i].getAutor()+"&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"+
                   "Diretor: "+lista[i].getDiretor()+
                   "<br>"
                   +"__________________________________________________________________________________________"
                   +"<br>Numero de Episodios: "+QString::number(lista[i].getEp())+"&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;"+
                   "Ano: "+QString::number(lista[i].getAno())+
                   "<br>"
                   +"__________________________________________________________________________________________"
                   +"<br>Estudio: "+lista[i].getEstudio()
                   );
       ui->tbw->setCellWidget(i,0,l1);

    }

}

void Principal::preencheTabelaEP(int linha){
    AnimeDao a;
    listaEP = (a.getListaEP(linha));
    signalMapper_ = new QSignalMapper();
    ui->tbep->setRowCount(0);
    ui->tbep->setColumnCount(3);
    QStringList titulos;
    titulos << "Titulo" << "Localização" << " ";
    ui->tbep->setHorizontalHeaderLabels(titulos);
    ui->tbep->setColumnWidth(0,300);
    ui->tbep->setColumnWidth(1,100);
    ui->tbep->setColumnWidth(2,60);
    ui->tbep->setSelectionMode(QAbstractItemView::SingleSelection);
    for(int i = 0 ; i < listaEP.length() ; i++){
        ui->tbep->insertRow(i);
        QPushButton *button = new QPushButton("Abrir");
        connect(button, SIGNAL(clicked(bool)), signalMapper_, SLOT(map()));
        signalMapper_->setMapping(button, i);
        ui->tbep->setItem(i, 0, new QTableWidgetItem(listaEP[i].getTitulo()));
        ui->tbep->setItem(i, 1, new QTableWidgetItem(listaEP[i].getCaminho()));
        ui->tbep->setCellWidget(i, 2, button);
    }
    connect(signalMapper_, SIGNAL(mapped(int)), SLOT(Abre(int)));
}

void Principal::on_sair_clicked()
{
    exit(0);
}

void Principal::Abre(int p){
    QStringList c;
    c << ui->tbep->item(p, 1)->text();
    QProcess *process = new QProcess();
    QString file = "C:/Program Files/MPC-HC/mpc-hc64.exe";
    process->start(file, c);
}

void Principal::AbrePasta(){
    AnimeDao b;
    QProcess *p = new QProcess();
    QString c;
    QStringList a;
    QList<get_set> l;
    l =(b.getLista());
    for(int i = 0 ; i < l.length() ; i++)
        if(l[i].getId() == sel){
            c = l[i].getPasta();
            for(int j = 0 ; j < c.length() ; j++){
                if(c.at(j) == QChar('/')){
                    c[j] = QChar('\\');
                }
            }
        }
    a << c;
    p->start("explorer", a);
}

void Principal::on_add_3_clicked()
{
    addEdit a;
    a.modoI();
    a.setWindowTitle("Inserir Novo");
    a.exec();
    AnimeDao b;
    preencheTabela(b.getLista());
    r = -1;
}

void Principal::on_info_clicked()
{
    Formulario f;
    f.exec();
}

void Principal::on_tbw_clicked(const QModelIndex &index)
{
    r = index.row();
    sel = id[r];
    preencheTabelaEP(sel);

}

void Principal::on_lineEdit_textChanged(const QString &arg1)
{
    AnimeDao b;
    int a = 0;
    QList<get_set> l, l2;
    l =(b.getLista());
    for(int i = 0 ; i < l.length() ; i++){
        if(l[i].getNome1().contains(arg1, Qt::CaseInsensitive) == true){
            l2.append(l[i]);
            a = 1;
        }
    }
    if (a == 0)
        ui->statusBar->showMessage("Anime não encontrado!");
    preencheTabela(l2);
}

void Principal::on_deletar_clicked()
{
    if(r != -1){
        AnimeDao a;
        Formulario f;
        a.Remove(sel);
        preencheTabela(a.getLista());
        preencheTabelaEP(sel);
        f.par("icon/deletado.png", "Removido!");
        f.exec();
        r = -1;
    }
    else
        ui->statusBar->showMessage("Selecione um anime");
}

void Principal::on_pasta_clicked()
{
    if(r != -1)
        AbrePasta();
    else
        ui->statusBar->showMessage("Selecione um anime");

}

void Principal::on_alterar_clicked()
{
    if(r != -1)
    {
        AnimeDao b;
        addEdit a;
        a.modoA(sel);
        a.exec();
        preencheTabela(b.getLista());
    }
    else
        ui->statusBar->showMessage("Selecione um anime");
}

void Principal::on_tbw_doubleClicked()
{
    AnimeDao b;
    addEdit a;
    a.modoA(sel);
    a.exec();
    preencheTabela(b.getLista());
}

void Principal::on_tbw_activated(const QModelIndex &index)
{
    r = index.row();
    sel = id[r];
    preencheTabelaEP(sel);
}

void Principal::on_tbep_doubleClicked(const QModelIndex &index)
{
    Abre(index.row());
}
