#include "keyboarddialog.h"
#include "ui_keyboarddialog.h"

KeyBoardDialog::KeyBoardDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::KeyBoardDialog)
{
    ui->setupUi(this);
}

KeyBoardDialog::~KeyBoardDialog()
{
    delete ui;
}

void KeyBoardDialog::keyPressEvent(QKeyEvent *e)
{
    int x=ui->label->pos().x();
    int y=ui->label->pos().y();

    if((e->key()==Qt::Key_Up)||(e->key()==Qt::Key_W))
    {
        ui->label->move(x,y-STEP);
    }
    else if((e->key()==Qt::Key_Down)||(e->key()==Qt::Key_S))
    {
        ui->label->move(x,y+STEP);
    }
    else if((e->key()==Qt::Key_Left)||(e->key()==Qt::Key_A))
    {
        ui->label->move(x-STEP,y);
    }
    else if((e->key()==Qt::Key_Right)||(e->key()==Qt::Key_D))
    {
        ui->label->move(x+STEP,y);
    }
}

