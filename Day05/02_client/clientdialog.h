#ifndef CLIENTDIALOG_H
#define CLIENTDIALOG_H

#include <QDialog>
#include <QTcpSocket>
#include <QHostAddress>
#include <QMessageBox>
#include <QDebug>


QT_BEGIN_NAMESPACE
namespace Ui { class ClientDialog; }
QT_END_NAMESPACE

class ClientDialog : public QDialog
{
    Q_OBJECT

public:
    ClientDialog(QWidget *parent = nullptr);
    ~ClientDialog();

private slots:
    //发送按钮对应槽函数
    void on_send_pushButton_clicked();

    //连接按钮对应槽函数
    void on_connect_pushButton_clicked();

    //和服务器连接成功时执行的槽函数
    void onConnect();

    //和服务器断开连接时执行的槽函数
     void onDisconnect();

    //接收聊天消息的套接字
    void onReadyRead();

    //网络异常
    void onError();

private:
    Ui::ClientDialog *ui;
    bool status;// 标志 在线/离线
    QTcpSocket tcpSocket; // 和服务器通信的套接字
    QHostAddress serverIP;//服务器地址
    quint16 serverPort;//服务器端口
    QString username;//昵称


};
#endif // CLIENTDIALOG_H
