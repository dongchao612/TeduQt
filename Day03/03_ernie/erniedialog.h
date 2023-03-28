#ifndef ERNIEDIALOG_H
#define ERNIEDIALOG_H

#include <QDialog>
#include <QDebug>
#include <QDir>
#include <QPainter>
#include <QTimer>
#include <QTime>
#include <QVector>
#include <QImage>

QT_BEGIN_NAMESPACE
namespace Ui { class ErnieDialog; }
QT_END_NAMESPACE

class ErnieDialog : public QDialog
{
    Q_OBJECT

public:
    ErnieDialog(QWidget *parent = nullptr);
    ~ErnieDialog();
private:
    // 加载图片容器功能
    void loadPhotos(const QString &path);
    // 定时器事件处理函数
    void timerEvent(QTimerEvent* e);
    // 绘图事件处理函数
    void paintEvent(QPaintEvent* e);

private slots:
    void on_m_pushBtn_clicked();

private:
    Ui::ErnieDialog *ui;
    int m_timerId;// 定时器Id
    int m_index; // 图片在容器的索引
    QVector<QImage> m_vecPhotos; //保存图片的容器
    bool isStart ;//标记 true 正在摇奖 false 停止摇奖
};
#endif // ERNIEDIALOG_H
