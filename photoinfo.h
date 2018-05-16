#ifndef PHOTOINFO_H
#define PHOTOINFO_H

#include <QDialog>
#include <login.h>
namespace Ui {
class PhotoInfo;
}

class PhotoInfo : public QDialog
{
    Q_OBJECT

public:
    explicit PhotoInfo(QWidget *parent = 0);
    ~PhotoInfo();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_Edit_clicked();

    void on_pushButton_delete_clicked();

    void on_pushButton_load_table_clicked();

private:
    Ui::PhotoInfo *ui;
};

#endif // PHOTOINFO_H
