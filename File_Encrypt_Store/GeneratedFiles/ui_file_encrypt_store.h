/********************************************************************************
** Form generated from reading UI file 'file_encrypt_store.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILE_ENCRYPT_STORE_H
#define UI_FILE_ENCRYPT_STORE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_File_Encrypt_StoreClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLineEdit *file_path_lineEdit;
    QPushButton *browse_button;
    QLabel *label_2;
    QLineEdit *key_name_lineEdit;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *encrypt_button;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_4;
    QTableWidget *cipher_key_tablewidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QTableWidget *cipher_text_tablewidget;

    void setupUi(QMainWindow *File_Encrypt_StoreClass)
    {
        if (File_Encrypt_StoreClass->objectName().isEmpty())
            File_Encrypt_StoreClass->setObjectName(QString::fromUtf8("File_Encrypt_StoreClass"));
        File_Encrypt_StoreClass->resize(600, 400);
        centralWidget = new QWidget(File_Encrypt_StoreClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout_4 = new QHBoxLayout(centralWidget);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(285, 12));

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        file_path_lineEdit = new QLineEdit(centralWidget);
        file_path_lineEdit->setObjectName(QString::fromUtf8("file_path_lineEdit"));
        file_path_lineEdit->setMinimumSize(QSize(202, 20));
        file_path_lineEdit->setReadOnly(true);

        horizontalLayout->addWidget(file_path_lineEdit);

        browse_button = new QPushButton(centralWidget);
        browse_button->setObjectName(QString::fromUtf8("browse_button"));
        browse_button->setMinimumSize(QSize(75, 23));

        horizontalLayout->addWidget(browse_button);


        verticalLayout->addLayout(horizontalLayout);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(285, 12));

        verticalLayout->addWidget(label_2);

        key_name_lineEdit = new QLineEdit(centralWidget);
        key_name_lineEdit->setObjectName(QString::fromUtf8("key_name_lineEdit"));
        key_name_lineEdit->setMinimumSize(QSize(285, 20));

        verticalLayout->addWidget(key_name_lineEdit);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        encrypt_button = new QPushButton(centralWidget);
        encrypt_button->setObjectName(QString::fromUtf8("encrypt_button"));
        encrypt_button->setMinimumSize(QSize(75, 23));

        horizontalLayout_2->addWidget(encrypt_button);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(285, 12));

        verticalLayout->addWidget(label_4);

        cipher_key_tablewidget = new QTableWidget(centralWidget);
        cipher_key_tablewidget->setObjectName(QString::fromUtf8("cipher_key_tablewidget"));
        cipher_key_tablewidget->setMinimumSize(QSize(285, 236));

        verticalLayout->addWidget(cipher_key_tablewidget);


        horizontalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(285, 12));

        verticalLayout_2->addWidget(label_3);

        cipher_text_tablewidget = new QTableWidget(centralWidget);
        cipher_text_tablewidget->setObjectName(QString::fromUtf8("cipher_text_tablewidget"));
        cipher_text_tablewidget->setMinimumSize(QSize(285, 360));

        verticalLayout_2->addWidget(cipher_text_tablewidget);


        horizontalLayout_3->addLayout(verticalLayout_2);


        horizontalLayout_4->addLayout(horizontalLayout_3);

        File_Encrypt_StoreClass->setCentralWidget(centralWidget);

        retranslateUi(File_Encrypt_StoreClass);

        QMetaObject::connectSlotsByName(File_Encrypt_StoreClass);
    } // setupUi

    void retranslateUi(QMainWindow *File_Encrypt_StoreClass)
    {
        File_Encrypt_StoreClass->setWindowTitle(QApplication::translate("File_Encrypt_StoreClass", "File_Encrypt_Store", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("File_Encrypt_StoreClass", "\351\200\211\346\213\251\345\212\240\345\257\206\346\226\207\344\273\266\357\274\232", 0, QApplication::UnicodeUTF8));
        browse_button->setText(QApplication::translate("File_Encrypt_StoreClass", "\346\265\217\350\247\210", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("File_Encrypt_StoreClass", "\347\224\237\346\210\220\345\257\206\351\222\245\345\220\215\357\274\232", 0, QApplication::UnicodeUTF8));
        encrypt_button->setText(QApplication::translate("File_Encrypt_StoreClass", "\345\212\240\345\257\206", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("File_Encrypt_StoreClass", "\345\257\206\351\222\245\345\272\223\357\274\232", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("File_Encrypt_StoreClass", "\345\257\206\346\226\207\345\255\230\345\202\250\345\272\223\357\274\232", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class File_Encrypt_StoreClass: public Ui_File_Encrypt_StoreClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILE_ENCRYPT_STORE_H
