#ifndef TIMEDIALOG_H
#define TIMEDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>  //垂直布局器
#include <QTime>        //时间
#include <QDebug>       //打印
#include <QFONT>
QT_BEGIN_NAMESPACE
namespace Ui
{
    class TimeDialog;
}
QT_END_NAMESPACE

class TimeDialog : public QDialog
{
    Q_OBJECT

public:
    TimeDialog(QWidget *parent = nullptr);
    ~TimeDialog();
public slots:
    void getTime();
signals:
    //自定义信号函数 只需声明 不能写定义
    void mySignal(QString str);
private:
    Ui::TimeDialog *ui;
    QLabel *m_label;        //显示时间label
    QPushButton *m_button;  //获取时间 button
};
#endif // TIMEDIALOG_H
