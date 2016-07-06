#include "addcap.h"
#include "ui_addcap.h"
#include <QFileDialog>
#include "addedit.h"
#include <QDebug>

addCap::addCap(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addCap)
{
    ui->setupUi(this);
}

addCap::~addCap()
{
    delete ui;
}

void addCap::on_pushButton_clicked()
{
    l = QFileDialog::getOpenFileNames(this, tr("Abrir Arquivo"), "", "All File(*.*)");
    ui->q->setText(QString::number(l.length())+" Imagen(s) Selecionada(s)");
}

void addCap::on_pushButton_2_clicked()
{
    get_set a;
    addEdit b1;
    qDebug() <<"aa";
    if(l.length() < 1)
        ui->label->setText("Imagens não selecionada!");
    else{
        if(ui->t->text().isEmpty() == true)
            a.setTitulo("Sem Titulo");
        else
            a.setTitulo(ui->t->text());
        qDebug() <<"b";
        a.setImg(l);
        qDebug() <<"c";
        b1.insetCap(a);
        qDebug() << a.getTitulo();
        //accept();
        qDebug() <<"v";
    }

}

void addCap::on_pushButton_3_clicked()
{
    reject();
}
