#include "showimagedialog.h"
#include "ui_showimagedialog.h"

ShowImageDialog::ShowImageDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ShowImageDialog)
{
    ui->setupUi(this);
    m_index=1;
}

ShowImageDialog::~ShowImageDialog()
{
    delete ui;
}

// 上一张对应的槽函数
void ShowImageDialog::on_m_btnPre_clicked()
{
    m_index--;
    if(m_index==0)
    {
       m_index=46;
    }
    update();
}

// 下一张对应的槽函数
void ShowImageDialog::on_m_btnNext_clicked()
{
    m_index++;
    if(m_index==47)
    {
       m_index=1;
    }
    update();
}

void ShowImageDialog::paintEvent(QPaintEvent *event)
{
    qDebug()<<"paintEvent"<<m_index;
    // 1、创建画家对象
    QPainter painter(this);

    // 2、获取绘图所在的矩形区域
    QRect rect=ui->frame->frameRect();
    // qDebug()<<"平移前："<<rect;
    //坐标值平移 让rect和painter使用相同的坐标系
    rect.translate(ui->frame->pos());
    // qDebug()<<"平移后："<<rect;

    // 3、构建绘制图形对象
    QImage image(":/images/shime"+QString::number(m_index)+".png");


    // 4、使用painter将image图片画到rect
    painter.drawImage(rect,image);


}

