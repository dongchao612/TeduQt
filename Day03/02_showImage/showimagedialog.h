#ifndef SHOWIMAGEDIALOG_H
#define SHOWIMAGEDIALOG_H

#include <QDialog>
#include <QPainter>//  画家类
#include <QImage>
#include<QDebug>
#define MAX_OF_IMAGES 46
#define MIN_OF_IMAGES 1
QT_BEGIN_NAMESPACE
namespace Ui
{
    class ShowImageDialog;
}
QT_END_NAMESPACE

class ShowImageDialog : public QDialog
{
    Q_OBJECT

public:
    ShowImageDialog(QWidget *parent = nullptr);
    ~ShowImageDialog();

private:
    // 绘图事件处理函数（虚函数）
    void paintEvent(QPaintEvent *e);

private slots:
    void on_pushButton_prev_clicked();

    void on_pushButton_next_clicked();

private:
    Ui::ShowImageDialog *ui;
    int m_index;
    QString m_image_url;

};
#endif // SHOWIMAGEDIALOG_H
