#ifndef CALCULATORDIALOG_H
#define CALCULATORDIALOG_H

#include <QDialog>
#include <QDoubleValidator>	//验证器
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
    // 使能等号按钮的槽函数
    void enableButton();

    //计算结果和显示的槽函数
    void calcClicked();

private:
    Ui::CalculatorDialog *ui;
};
#endif // CALCULATORDIALOG_H
