#include "erniedialog.h"
#include "ui_erniedialog.h"

ErnieDialog::ErnieDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ErnieDialog)
{
    ui->setupUi(this);
    m_index=1;
    isStart=false;
    //设置随机数种子
    qsrand(QTime::currentTime().msec());

    loadPhotos("./images");
    // qDebug()<<"加载图片个数："<<m_vecPhotos.size();
}

ErnieDialog::~ErnieDialog()
{
    delete ui;
}
// 加载图片容器功能
void ErnieDialog::loadPhotos(const QString &path)
{
    QDir dir(path);
    //遍历当前目录所有图片
    QStringList list1=dir.entryList(QDir::Files);

    for (int i=0;i<list1.size() ; i++) {
        // qDebug()<<list1.at(i);
        QImage image(path+"/"+list1.at(i));
        m_vecPhotos<<image;
    }
    //遍历子目录
    QStringList list2=dir.entryList(QDir::Dirs|QDir::NoDotAndDotDot);

    for (int  i=0;i<list2.size() ;i++ ) {
        loadPhotos(path+"/"+list2.at(i));
    }

}
// 定时器事件处理函数
void ErnieDialog::timerEvent(QTimerEvent *e)
{
    if(e->timerId()!=m_timerId)
    {
           return ;
    }

    m_index=qrand() %(m_vecPhotos.size());
    update();
}
// 绘图事件处理函数
void ErnieDialog::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    QRect rect=ui->frame->frameRect();
    rect.translate(ui->frame->pos());
    // qDebug()<<m_index;
    painter.drawImage(rect,m_vecPhotos.at(m_index));


}



void ErnieDialog::on_m_pushBtn_clicked()
{
    // qDebug()<<"on_m_pushBtn_clicked"<<isStart;
    if(isStart==false)
    {
        isStart=true;//开始摇奖
        m_timerId=startTimer(50);
        ui->m_pushBtn->setText("停止");
    }
    else if(isStart==true)
    {
        isStart=false;//停止摇奖
        killTimer(m_timerId);
         ui->m_pushBtn->setText("开始");
    }

}

