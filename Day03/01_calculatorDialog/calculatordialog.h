#ifndef CALCULATORDIALOG_H
#define CALCULATORDIALOG_H

#include <QDialog>
#include <QDoubleValidator>
QT_BEGIN_NAMESPACE
namespace Ui
{
    class CalculatorDialog; // 短视声明
}
QT_END_NAMESPACE

class CalculatorDialog : public QDialog
{
    Q_OBJECT

public:
    CalculatorDialog(QWidget *parent = nullptr);
    ~CalculatorDialog();

private slots:
    void on_pushButton_equ_clicked();
    void enableButton();

private:
    Ui::CalculatorDialog *ui;
};
#endif // CALCULATORDIALOG_H
