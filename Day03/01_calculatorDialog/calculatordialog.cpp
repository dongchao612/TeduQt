#include "calculatordialog.h"
#include "./ui_calculatordialog.h"

CalculatorDialog::CalculatorDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CalculatorDialog)
{
    ui->setupUi(this);
    //设置数字验证器 只能输入数字形式内容
    ui->lineEdit_left->setValidator(new QDoubleValidator(this));

    //设置数字验证器 只能输入数字形式内容
    ui->lineEdit_right->setValidator(new QDoubleValidator(this));


    //信号和槽函数连接
    //左右操作数文本改变时 发送信号textChanged
    QObject::connect(ui->lineEdit_left, SIGNAL(textChanged(QString)), this, SLOT(enableButton()));
    QObject::connect(ui->lineEdit_right, SIGNAL(textChanged(QString)), this, SLOT(enableButton()));


}

void CalculatorDialog::enableButton()
{
    bool bXOK, bYOK;

    // text() 获取输入文本
    // toDouble() QString转换为double 参数保存转换是否成功
    ui->lineEdit_left->text().toDouble(&bXOK);
    ui->lineEdit_right->text().toDouble(&bYOK);

    // 当左右操作数都输入了有效的数据 则使能等号按钮 否则设置禁用
    ui->pushButton_equ->setEnabled(bXOK && bYOK);
    ui->lineEdit_result->clear();

}

CalculatorDialog::~CalculatorDialog()
{
    delete ui;
}

void CalculatorDialog::on_pushButton_equ_clicked()
{
    double res = ui->lineEdit_left->text().toDouble() + ui->lineEdit_right->text().toDouble();

    // number() 将double 转换为 QString
    QString str = QString::number(res);

    //显示字符串形式结果
    ui->lineEdit_result->setText(str);

}

