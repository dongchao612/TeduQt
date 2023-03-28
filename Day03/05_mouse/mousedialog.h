#ifndef MOUSEDIALOG_H
#define MOUSEDIALOG_H

#include <QDialog>
#include <QMouseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MouseDialog; }
QT_END_NAMESPACE

class MouseDialog : public QDialog
{
    Q_OBJECT

public:
    MouseDialog(QWidget *parent = nullptr);
    ~MouseDialog();
    // 按下
    void mousePressEvent(QMouseEvent * e);
    // 释放
    void mouseReleaseEvent(QMouseEvent * e);
    // 移动
    void mouseMoveEvent(QMouseEvent * e);


private:
    Ui::MouseDialog *ui;
    bool m_drag;
    QPoint m_pos;  // QRext(x,y,w,h) QPoint(x,y) QSize(w,h)

};
#endif // MOUSEDIALOG_H
