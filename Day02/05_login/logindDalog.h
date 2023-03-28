#ifndef LOGINDDALOG_H
#define LOGINDDALOG_H

#include <QDialog>
#include "ui_LoginDialog.h"
#include <QMessageBox>
#include <QDebug>

class LoginDialog : public QDialog,public Ui::LoginDialog
{
    Q_OBJECT
public:
    LoginDialog();
    ~LoginDialog();
public slots:
    //处理Ok按钮的槽函数
    void onAccepted();

    //处理Cancel按钮的槽函数
    void onRejected();
signals:

};

#endif // LOGINDDALOG_H
