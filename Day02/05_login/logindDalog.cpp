#include "logindDalog.h"

//构造函数
LoginDialog::LoginDialog()
{
    //初始化界面
    setupUi(this);

    //信号与槽的连接
    //点击OK发送信号accepted
    connect(m_buttonBox,SIGNAL(accepted()),this,SLOT(onAccepted()));
    //点击Cancel发送信号rejected
    connect(m_buttonBox,SIGNAL(rejected()),this,SLOT(onRejected()));
}

LoginDialog::~LoginDialog()
{

}

void LoginDialog::onAccepted()
{
    if(m_nameEdit->text()=="username"&&m_passwdEdit->text()=="123")
    {
        qDebug()<<"登录成功"<<endl;
        this->close();
    }
    else
    {
        QMessageBox msgBox(QMessageBox::Critical,// 图标
                           "ERROR","用户名或者密码错误",//提示消息
                           QMessageBox::Ok,//按钮
                           this);//父窗口
        msgBox.exec();//显示消息提示框 并进入事件循环
    }
}

void LoginDialog::onRejected()
{
    QMessageBox msgBox(QMessageBox::Question,
                       "登录",
                       "是否取消登录:",
                       QMessageBox::Yes|QMessageBox::No,
                       this);
    //显示消息提示框 并进入事件循环
    if(msgBox.exec()==QMessageBox::Yes)
    {
        this->close();
    }
}
