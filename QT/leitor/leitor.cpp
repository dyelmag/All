#include "leitor.h"
#include "ui_leitor.h"
#include <QLabel>
#include <QLayout>

Leitor::Leitor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Leitor)
{
    ui->setupUi(this);

}

Leitor::~Leitor()
{
    delete ui;
}

void Leitor::p(QList<get_set> a){
    b = a;
    id = new int[a.length()];
    ui->tbw->setColumnCount(1);
    QStringList titulos;
    titulos << "Capitulos";
    ui->tbw->setHorizontalHeaderLabels(titulos);
    ui->tbw->setColumnWidth(0,250);
    ui->tbw->verticalHeader()->hide();
    ui->tbw->setRowCount(0);
    for(int i = 0 ; i < a.length() ; i++){
       ui->tbw->insertRow(i);
       id[i] = a[i].getID();
       ui->tbw->setItem(i, 0, new QTableWidgetItem(a[i].getTitulo()));
    }

}

void Leitor::preenche(QStringList lista){
    ui->tb->setColumnCount(1);
    QStringList titulos;
    titulos << "Paginas ("+QString::number(lista.length())+")";
    ui->tb->setHorizontalHeaderLabels(titulos);
    ui->tb->verticalHeader()->hide();
    ui->tb->setRowCount(0);
    ui->tb->setColumnWidth(0,1300);
    for(int i = 0 ; i < lista.length() ; i++){
        ui->tb->insertRow(i);
        QLabel *l = new QLabel();
        QPixmap capa(lista.at(i));
        l->setPixmap(capa);
        ui->tb->setRowHeight(i, 700);
        ui->tb->setCellWidget(i,0,l);
    }
}

void Leitor::on_tbw_clicked(const QModelIndex &index)
{
    preenche(b[index.row()].getImg());
    //sel = index.row();
}
