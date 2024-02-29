/********************************************************************************
** Form generated from reading UI file 'listofcases.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTOFCASES_H
#define UI_LISTOFCASES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>

QT_BEGIN_NAMESPACE

class Ui_listOfCases
{
public:
    QListView *listView;
    QLabel *label;

    void setupUi(QDialog *listOfCases)
    {
        if (listOfCases->objectName().isEmpty())
            listOfCases->setObjectName("listOfCases");
        listOfCases->resize(400, 300);
        listView = new QListView(listOfCases);
        listView->setObjectName("listView");
        listView->setGeometry(QRect(60, 40, 251, 241));
        label = new QLabel(listOfCases);
        label->setObjectName("label");
        label->setGeometry(QRect(150, 10, 49, 16));

        retranslateUi(listOfCases);

        QMetaObject::connectSlotsByName(listOfCases);
    } // setupUi

    void retranslateUi(QDialog *listOfCases)
    {
        listOfCases->setWindowTitle(QCoreApplication::translate("listOfCases", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("listOfCases", "test cases", nullptr));
    } // retranslateUi

};

namespace Ui {
    class listOfCases: public Ui_listOfCases {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTOFCASES_H
