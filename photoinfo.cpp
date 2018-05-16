#include "photoinfo.h"
#include "ui_photoinfo.h"
#include <QMessageBox>

PhotoInfo::PhotoInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PhotoInfo)
{
    ui->setupUi(this);
    Login conn;
    if(!conn.connOpen())
        ui->label_sec_status->setText("Failed to open the database");
    else
        ui->label_sec_status->setText("DB is connected...");
}

PhotoInfo::~PhotoInfo()
{
    delete ui;
}

void PhotoInfo::on_pushButton_clicked()
{
    Login conn;
    QString pid, author, person, date;
    pid=ui->txt_pid->text();
    author=ui->txt_author->text();
    person=ui->txt_person->text();
    date=ui->txt_date->text();

    if(!conn.connOpen()) {
        qDebug()<<"Failed to open database";
        return;
    }

    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("insert into photoinfo(id,author,person,yymmdd) values ('"+pid+"','"+author+"','"+person+"','"+date+"') ");

    if(qry.exec()) {
        //QMessageBox::critical(this,tr("Save"),tr("Saved"));

        QMessageBox::information(this,tr("Save"),tr("Saved"));
        conn.connClose();
    }
    else {
        QMessageBox::critical(this,tr("error::"),qry.lastError().text());
    }
}

void PhotoInfo::on_pushButton_Edit_clicked()
{
    Login conn;
    QString pid, author, person, date;
    pid=ui->txt_pid->text();
    author=ui->txt_author->text();
    person=ui->txt_person->text();
    date=ui->txt_date->text();

    if(!conn.connOpen()) {
        qDebug()<<"Failed to open database";
        return;
    }

    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("update photoinfo set id='"+pid+"', author='"+author+"', person='"+person+"', yymmdd='"+date+"' where id='"+pid+"' ");

    if(qry.exec()) {

        QMessageBox::information(this,tr("Edit"),tr("Updated"));
        conn.connClose();
    }
    else {
        QMessageBox::critical(this,tr("error::"),qry.lastError().text());
    }
}

void PhotoInfo::on_pushButton_delete_clicked()
{
    Login conn;
    QString pid, author, person, date;
    pid=ui->txt_pid->text();
    author=ui->txt_author->text();
    person=ui->txt_person->text();
    date=ui->txt_date->text();

    if(!conn.connOpen()) {
        qDebug()<<"Failed to open database";
        return;
    }

    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("delete from photoinfo where id='"+pid+"' ");

    if(qry.exec()) {

        QMessageBox::information(this,tr("Delete"),tr("Deleted"));
        conn.connClose();
    }
    else {
        QMessageBox::critical(this,tr("error::"),qry.lastError().text());
    }
}

void PhotoInfo::on_pushButton_load_table_clicked()
{
    Login conn;
    QSqlQueryModel * modal=new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery* qry = new QSqlQuery(conn.mydb);

    qry->prepare("select id, author, person, yymmdd from photoinfo");

    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
    conn.connClose();
}
