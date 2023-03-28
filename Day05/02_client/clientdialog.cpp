#include "clientdialog.h"
#include "ui_clientdialog.h"

ClientDialog::ClientDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ClientDialog)
{
    ui->setupUi(this);
    status=false;
    connect(&tcpSocket,SIGNAL(connected()),this,SLOT(onConnect()));
    connect(&tcpSocket,SIGNAL(disconnected()),this,SLOT(onDisconnect()));
    connect(&tcpSocket,SIGNAL(readyRead()),this,SLOT(onReadyRead()));
    connect(&tcpSocket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(onError()));
}

ClientDialog::~ClientDialog()
{
    delete ui;
}

//发送按钮对应槽函数
void ClientDialog::on_send_pushButton_clicked()
{
    //获取消息
    QString msg=ui->message_lineEdit->text();
    if(msg=="")
    {
        return;
    }

    msg=username+":"+msg;


    tcpSocket.write(msg.toUtf8());

    //清空消息框
    ui->message_lineEdit->clear();


}

//连接按钮对应槽函数
void ClientDialog::on_connect_pushButton_clicked()
{
    //如果当前状态是离线状态 则建立和服务器的连接
    if(status==false)
    {
        // 获取服务器IP
        serverIP.setAddress(ui->server_ip_lineEdit->text());
        // 获取服务器端口
        serverPort=ui->server_port_lineEdit->text().toUShort();
        // 获取服务器昵称
        username=ui->server_username_lineEdit->text();

        //连接服务器
        // 成功 发送信号  connect
        // 失败 发送信号  error
        tcpSocket.connectToHost(QHostAddress(serverIP),serverPort);

    }
    //如果是在线状态 则断开和服务器的连接
    else
    {
        //向服务器发送离开聊天室的提示消息
        QString msg=username+"：离开了聊天室";
        tcpSocket.write(msg.toUtf8());

        //关闭和服务器的连接 发送信号disconnected
        tcpSocket.disconnectFromHost();
    }

}

//和服务器连接成功时执行的槽函数
void ClientDialog::onConnect()
{
    status=true;//在线
    ui->send_pushButton->setEnabled(true); //恢复按钮状态
    ui->server_ip_lineEdit->setEnabled(false); //禁用ip
    ui->server_port_lineEdit->setEnabled(false);//禁用端口
    ui->server_username_lineEdit->setEnabled(false);//禁用昵称
    ui->connect_pushButton->setText("离开聊天室");

    //进入聊天室的提示消息
    QString msg=username+"：进入了聊天室";
    // toUtf8 QString转换QByteArray
    tcpSocket.write(msg.toUtf8());

}


//和服务器断开连接时执行的槽函数
 void ClientDialog::onDisconnect()
{
     status=false ;//在线
     ui->send_pushButton->setEnabled(false); //恢复按钮状态
     ui->server_ip_lineEdit->setEnabled(true); //禁用ip
     ui->server_port_lineEdit->setEnabled(true);//禁用端口
     ui->server_username_lineEdit->setEnabled(true);//禁用昵称
     ui->connect_pushButton->setText("进入聊天室");
}

//接收聊天消息的套接字
void ClientDialog::onReadyRead()
{
    // qDebug()<<"onReadyRead";

    if(tcpSocket.bytesAvailable())
    {
        // 接收消息
        QByteArray buf=tcpSocket.readAll();
        //显示消息
        ui->listWidget->addItem(buf);
        ui->listWidget->scrollToBottom();

    }
}

//网络异常
void ClientDialog::onError()
{
    QMessageBox::critical(this,"ERROR!",tcpSocket.errorString());
}

