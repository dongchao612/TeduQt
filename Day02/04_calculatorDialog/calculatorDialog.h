#ifndef	CALCULATORDIALOG_H
#define	CALCULATORDIALOG_H

#include "ui_CalculatorDialog.h"
#include <QDoubleValidator>
// 继承方法
class CalculatorDialog:public QDialog{
    Q_OBJECT //moc
public:
    CalculatorDialog();
    ~CalculatorDialog();
public slots:
	// 使能等号按钮的槽函数
    void enableButton();
	
	//计算结果和显示的槽函数
	void calcClicked();
private:
    //通过"ui->"访问和界面相关的代码
    Ui::CalculatorDialog* ui;
};
#endif //CALCULATORDIALOG_H