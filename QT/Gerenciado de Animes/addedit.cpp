#include "addedit.h"
#include "ui_addedit.h"
#include <QPushButton>
#include <QStringList>
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>
#include "animedao.h"
#include "formulario.h"

addEdit::addEdit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addEdit)
{
    ui->setupUi(this);
    QStringList s1, s2, ori;
    ori << "Mangá" << "Light Novel" << "Outros";
    s1 << "Assistido" << "Não Assitido";
    s2 << "Completo" << "Incompleto";
    ui->s1->insertItems(2, s1);
    ui->s2->insertItems(2, s2);
    ui->origem->insertItems(3, ori);
    qp = 0;
    QPixmap pixmap2("icon/addedit.png");
    this->setWindowIcon(pixmap2);

}

addEdit::~addEdit()
{
    delete ui;
}
void addEdit::modoI(){
        ui->gb->setTitle("Inserir Novo");
        qEP = 0;
        mod = 1;
        ui->audio->setText("Japonês");
        ui->legenda->setText("PT-BR");
        ui->temporada->setMinimum(1);
}

void addEdit::modoA(int id){
    AnimeDao a;
    get_set b;
    b = a.Info(id);
    this->setWindowTitle(b.getNome1());
    ui->gb->setTitle(b.getNome1());
    ui->nome->setText(b.getNome1());
    ui->nomeA->setText(b.getNome2());
    ui->genero->setText(b.getGenero());
    if(b.getS1() == "Assitido")
        ui->s1->setCurrentIndex(0);
    else
        ui->s1->setCurrentIndex(1);
    if(b.getS2() == "Completo")
        ui->s2->setCurrentIndex(0);
    else
        ui->s2->setCurrentIndex(1);
    if((b.getOrigem() == "Mangá") || (b.getOrigem() == "mangá"))
        ui->origem->setCurrentIndex(0);
    else
        if((b.getOrigem() == "Light Novel") || (b.getOrigem() == "Light novel") || (b.getOrigem() == "light novel"))
            ui->origem->setCurrentIndex(1);
        else
            if(b.getOrigem() == "Outros")
                ui->origem->setCurrentIndex(2);
            else{
                ui->origem->addItem(b.getOrigem());
                ui->origem->setCurrentIndex(3);
            }
    ui->ano->setText(QString::number(b.getAno()));
    ui->nep->setText(QString::number(b.getEp()));
    ui->autor->setText(b.getAutor());
    ui->diretor->setText(b.getDiretor());
    ui->pasta->setText(b.getPasta());
    ui->capa->setText(b.getCapa());
    ui->estudio->setText(b.getEstudio());
    ui->desc->setText(b.getDesc());
    ui->audio->setText(b.getAudio());
    ui->legenda->setText(b.getLegenda());
    //ui->origem->setText(b.getOrigem());
    //ui->temporada->setText(QString::number(b.getTemporada()));
    ui->temporada->setValue(b.getTemporada());
    QPixmap capa(b.getCapa());
    ui->capa_2->setPixmap(capa.scaled(300,300, Qt::KeepAspectRatio));
    listaEP = (a.getListaEP(id));
    qEP = listaEP.length();
    preencheT();
}

void addEdit::preencheT(){
    signalMapper_ = new QSignalMapper();
    signalMapper2 = new QSignalMapper();
    ui->tb->setRowCount(0);
    ui->tb->setColumnCount(4);
    QStringList titulos;
    titulos << "-" << "Titulo" << "Localização" << " ";
    ui->tb->setHorizontalHeaderLabels(titulos);
    ui->tb->setColumnWidth(0,20);
    ui->tb->setColumnWidth(1,210);
    ui->tb->setColumnWidth(2,150);
    ui->tb->setColumnWidth(3,50);
    ui->tb->setSelectionMode(QAbstractItemView::SingleSelection);
    for (int i = 0; i < listaEP.length(); i++) {
        ui->tb->insertRow(i);
        QPushButton *button = new QPushButton("-");
        QPushButton *button2 = new QPushButton("Abrir");
        connect(button, SIGNAL(clicked(bool)), signalMapper_, SLOT(map()));
        connect(button, SIGNAL(clicked(bool)), signalMapper2, SLOT(map()));
        signalMapper_->setMapping(button, i);
        signalMapper2->setMapping(button2, i);
        ui->tb->setCellWidget(i, 0, button);
        ui->tb->setCellWidget(i, 3, button2);
        ui->tb->setItem(i, 1, new QTableWidgetItem(listaEP[i].getTitulo()));
        ui->tb->setItem(i, 2, new QTableWidgetItem(listaEP[i].getCaminho()));
    }
    connect(signalMapper_, SIGNAL(mapped(int)), SLOT(DeletePressed(int)));
    connect(signalMapper2, SIGNAL(mapped(int)), SLOT(Abre(int)));
}

void addEdit::on_pushButton_5_clicked()
{
    QStringList l;
    get_set2 a;
    l = QFileDialog::getOpenFileNames(this, tr("Abrir Arquivo"), ui->pasta->text(), "All File(*.*)");
    for(int i = qEP ; i < l.length() + qEP ; i++){
        a.setTitulo("Sem Titulo");
        a.setCaminho(l.at(i - qEP));
        listaEP.append(a);
    }
    if(ui->nep->text().isEmpty())
        ui->nep->setText(QString::number(l.length()));
    preencheT();
}
void addEdit::DeletePressed(int row)
{
    listaEP.removeAt(row);
    ui->tb->clear();
    preencheT();
}

void addEdit::on_pushButton_4_clicked()
{
    reject();
}

void addEdit::on_pushButton_2_clicked()
{
    if(ui->nome->text().isEmpty()){
        Formulario f;
        f.par("icon/at.png", "O campo Nome é Obrigatorio");
        f.exec();
    }
    else{
        get_set a;
        AnimeDao d;
        a.setNome1(ui->nome->text());
        a.setNome2(ui->nomeA->text());
        a.setGenero(ui->genero->text());
        a.setS1(ui->s1->currentText());
        a.setS2(ui->s2->currentText());
        a.setAno(ui->ano->text().toInt());
        a.setEp(ui->nep->text().toInt());
        a.setAutor(ui->autor->text());
        a.setDiretor(ui->diretor->text());
        a.setPasta(ui->pasta->text());
        a.setCapa(ui->capa->text());
        a.setEstudio(ui->estudio->text());
        a.setDesc(ui->desc->toPlainText());
        a.setAudio(ui->audio->text());
        a.setLeg(ui->legenda->text());
        a.setOrigem(ui->origem->currentText());
        a.setTemporada(ui->temporada->text().toInt());
        d.Insere(a);
        for(int i = 0 ; i < listaEP.length() ; i++){
            listaEP[i].setTitulo(ui->tb->item(i, 1)->text());
        }
        d.salvaListaEP(listaEP);
        Formulario f;
        f.par("icon/sucess.png", "Anime: " + ui->nome->text() + " Cadastrado com sucesso!");
        f.exec();
    }
}

void addEdit::on_btPasta_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"), "",
                                                    QFileDialog::ShowDirsOnly
                                                    | QFileDialog::DontResolveSymlinks);
    ui->pasta->setText(dir);

}

void addEdit::on_pushButton_clicked()
{
    QString file;
    file = QFileDialog::getOpenFileName(this, tr("Abrir Arquivo"), ui->pasta->text(), "All File(*.*)");
    ui->capa->setText(file);
    QPixmap capa(file);
    ui->capa_2->setPixmap(capa.scaled(300,300, Qt::KeepAspectRatio));
}
