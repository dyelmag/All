#include "formulario.h"
#include "ui_formulario.h"

Formulario::Formulario(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Formulario)
{
    ui->setupUi(this);
}

Formulario::~Formulario()
{
    delete ui;
}
void Formulario::par(QString p1, QString p2){
    QPixmap capa(p1);
    ui->img->setPixmap(capa.scaled(50, 50, Qt::KeepAspectRatio));
    ui->msg->setText(p2);
}

void Formulario::on_pushButton_clicked()
{
    accept();
}
