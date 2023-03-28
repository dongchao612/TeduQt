#include "calculatordialog.h"
#include "ui_calculatordialog.h"

CalculatorDialog::CalculatorDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CalculatorDialog)
{
    //界面初始化
    ui->setupUi(this);
    //设置数字验证器 只能输入数字形式内容
    ui->m_editX->setValidator(new QDoubleValidator(this));

    //设置数字验证器 只能输入数字形式内容
    ui->m_editY->setValidator(new QDoubleValidator(this));


    //信号和槽函数连接
    //左右操作数文本改变时 发送信号textChanged
    QObject::connect(ui->m_editX,SIGNAL(textChanged(QString)),this,SLOT(enableButton()));
    QObject::connect(ui->m_editY,SIGNAL(textChanged(QString)),this,SLOT(enableButton()));

    //点击按钮 发射信号
    QObject::connect(ui->m_button,SIGNAL(clicked()),this,SLOT(calcClicked()));
}

CalculatorDialog::~CalculatorDialog()
{
    delete ui;
}
// 使能等号按钮的槽函数
void CalculatorDialog::enableButton()
{
    bool bXOK,bYOK;

    // text() 获取输入文本
    // toDouble() QString转换为double 参数保存转换是否成功
    ui->m_editX->text().toDouble(&bXOK);
    ui->m_editY->text().toDouble(&bYOK);

    // 当左右操作数都输入了有效的数据 则使能等号按钮 否则设置禁用
    ui->m_button->setEnabled(bXOK&&bYOK);

}

//计算结果和显示的槽函数
void CalculatorDialog::calcClicked()
{
    double res=ui->m_editX->text().toDouble()+ui->m_editY->text().toDouble();

    // number() 将double 转换为 QString
    QString str=QString::number(res);

    //显示字符串形式结果
    ui->m_editZ->setText(str);
}
