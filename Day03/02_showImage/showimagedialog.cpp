#include "showimagedialog.h"
#include "./ui_showimagedialog.h"

ShowImageDialog::ShowImageDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ShowImageDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("图图秀");
    this->m_index = MIN_OF_IMAGES;
    this->m_image_url = "";
}

ShowImageDialog::~ShowImageDialog()
{
    delete ui;
}
// 绘图事件处理函数（虚函数）
void ShowImageDialog::paintEvent(QPaintEvent *e)
{
    // qDebug() << __func__;
    // 创建画家对象
    QPainter painter(this);
    // 获取画图区域
    QRect rect = ui->frame->rect();
    // qDebug() << "平移前：" << rect;
    //使用相同的坐标值
    rect.translate(ui->frame->pos());
    // qDebug() << "平移后：" << rect;
    // 后见要绘制的图像对象
    this -> m_image_url = ":/images/shime" + QString::number(this->m_index) + ".png";
    QImage image(this->m_image_url);

    //使用painter将image图片画到rect中

    painter.setRenderHint(QPainter::SmoothPixmapTransform);
    painter.drawImage(rect, image);
}

// 上一张按钮的槽函数
void ShowImageDialog::on_pushButton_prev_clicked()
{
    // qDebug() << this->m_image_url;
    if(--this->m_index < MIN_OF_IMAGES)
    {
        m_index = MAX_OF_IMAGES;
    }
    update();
}

// 下一张按钮的槽函数
void ShowImageDialog::on_pushButton_next_clicked()
{
    // qDebug() << this->m_image_url;
    if(++this->m_index > MAX_OF_IMAGES)
    {
        m_index = MIN_OF_IMAGES;
    }
    update();
}

