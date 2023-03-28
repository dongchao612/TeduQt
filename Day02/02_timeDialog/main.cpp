#include <QApplication>
#include "timeDialog.h"

int main(int argc,char** argv)
{
    //创建QT应用程序对象
    QApplication app(argc,argv);
    TimeDialog t;
    t.show();
    return app.exec();
}