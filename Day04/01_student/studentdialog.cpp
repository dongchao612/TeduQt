#include "studentdialog.h"
#include "ui_studentdialog.h"

StudentDialog::StudentDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::StudentDialog)
{
    ui->setupUi(this);
    createDB();
    createTable();
    queryTable();

}

StudentDialog::~StudentDialog()
{
    delete ui;
}

//创建数据集
void StudentDialog::createDB()
{
    //添加数据库驱动
    db=QSqlDatabase::addDatabase("QSQLITE");
    //设置数据集名字(文件名)
    db.setDatabaseName("student.db");

    //打开数据库
    if(db.open()==true)
    {
        qDebug()<<"创建/打开数据集成功";
    }
    else
    {
        qDebug()<<"创建/打开数据集失败";
    }
}

//创建数据表
void StudentDialog::createTable()
{
    QSqlQuery query;
    QString sql=QString("create table student(id int primary key not null,name text not null,score real not null);");
    if (query.exec(sql)==false)
    {
        qDebug()<<sql;
    }
    else
    {
        qDebug()<<"创建数据表成功";
    }
}

//查询
void StudentDialog::queryTable()
{
    QString sql=QString("select * from student;");
    model.setQuery(sql);
    ui->tableView->setModel(&model);
}

//插入
void StudentDialog::on_insert_pushButton_clicked()
{
    QSqlQuery query;
    int id = ui->ID_lineEdit->text().toInt();
    if(id==0)
    {
        QMessageBox::critical(this,"Error","ID输入错误");
        return ;
    }
    QString name = ui->name_lineEdit->text();
    if(name=="")
    {
        QMessageBox::critical(this,"Error","姓名输入错误");
        return ;
    }
    double score = ui->score_lineEdit->text().toDouble();
    if(score<=0 ||score>100)
    {
        QMessageBox::critical(this,"Error","成绩输入错误");
        return ;
    }

    QString sql = QString("insert into student values (%1, '%2', '%3');").arg(id).arg(name).arg(score);
    if (query.exec(sql)==false)
    {
       qDebug()<<sql;
    }
    else
    {
       qDebug()<<"插入成功";
       queryTable();
    }

    ui->ID_lineEdit->clear();
    ui->name_lineEdit->clear();
    ui->score_lineEdit->clear();
}

//删除 根据ID
void StudentDialog::on_delete_pushButton_clicked()
{
    QSqlQuery query;
    int id=ui->ID_lineEdit->text().toInt();
    QString sql=QString("delete from student where id=%1;").arg(id);

    if(QMessageBox::question(this,"删除","确定删除",QMessageBox::Yes|QMessageBox::No)==QMessageBox::No)
    {
        ui->ID_lineEdit->clear();
        return;
    }
    if (query.exec(sql)==false)
    {
       qDebug()<<sql;
    }
    else
    {
       qDebug()<<"删除成功";
       queryTable();
    }

    ui->ID_lineEdit->clear();
}

//修改 根据ID 根据成绩
void StudentDialog::on_update_pushButton_clicked()
{
    QSqlQuery query;
    int id = ui->ID_lineEdit->text().toInt();
    double score = ui->score_lineEdit->text().toDouble();

    QString sql = QString("update student set score=%1 where id=%2;").arg(score).arg(id);

    if (query.exec(sql)==false)
    {
       qDebug()<<sql;
    }
    else
    {
       qDebug()<<"修改成功";
       queryTable();
    }

    ui->ID_lineEdit->clear();
    ui->score_lineEdit->clear();
}

//排序
void StudentDialog::on_sord_pushButton_clicked()
{
    // 获取排序列名
    QString value=ui->value_comboBox->currentText();
    // 获取排序方式
    QString condition;
    if(ui->cond_comboBox->currentIndex()==0)
    {
        condition="ASC";//升序
    }
    else
    {
        condition="DESC";//降序
    }

    QString sql=QString("select * from student order by %1 %2;").arg(value).arg(condition);
    model.setQuery(sql);
    ui->tableView->setModel(&model);

}

