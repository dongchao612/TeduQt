#ifndef SERVERDIALOG_H
#define SERVERDIALOG_H

#include <QDialog>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <QTimer>

#define TIMER 3000

QT_BEGIN_NAMESPACE
namespace Ui { class ServerDialog; }
QT_END_NAMESPACE

class ServerDialog : public QDialog
{
    Q_OBJECT

public:
    ServerDialog(QWidget *parent = nullptr);
    ~ServerDialog();

private slots:
    //创建服务器按钮对应的槽函数
    void on_createButton_clicked();

    // 响应客户端连接请求的槽函数
    void onNewConnection();

    //接收客户端消息的槽函数
    void onReadyRead();

    //转发聊天信息给客户端
    void sendMessage(const QByteArray& buf);

    void on_closeButton_clicked();

    //定时器到时后执行的槽函数
    void onTimeout();

private:
    Ui::ServerDialog *ui;
    QTcpServer tcpServer;
    quint16 port ; //服务器端口 unsigned short
    QList<QTcpSocket*> tcpClientList;//列表容器 保存所有和客户端通信的套接字
    QTimer timer; //定时器
};
#endif // SERVERDIALOG_H
