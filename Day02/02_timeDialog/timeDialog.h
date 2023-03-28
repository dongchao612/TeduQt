#ifndef	TIMEDIALOG_H
#define	TIMEDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>  //垂直布局器
#include <QTime>        //时间
#include <QDebug>       //打印
#include <QFont>

class TimeDialog:public QDialog{
    Q_OBJECT //moc
public:
    TimeDialog();
public slots:
    void getTime();
private:
    QLabel* m_label;        //显示时间label
    QPushButton* m_button;  //获取时间 button
signals:
    //自定义信号函数 只需声明 不能写定义
    void mySignal(QString str);
};

#endif //TIMEDIALOG_H