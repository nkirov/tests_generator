/********************************************************************************
** Form generated from reading UI file 'ut.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UT_H
#define UI_UT_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDateEdit>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_ut
{
public:
    QFormLayout *formLayout;
    QFrame *line_3;
    QLabel *input_file_name_label;
    QLineEdit *input_file_name;
    QLabel *title_label;
    QComboBox *title;
    QLabel *label;
    QComboBox *test_no;
    QLabel *ddate_label;
    QDateEdit *ddate;
    QLabel *number_label;
    QSpinBox *nnumber;
    QLabel *number_of_tests_label;
    QSpinBox *number_of_tests;
    QPushButton *go;

    void setupUi(QDialog *ut)
    {
        if (ut->objectName().isEmpty())
            ut->setObjectName(QString::fromUtf8("ut"));
        ut->resize(591, 294);
        formLayout = new QFormLayout(ut);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        line_3 = new QFrame(ut);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        formLayout->setWidget(0, QFormLayout::LabelRole, line_3);

        input_file_name_label = new QLabel(ut);
        input_file_name_label->setObjectName(QString::fromUtf8("input_file_name_label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, input_file_name_label);

        input_file_name = new QLineEdit(ut);
        input_file_name->setObjectName(QString::fromUtf8("input_file_name"));

        formLayout->setWidget(1, QFormLayout::FieldRole, input_file_name);

        title_label = new QLabel(ut);
        title_label->setObjectName(QString::fromUtf8("title_label"));
        title_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        formLayout->setWidget(3, QFormLayout::LabelRole, title_label);

        title = new QComboBox(ut);
        title->setObjectName(QString::fromUtf8("title"));

        formLayout->setWidget(3, QFormLayout::FieldRole, title);

        label = new QLabel(ut);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label);

        test_no = new QComboBox(ut);
        test_no->setObjectName(QString::fromUtf8("test_no"));

        formLayout->setWidget(4, QFormLayout::FieldRole, test_no);

        ddate_label = new QLabel(ut);
        ddate_label->setObjectName(QString::fromUtf8("ddate_label"));

        formLayout->setWidget(6, QFormLayout::LabelRole, ddate_label);

        ddate = new QDateEdit(ut);
        ddate->setObjectName(QString::fromUtf8("ddate"));
        ddate->setDate(QDate(2015, 6, 25));
        ddate->setCalendarPopup(false);

        formLayout->setWidget(6, QFormLayout::FieldRole, ddate);

        number_label = new QLabel(ut);
        number_label->setObjectName(QString::fromUtf8("number_label"));

        formLayout->setWidget(8, QFormLayout::LabelRole, number_label);

        nnumber = new QSpinBox(ut);
        nnumber->setObjectName(QString::fromUtf8("nnumber"));
        nnumber->setMinimum(2);
        nnumber->setMaximum(20);
        nnumber->setValue(15);

        formLayout->setWidget(8, QFormLayout::FieldRole, nnumber);

        number_of_tests_label = new QLabel(ut);
        number_of_tests_label->setObjectName(QString::fromUtf8("number_of_tests_label"));

        formLayout->setWidget(10, QFormLayout::LabelRole, number_of_tests_label);

        number_of_tests = new QSpinBox(ut);
        number_of_tests->setObjectName(QString::fromUtf8("number_of_tests"));
        number_of_tests->setMinimum(2);
        number_of_tests->setValue(35);

        formLayout->setWidget(10, QFormLayout::FieldRole, number_of_tests);

        go = new QPushButton(ut);
        go->setObjectName(QString::fromUtf8("go"));
        go->setEnabled(true);
        QFont font;
        font.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font.setPointSize(10);
        font.setBold(false);
        font.setItalic(false);
        font.setUnderline(false);
        font.setWeight(50);
        font.setKerning(true);
        go->setFont(font);

        formLayout->setWidget(11, QFormLayout::FieldRole, go);


        retranslateUi(ut);

        title->setCurrentIndex(0);
        test_no->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ut);
    } // setupUi

    void retranslateUi(QDialog *ut)
    {
        ut->setWindowTitle(QApplication::translate("ut", "Test generator, v.2, 27.11.2016", 0, QApplication::UnicodeUTF8));
        input_file_name_label->setText(QApplication::translate("ut", "Input file name:", 0, QApplication::UnicodeUTF8));
        input_file_name->setText(QApplication::translate("ut", "t1_data.tex", 0, QApplication::UnicodeUTF8));
        title_label->setText(QApplication::translate("ut", "Title:", 0, QApplication::UnicodeUTF8));
        title->clear();
        title->insertItems(0, QStringList()
         << QApplication::translate("ut", "CITB100 \320\237\321\200\320\276\320\263\321\200\320\260\320\274\320\270\321\200\320\260\320\275\320\265", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ut", "CSCB300 \320\237\321\200\320\276\320\263\321\200\320\260\320\274\320\270\321\200\320\260\320\275\320\265 \320\267\320\260 \320\275\320\260\320\277\321\200\320\265\320\264\320\275\320\260\320\273\320\270", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ut", "CITB303 \320\241\321\202\321\200\321\203\320\272\321\202\321\203\321\200\320\270 \320\276\321\202 \320\264\320\260\320\275\320\275\320\270 (\320\241++)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ut", "CITB101 \320\237\321\200\320\276\320\263\321\200\320\260\320\274\320\270\321\200\320\260\320\275\320\265 \320\275\320\260 \320\241 \320\270 \320\241++", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ut", "NETB201 Data structures (C++)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ut", "CITB201 \320\236\320\261\320\265\320\272\321\202\320\275\320\276-\320\276\321\200\320\270\320\265\320\275\321\202\320\270\321\200\320\260\320\275\320\276 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\270\321\200\320\260\320\275\320\265 (C++)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ut", "\320\237\321\200\320\276\320\263\321\200\320\260\320\274\320\270\321\200\320\260\320\275\320\265 \320\275\320\260 \320\241", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ut", "CSCB010 \320\237\321\200\320\276\320\263\321\200\320\260\320\274\320\270\321\200\320\260\320\275\320\265 \320\267\320\260 \320\275\320\260\320\277\321\200\320\265\320\264\320\275\320\260\320\273\320\270", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ut", "NETB101 Computer programming (C++)", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ut", "NETB151 Object-Oriented Programming (C++)", 0, QApplication::UnicodeUTF8)
        );
        label->setText(QApplication::translate("ut", "Test No", 0, QApplication::UnicodeUTF8));
        test_no->clear();
        test_no->insertItems(0, QStringList()
         << QApplication::translate("ut", "\320\242\320\265\321\201\321\202 1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ut", "\320\242\320\265\321\201\321\202 2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ut", "\320\242\320\265\321\201\321\202 3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ut", "\320\242\320\265\321\201\321\202 4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ut", "Test 1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ut", "Test 2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ut", "Test 3", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ut", "New Item", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ut", "Test 4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ut", "Final test", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("ut", "\320\242\320\265\321\201\321\202", 0, QApplication::UnicodeUTF8)
        );
        ddate_label->setText(QApplication::translate("ut", "Date:", 0, QApplication::UnicodeUTF8));
        ddate->setDisplayFormat(QApplication::translate("ut", "d.MM.yyyy", 0, QApplication::UnicodeUTF8));
        number_label->setText(QApplication::translate("ut", "Number of test questions:", 0, QApplication::UnicodeUTF8));
        number_of_tests_label->setText(QApplication::translate("ut", "Number of tests:", 0, QApplication::UnicodeUTF8));
        go->setText(QApplication::translate("ut", "GO", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ut: public Ui_ut {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UT_H
