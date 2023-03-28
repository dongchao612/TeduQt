/********************************************************************************
** Form generated from reading UI file 'CalculatorDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCULATORDIALOG_H
#define UI_CALCULATORDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_CalculatorDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QLineEdit *m_editX;
    QSpacerItem *horizontalSpacer;
    QLabel *m_label;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *m_editY;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *m_button;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *m_editZ;

    void setupUi(QDialog *CalculatorDialog)
    {
        if (CalculatorDialog->objectName().isEmpty())
            CalculatorDialog->setObjectName(QString::fromUtf8("CalculatorDialog"));
        CalculatorDialog->resize(800, 300);
        QFont font;
        font.setFamily(QString::fromUtf8("Adobe \345\256\213\344\275\223 Std L"));
        font.setPointSize(20);
        CalculatorDialog->setFont(font);
        horizontalLayout = new QHBoxLayout(CalculatorDialog);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        m_editX = new QLineEdit(CalculatorDialog);
        m_editX->setObjectName(QString::fromUtf8("m_editX"));
        m_editX->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(m_editX);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        m_label = new QLabel(CalculatorDialog);
        m_label->setObjectName(QString::fromUtf8("m_label"));
        m_label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(m_label);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        m_editY = new QLineEdit(CalculatorDialog);
        m_editY->setObjectName(QString::fromUtf8("m_editY"));
        m_editY->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(m_editY);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        m_button = new QPushButton(CalculatorDialog);
        m_button->setObjectName(QString::fromUtf8("m_button"));
        m_button->setEnabled(false);

        horizontalLayout->addWidget(m_button);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        m_editZ = new QLineEdit(CalculatorDialog);
        m_editZ->setObjectName(QString::fromUtf8("m_editZ"));
        m_editZ->setAlignment(Qt::AlignCenter);
        m_editZ->setReadOnly(true);

        horizontalLayout->addWidget(m_editZ);


        retranslateUi(CalculatorDialog);

        QMetaObject::connectSlotsByName(CalculatorDialog);
    } // setupUi

    void retranslateUi(QDialog *CalculatorDialog)
    {
        CalculatorDialog->setWindowTitle(QApplication::translate("CalculatorDialog", "\350\256\241\347\256\227\345\231\250", nullptr));
        m_label->setText(QApplication::translate("CalculatorDialog", "+", nullptr));
        m_button->setText(QApplication::translate("CalculatorDialog", "=", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CalculatorDialog: public Ui_CalculatorDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULATORDIALOG_H
