#include "calculatordialog.h"
#include "./ui_calculatordialog.h"

CalculatorDialog::CalculatorDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CalculatorDialog)
{
    ui->setupUi(this);
    ui->lineEditX->setValidator(new QDoubleValidator(this));
    ui->lineEditY->setValidator(new QDoubleValidator(this));

    //左右操作数文本改变时 发送信号textChanged
    QObject::connect(ui->lineEditX, SIGNAL(textChanged(QString)), this, SLOT(enableButton()));
    QObject::connect(ui->lineEditY, SIGNAL(textChanged(QString)), this, SLOT(enableButton()));

    //点击按钮 发射信号
    QObject::connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(calcClicked()));

}

CalculatorDialog::~CalculatorDialog()
{
    delete ui;
}

// 使能等号按钮的槽函数
void CalculatorDialog::enableButton()
{
    bool bXOK, bYOK;

    // text() 获取输入文本
    // toDouble() QString转换为double 参数保存转换是否成功
    ui->lineEditX->text().toDouble(&bXOK);
    ui->lineEditY->text().toDouble(&bYOK);

    // 当左右操作数都输入了有效的数据 则使能等号按钮 否则设置禁用
    ui->pushButton->setEnabled(bXOK && bYOK);
    ui->lineEditZ->clear();

}

//计算结果和显示的槽函数
void CalculatorDialog::calcClicked()
{
    double res = ui->lineEditX->text().toDouble() + ui->lineEditY->text().toDouble();

    // number() 将double 转换为 QString
    QString str = QString::number(res);

    //显示字符串形式结果
    ui->lineEditZ->setText(str);

}
