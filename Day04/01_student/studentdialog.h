#ifndef STUDENTDIALOG_H
#define STUDENTDIALOG_H

#include <QDialog>

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QDebug>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class StudentDialog; }
QT_END_NAMESPACE

class StudentDialog : public QDialog
{
    Q_OBJECT

public:
    StudentDialog(QWidget *parent = nullptr);
    ~StudentDialog();
private:
    void createDB(); //创建数据集
    void createTable();//创建数据表
    void queryTable(); //查询
private slots:
    void on_insert_pushButton_clicked();

    void on_delete_pushButton_clicked();

    void on_update_pushButton_clicked();

    void on_sord_pushButton_clicked();

private:
    Ui::StudentDialog *ui;
    QSqlDatabase db ;//建立Qt和数据库的连接
    QSqlQueryModel model;// 保存结果集
};
#endif // STUDENTDIALOG_H
