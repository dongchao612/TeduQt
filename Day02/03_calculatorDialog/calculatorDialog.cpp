#include "calculatorDialog.h"
//构造函数
CalculatorDialog::CalculatorDialog()
{
	//界面初始化
    this->setupUi(this);
	
	//设置数字验证器 只能输入数字形式内容
	m_editX->setValidator(new QDoubleValidator(this));
	
    //设置数字验证器 只能输入数字形式内容
	m_editY->setValidator(new QDoubleValidator(this));

	
	//信号和槽函数连接
    //左右操作数文本改变时 发送信号textChanged
    QObject::connect(m_editX,SIGNAL(textChanged(QString)),this,SLOT(enableButton()));
    QObject::connect(m_editY,SIGNAL(textChanged(QString)),this,SLOT(enableButton()));

    //点击按钮 发射信号
    QObject::connect(m_button,SIGNAL(clicked()),this,SLOT(calcClicked()));
}

// 使能等号按钮的槽函数
void CalculatorDialog::enableButton()
{
    bool bXOK,bYOK;

    // text() 获取输入文本
    // toDouble() QString转换为double 参数保存转换是否成功
    m_editX->text().toDouble(&bXOK);
    m_editY->text().toDouble(&bYOK);

    // 当左右操作数都输入了有效的数据 则使能等号按钮 否则设置禁用
    m_button->setEnabled(bXOK&&bYOK);

}

//计算结果和显示的槽函数
void CalculatorDialog::calcClicked()
{
    double res=m_editX->text().toDouble()+m_editY->text().toDouble();

    // number() 将double 转换为 QString
    QString str=QString::number(res);

    //显示字符串形式结果
    m_editZ->setText(str);

}
