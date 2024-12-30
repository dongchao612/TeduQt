#include "calculatordialog.h"
#include "./ui_calculatordialog.h"

CalculatorDialog::CalculatorDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CalculatorDialog)
{
    ui->setupUi(this);
    //界面初始化
    this->setWindowTitle("计算器"); //设置窗口标题

    //左操作数 this即为当前父窗口指针
    m_editX = new QLineEdit(this);
    //设置文本对齐 右对齐
    m_editX->setAlignment(Qt::AlignRight);
    //设置数字验证器 只能输入数字形式内容
    m_editX->setValidator(new QDoubleValidator(this));

    //右操作数
    m_editY = new QLineEdit(this);
    m_editY->setAlignment(Qt::AlignRight);
    m_editY->setValidator(new QDoubleValidator(this));

    //显示结果
    m_editZ = new QLineEdit(this);
    m_editZ->setAlignment(Qt::AlignRight);
    m_editZ->setReadOnly(true); //设置只读

    // "+"
    m_label = new QLabel("+", this);

    // "="
    m_button = new QPushButton("=", this);
    m_button->setEnabled(false);//设置禁用

    //创建布局期 自动调用每个空间的大小和位置
    QHBoxLayout *layout = new QHBoxLayout(this);

    //按照水平方向布局 依次将控件添加到布局器中
    layout->addWidget(m_editX);
    layout->addWidget(m_label);
    layout->addWidget(m_editY);
    layout->addWidget(m_button);
    layout->addWidget(m_editZ);

    //设置布局器
    this->setLayout(layout);


    //信号和槽函数连接
    //左右操作数文本改变时 发送信号textChanged
    QObject::connect(m_editX, SIGNAL(textChanged(QString)), this, SLOT(enableButton()));
    QObject::connect(m_editY, SIGNAL(textChanged(QString)), this, SLOT(enableButton()));

    //点击按钮 发射信号
    QObject::connect(m_button, SIGNAL(clicked()), this, SLOT(calcClicked()));
}

// 使能等号按钮的槽函数
void CalculatorDialog::enableButton()
{
    bool bXOK, bYOK;
    // qDebug() << __FUNCTION__;
    // text() 获取输入文本
    // toDouble() QString转换为double 参数保存转换是否成功
    m_editX->text().toDouble(&bXOK);
    m_editY->text().toDouble(&bYOK);

    // 当左右操作数都输入了有效的数据 则使能等号按钮 否则设置禁用
    m_button->setEnabled(bXOK && bYOK);
    m_editZ->clear();

}
CalculatorDialog::~CalculatorDialog()
{
    delete ui;
}

//计算结果和显示的槽函数
void CalculatorDialog::calcClicked()
{
    double res = m_editX->text().toDouble() + m_editY->text().toDouble();
    qDebug() << res;
    // number() 将double 转换为 QString
    QString str = QString::number(res);

    //显示字符串形式结果
    m_editZ->setText(str);

}
