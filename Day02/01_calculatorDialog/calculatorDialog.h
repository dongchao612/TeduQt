#ifndef CALCULATORDIALOG_H
#define CALCULATORDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>		//行编辑器
#include <QHBoxLayout>		//水平布局器
#include <QDoubleValidator>	//验证器
#include <QDebug>
QT_BEGIN_NAMESPACE
namespace Ui
{
    class CalculatorDialog;
}
QT_END_NAMESPACE

class CalculatorDialog : public QDialog
{
    Q_OBJECT

public:
    CalculatorDialog(QWidget *parent = nullptr);
    ~CalculatorDialog();
public slots:
    void calcClicked();
    void enableButton();

private:
    Ui::CalculatorDialog *ui;
    QLineEdit *m_editX; //左操作数
    QLineEdit *m_editY;	//右操作数
    QLineEdit *m_editZ;	//显示结果


    QLabel *m_label; // "+"

    QPushButton *m_button;// "="
};
#endif // CALCULATORDIALOG_H
