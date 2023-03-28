#include <QApplication>
#include "calculatorDialog.h"

int main(int argc,char** argv)
{
    //创建QT应用程序对象
    QApplication app(argc,argv);
    CalculatorDialog c;
    c.show();
    return app.exec();
}