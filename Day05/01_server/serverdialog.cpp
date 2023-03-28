#include "serverdialog.h"
#include "ui_serverdialog.h"

ServerDialog::ServerDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ServerDialog)
{
    ui->setupUi(this);

    //当有客户端向服务器发送连接请求
    connect(&tcpServer,SIGNAL(newConnection()),this,SLOT(onNewConnection()));
    connect(&timer,SIGNAL(timeout()),this,SLOT(onTimeout()));
}

ServerDialog::~ServerDialog()
{
    delete ui;
}

//创建服务器按钮对应的槽函数
void ServerDialog::on_createButton_clicked()
{
    //获取服务器端口
    port=ui->portEdit->text().toShort();

    //设置服务器IP和端口
    if(tcpServer.listen(QHostAddress::Any, port)==true)
    {
        qDebug()<<"创建服务器成功!";
        qDebug()<<"此时在线客户端人数为："<<tcpClientList.size();
        //禁用 创建服务器按钮和输入端口
        ui->createButton->setEnabled(false);
        ui->portEdit->setEnabled(false);

        //开始定时器
        timer.start(TIMER);
    }
    else
    {
        qDebug()<<"创建服务器失败!";
    }
}

// 响应客户端连接请求的槽函数
void ServerDialog::onNewConnection()
{
    //建立TCP连接
    QTcpSocket *tcpClient = tcpServer.nextPendingConnection();

    //保存套接字到容器
    tcpClientList.append(tcpClient);
    qDebug()<<"上线了一个客户端，此时在线客户端人数为："<<tcpClientList.size();

     // 当客户端向服务器发送信息时 通信套接字发送信号
     connect(tcpClient, SIGNAL(readyRead()), this,SLOT(onReadyRead()));
}

//接收客户端消息的槽函数
void ServerDialog::onReadyRead()
{
    //遍历容器 是哪个客户端给服务器发送了信息
    for (int i=0; i<tcpClientList.size();i++ ) {
        //bytesAvailable 获取当前套接字等待读取信息的字节数
        // =0 没消息
        // >0 有消息
        if(tcpClientList.at(i)->bytesAvailable())
        {
            //读取消息并保存
            QByteArray buf=tcpClientList.at(i)->readAll();

            //显示聊天消息
            ui->listWidget->addItem(buf);
            ui->listWidget->scrollToBottom();

            //转发消息到所有在线客户端
            sendMessage(buf);
        }
    }
}

//转发聊天信息给客户端
void ServerDialog::sendMessage(const QByteArray &buf)
{
    for (int i=0; i<tcpClientList.size();i++ ) {
        tcpClientList.at(i)->write(buf);
    }
}


void ServerDialog::on_closeButton_clicked()
{
    tcpServer.close();

    //启用 创建服务器按钮和输入端口
    ui->createButton->setEnabled(true);
    ui->portEdit->setEnabled(true);

    timer.stop();
    qDebug()<<"关闭服务器!";
}

void ServerDialog::onTimeout()
{
    //遍历检查容器中保存的客户端通信套接字是否断开连接
    for (int i=0; i<tcpClientList.size();i++ ) {

        if(tcpClientList.at(i)->state()==QAbstractSocket::UnconnectedState)
        {

            tcpClientList.removeAt(i);
            i--;
            qDebug()<<"发现离线客户端，此时在线客户端人数为："<<tcpClientList.size();
        }
    }

    //
}

