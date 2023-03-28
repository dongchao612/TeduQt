#include "mousedialog.h"
#include "ui_mousedialog.h"

MouseDialog::MouseDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MouseDialog)
{
    ui->setupUi(this);
    m_drag=false;
}

MouseDialog::~MouseDialog()
{
    delete ui;
}
// 按下
void MouseDialog::mousePressEvent(QMouseEvent *e)
{
    // 是否鼠标左键
    if(e->button()==Qt::LeftButton)
    {
        // 获取label所在举行区域
        QRect rect=ui->label->frameRect();
        //坐标平移
        rect.translate(ui->label->pos());
        //判断鼠标点击位置是否在label位置中
        if(rect.contains(e->pos()))
        {
            m_drag=true;
            m_pos=ui->label->pos()-e->pos();
        }
    }
}
// 释放
void MouseDialog::mouseReleaseEvent(QMouseEvent *e)
{
    if(e->button()==Qt::LeftButton)
    {
        m_drag=false;
    }
}
// 移动
void MouseDialog::mouseMoveEvent(QMouseEvent *e)
{
    if(m_drag==true)
    {
        //计算label要移动的新位置
        QPoint newpos=e->pos()+m_pos;

        //
        QSize s1=this->size(); //父窗口大小
        QSize s2=ui->label->size();// 获取label大小

        if(newpos.x()<0)
        {
            newpos.setX(0);
        }
        else if(newpos.x()>s1.width()-s2.width())
        {
            newpos.setX(s1.width()-s2.width());
        }

        if(newpos.y()<0)
        {
            newpos.setY(0);
        }
        else if(newpos.y()>s1.height()-s2.height())
        {
            newpos.setY(s1.height()-s2.height());
        }


        // 移动label到新的位置
        ui->label->move(newpos);

    }
}

