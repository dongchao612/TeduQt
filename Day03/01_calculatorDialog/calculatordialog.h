#ifndef CALCULATORDIALOG_H
#define CALCULATORDIALOG_H

#include <QDialog>
#include <QDoubleValidator>

QT_BEGIN_NAMESPACE
// 短视声明  #include "ui_calculatordialog.h"
namespace Ui { class CalculatorDialog; }
QT_END_NAMESPACE

class CalculatorDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CalculatorDialog(QWidget *parent = nullptr);
    ~CalculatorDialog();  //虚析构函数
public slots:
    // 使能等号按钮的槽函数
    void enableButton();

    //计算结果和显示的槽函数
    void calcClicked();
private:
    Ui::CalculatorDialog *ui;
};
#endif // CALCULATORDIALOG_H
