#include <QApplication>
#include "logindDalog.h"

int main(int argc,char** argv)
{
    //创建QT应用程序对象
    QApplication app(argc,argv);
    LoginDialog l;
    l.show();
    return app.exec();
}