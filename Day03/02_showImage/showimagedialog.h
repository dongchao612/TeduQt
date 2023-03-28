#ifndef SHOWIMAGEDIALOG_H
#define SHOWIMAGEDIALOG_H

#include <QDialog>
#include <QPainter> //画家类
#include <QImage> //图片
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class ShowImageDialog; }
QT_END_NAMESPACE

class ShowImageDialog : public QDialog
{
    Q_OBJECT

public:
    ShowImageDialog(QWidget *parent = nullptr);
    ~ShowImageDialog();

private slots:
    // 上一张对应的槽函数
    void on_m_btnPre_clicked();
    // 下一张对应的槽函数
    void on_m_btnNext_clicked();
private:
    void paintEvent(QPaintEvent *event);
private:
    Ui::ShowImageDialog *ui;
    int m_index; //图片索引
};
#endif // SHOWIMAGEDIALOG_H
