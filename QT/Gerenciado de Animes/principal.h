#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>
#include <QDialog>
#include <QDataStream>
#include <QFileInfo>
#include <QSignalMapper>
#include "animedao.h"

namespace Ui {
class Principal;
}

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    explicit Principal(QWidget *parent = 0);
    ~Principal();

private slots:
    void on_sair_clicked();

    void on_add_3_clicked();

    void on_info_clicked();

    void on_tbw_clicked(const QModelIndex &index);

    //void on_tbw_activated(const QModelIndex &index);

    //void on_tbw_entered(const QModelIndex &index);

    void Abre(int p);

    void on_lineEdit_textChanged(const QString &arg1);

    void on_deletar_clicked();

    void on_pasta_clicked();

    void on_alterar_clicked();

    void AbrePasta();

    void on_tbw_doubleClicked();

    void on_tbw_activated(const QModelIndex &index);


    void on_tbep_doubleClicked(const QModelIndex &index);

private:
    Ui::Principal *ui;
    void preencheTabela(QList<get_set>);
    int sel, r;
    QList<get_set2> listaEP;
    get_set g3;
    void preencheTabelaEP(int linha);
    QSignalMapper *signalMapper_;
    int *id;
};

#endif // PRINCIPAL_H
