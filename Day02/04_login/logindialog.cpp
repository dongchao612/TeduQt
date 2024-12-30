#include "logindialog.h"
#include "./ui_logindialog.h"

LoginDialog::LoginDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("登录");
    setFixedSize(430, 300);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

// 假设这个函数用于验证用户的凭据，这里仅作为示例实现。
bool LoginDialog::validateUser(const QString &username, const QString &password)
{
    // 在实际应用中，不要硬编码用户名和密码。
    // 应该查询数据库或调用外部认证服务来验证凭据。
    return username == "root" && password == "admin";
}

void LoginDialog::clearInputs()
{
    ui->lineEdit_username->clear();
    ui->lineEdit_passwd->clear();
}

void LoginDialog::on_buttonBox_accepted()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_passwd->text();

    if(validateUser(username, password))
    {
        qDebug() << tr("登录成功");
        accept(); // 使用accept()表示对话框被接受
    }
    else
    {
        QMessageBox::StandardButton result;
        if (username.isEmpty())
        {
            result = QMessageBox::critical(this, tr("错误"), tr("请输入用户名"));
        }
        else if (password.isEmpty())
        {
            result = QMessageBox::critical(this, tr("错误"), tr("请输入密码"));
        }
        else
        {
            result = QMessageBox::critical(this, tr("错误"), tr("用户名或密码错误"));
        }

        clearInputs(); // 清除输入框内容
    }
}


void LoginDialog::on_buttonBox_rejected()
{
    QMessageBox::StandardButton result = QMessageBox::question(
            this,
            tr("登录"),
            tr("是否取消登录？"),
            QMessageBox::Yes | QMessageBox::No
                                         );

    if(result == QMessageBox::Yes)
    {
        clearInputs();
        reject(); // 使用reject()表示对话框被拒绝
    }

}

