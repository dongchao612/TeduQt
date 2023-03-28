#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QDialog>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    QDialog parent;//父窗口
    parent.resize(320, 240);


    QLabel label("我是标签", &parent);
    label.move(50, 40);

    QPushButton button("我是按钮", &parent);
    button.move(50, 140);

    // 点击按钮，关闭标签
    QObject::connect(&button,SIGNAL(clicked()),&label,SLOT(close()));


    //增加退出按钮，实现点击按钮退出应用程序
    QPushButton button2("退出", &parent);
    button2.move(200, 140);

    QObject::connect(&button2, SIGNAL(clicked()),
                     // &app,SLOT(closeAllWindows())
                     // &app,SLOT(quit())
                     &parent, SLOT(close())
                    );




    parent.show();//父窗口显示 上面停靠的控件也将一起显示
    return app.exec();

}