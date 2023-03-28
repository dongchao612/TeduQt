#ifndef KEYBOARDDIALOG_H
#define KEYBOARDDIALOG_H

#include <QDialog>
#include <QKeyEvent>

#define STEP 10

QT_BEGIN_NAMESPACE
namespace Ui { class KeyBoardDialog; }
QT_END_NAMESPACE

class KeyBoardDialog : public QDialog
{
    Q_OBJECT

public:
    KeyBoardDialog(QWidget *parent = nullptr);
    ~KeyBoardDialog();
    // 按下
    void keyPressEvent(QKeyEvent *e);

private:
    Ui::KeyBoardDialog *ui;
};
#endif // KEYBOARDDIALOG_H
