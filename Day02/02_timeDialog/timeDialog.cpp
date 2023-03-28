#include "timeDialog.h"
TimeDialog::TimeDialog()
{
    //初始化界面
    setMinimumSize(QSize(320, 120));


    m_label=new QLabel(this);
    //设置label边框消息 凹陷面板
    m_label->setFrameStyle(QFrame::Panel|QFrame::Sunken);
    //设置label文本对齐方式 水平/垂直居中
    m_label->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    //设置label的字体
    m_label->setFont(QFont("宋体",20));

    //获取系统时间的按钮
    m_button=new QPushButton(this);
    //m_button->setFont(QFont("黑体",20));

    QVBoxLayout* layout=new QVBoxLayout(this);

    layout->addWidget(m_label);
    layout->addWidget(m_button);
    this->setLayout(layout);


    //信号与槽函数
    QObject::connect(m_button,SIGNAL(clicked()),this,SLOT(getTime()));

    //通过自定义信号 发出label的setText槽函数
    connect(this,SIGNAL(mySignal(QString)),m_label,SLOT(setText(QString)));
}

void TimeDialog::getTime()
{
    // qDebug()<<"getTime"<<endl;
    //获取当前时间
    QTime time;
    time=QTime::currentTime();
    //将时间转化为字符串
    QString str = time.toString("H:m:s a");
    // qDebug()<<str<<endl;

    //显示时间
    //m_label->setText(str);

    //emit 是Qt关键字 标记当前是发射信号
    // emit mySignal(str);//发射信号
    mySignal(str);
}
