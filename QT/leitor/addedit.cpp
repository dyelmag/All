#include "addedit.h"
#include "ui_addedit.h"
#include <QFileDialog>
#include "addcap.h"
#include <QDebug>
#include <QPushButton>
#include "mangadao.h"

addEdit::addEdit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addEdit)
{
    ui->setupUi(this);
    QStringList s;
    s << "Em lançamento" << "Finalizado";
    ui->status->addItems(s);
    linha = 0;
}

addEdit::~addEdit()
{
    delete ui;
}

void addEdit::on_pushButton_clicked()
{
    QString file;
    file = QFileDialog::getOpenFileName(this, tr("Abrir Arquivo"), "", "All File(*.*)");
    ui->capa->setText(file);
    QPixmap capa(file);
    ui->lbCapa->setPixmap(capa.scaled(200,300, Qt::KeepAspectRatio));
}

void addEdit::on_pushButton_3_clicked()
{
    reject();
}

void addEdit::on_pushButton_4_clicked()
{
    get_set a;
    a.setTitulo("Capitulo "+QString::number(linha));
    linha++;
    l.append(a);
    preencheT();
}

void addEdit::insetCap(get_set a){
    l.append(a);
    qDebug() << "q";
    //preencheTab();
    qDebug() << "q2";
}

void addEdit::preencheT(){
    signalMapper_ = new QSignalMapper();
    signalMapper2 = new QSignalMapper();
    ui->tb->setRowCount(0);
    ui->tb->setColumnCount(4);
    QStringList titulos;
    titulos << "-" << "Titulo" << "Paginas" << " ";
    ui->tb->setHorizontalHeaderLabels(titulos);
    ui->tb->setColumnWidth(0,20);
    ui->tb->setColumnWidth(1,120);
    ui->tb->setColumnWidth(2,50);
    ui->tb->setColumnWidth(3,50);
    ui->tb->setSelectionMode(QAbstractItemView::SingleSelection);
    for (int i = 0; i < l.length(); i++) {
        ui->tb->insertRow(i);
        QPushButton *button = new QPushButton("-");
        QPushButton *button2 = new QPushButton("Abrir");
        connect(button, SIGNAL(clicked(bool)), signalMapper_, SLOT(map()));
        connect(button2, SIGNAL(clicked(bool)), signalMapper2, SLOT(map()));
        signalMapper_->setMapping(button, i);
        signalMapper2->setMapping(button2, i);
        ui->tb->setCellWidget(i, 0, button);
        ui->tb->setCellWidget(i, 3, button2);
        ui->tb->setItem(i, 1, new QTableWidgetItem(l[i].getTitulo()));
        ui->tb->setItem(i, 2, new QTableWidgetItem(QString::number(l[i].getImg().length())));
    }
    connect(signalMapper_, SIGNAL(mapped(int)), SLOT(DeletePressed(int)));
    connect(signalMapper2, SIGNAL(mapped(int)), SLOT(Abre(int)));
}

void addEdit::Abre(int row){
    QStringList li = QFileDialog::getOpenFileNames(this, tr("Abrir Arquivo"), "", "All File(*.*)");
    l[row].setImg(li);
    preencheT();
}

void addEdit::DeletePressed(int row)
{
    l.removeAt(row);
    preencheT();
    linha--;
}

void addEdit::on_pushButton_2_clicked()
{
    get_set2 a;
    MangaDao m;
    a.setNome(ui->nome->text());
    a.setGenero(ui->lineEdit->text());
    a.setAltor(ui->altor->text());
    a.setEditora(ui->editora->text());
    a.setStatus(ui->status->currentText());
    a.setAno(ui->ano->text().toInt());
    a.setCapa(ui->capa->text());
    a.setIdioma(ui->idioma->text());
    a.setCapi(l);
    m.InsereM(a);
    m.InsereC(a.getCapi());
}
