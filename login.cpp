#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);

    QPixmap pix (":database.png");
    ui->label_pic->setPixmap(pix);

    if(!connOpen())
        ui->label->setText("Failed to open the database");
    else
        ui->label->setText("Connected...");
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
{
    QString username, password;
    username=ui->lineEdit_username->text();
    password=ui->lineEdit_Password->text();

    if(!connOpen()) {
        qDebug()<<"Failed to open database";
        return;
    }

    connOpen();
    QSqlQuery qry;
    qry.prepare("select * from photoinfo where username='"+username +"' and password='"+password+"'" );

    if(qry.exec()) {
        int count=0;
        while(qry.next()) {
            count++;
        }
        if(count == 1){
            ui->label->setText("Username and password is correct");
            connClose();
            this->hide();
            PhotoInfo photoinfo;
            photoinfo.setModal(true);
            photoinfo.exec();
        }
        if(count > 1)
            ui->label->setText("Duplicate username and password");
        if(count < 1)
            ui->label->setText("Username and password is not correct");
    }
}
