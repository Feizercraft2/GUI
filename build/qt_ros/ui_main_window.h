/********************************************************************************
** Form generated from reading UI file 'main_window.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_WINDOW_H
#define UI_MAIN_WINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowDesign
{
public:
    QAction *action_Quit;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *enteredCoords;
    QHBoxLayout *horizontalLayout;
    QLineEdit *input_box_lat;
    QLineEdit *input_box_long;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *verticalSpacer_2;
    QPushButton *quit_button;
    QHBoxLayout *horizontalLayout_7;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *button_connect;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *verticalSpacer_4;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer;
    QPushButton *run_button;
    QPushButton *button_close;

    void setupUi(QMainWindow *MainWindowDesign)
    {
        if (MainWindowDesign->objectName().isEmpty())
            MainWindowDesign->setObjectName(QString::fromUtf8("MainWindowDesign"));
        MainWindowDesign->setEnabled(true);
        MainWindowDesign->resize(733, 263);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindowDesign->setWindowIcon(icon);
        MainWindowDesign->setLocale(QLocale(QLocale::English, QLocale::Australia));
        action_Quit = new QAction(MainWindowDesign);
        action_Quit->setObjectName(QString::fromUtf8("action_Quit"));
        action_Quit->setShortcutContext(Qt::ApplicationShortcut);
        centralwidget = new QWidget(MainWindowDesign);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        enteredCoords = new QComboBox(centralwidget);
        enteredCoords->setObjectName(QString::fromUtf8("enteredCoords"));
        enteredCoords->setMaximumSize(QSize(300, 16777215));

        horizontalLayout_2->addWidget(enteredCoords);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        input_box_lat = new QLineEdit(centralwidget);
        input_box_lat->setObjectName(QString::fromUtf8("input_box_lat"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(input_box_lat->sizePolicy().hasHeightForWidth());
        input_box_lat->setSizePolicy(sizePolicy);
        input_box_lat->setMaximumSize(QSize(300, 16777215));
        input_box_lat->setInputMethodHints(Qt::ImhDigitsOnly);
        input_box_lat->setMaxLength(13);

        horizontalLayout->addWidget(input_box_lat);

        input_box_long = new QLineEdit(centralwidget);
        input_box_long->setObjectName(QString::fromUtf8("input_box_long"));
        input_box_long->setMaximumSize(QSize(300, 16777215));
        input_box_long->setInputMethodHints(Qt::ImhDigitsOnly);
        input_box_long->setMaxLength(13);

        horizontalLayout->addWidget(input_box_long);


        horizontalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        verticalSpacer_2 = new QSpacerItem(60, 58, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout_5->addItem(verticalSpacer_2);


        horizontalLayout_2->addLayout(horizontalLayout_5);

        quit_button = new QPushButton(centralwidget);
        quit_button->setObjectName(QString::fromUtf8("quit_button"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(quit_button->sizePolicy().hasHeightForWidth());
        quit_button->setSizePolicy(sizePolicy1);
        quit_button->setMaximumSize(QSize(200, 25));

        horizontalLayout_2->addWidget(quit_button);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        button_connect = new QPushButton(centralwidget);
        button_connect->setObjectName(QString::fromUtf8("button_connect"));
        sizePolicy.setHeightForWidth(button_connect->sizePolicy().hasHeightForWidth());
        button_connect->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(button_connect);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalSpacer_4 = new QSpacerItem(30, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout_3->addItem(verticalSpacer_4);

        verticalSpacer_3 = new QSpacerItem(30, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout_3->addItem(verticalSpacer_3);

        verticalSpacer = new QSpacerItem(30, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        horizontalLayout_3->addItem(verticalSpacer);


        horizontalLayout_4->addLayout(horizontalLayout_3);


        horizontalLayout_6->addLayout(horizontalLayout_4);

        run_button = new QPushButton(centralwidget);
        run_button->setObjectName(QString::fromUtf8("run_button"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(run_button->sizePolicy().hasHeightForWidth());
        run_button->setSizePolicy(sizePolicy2);
        run_button->setCheckable(true);
        run_button->setDefault(false);
        run_button->setFlat(false);

        horizontalLayout_6->addWidget(run_button);


        horizontalLayout_7->addLayout(horizontalLayout_6);

        button_close = new QPushButton(centralwidget);
        button_close->setObjectName(QString::fromUtf8("button_close"));

        horizontalLayout_7->addWidget(button_close);


        verticalLayout->addLayout(horizontalLayout_7);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        MainWindowDesign->setCentralWidget(centralwidget);

        retranslateUi(MainWindowDesign);
        QObject::connect(action_Quit, SIGNAL(triggered()), MainWindowDesign, SLOT(close()));
        QObject::connect(quit_button, SIGNAL(clicked()), MainWindowDesign, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindowDesign);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowDesign)
    {
        MainWindowDesign->setWindowTitle(QApplication::translate("MainWindowDesign", "QRosApp", 0, QApplication::UnicodeUTF8));
        action_Quit->setText(QApplication::translate("MainWindowDesign", "&Quit", 0, QApplication::UnicodeUTF8));
        action_Quit->setShortcut(QApplication::translate("MainWindowDesign", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        input_box_lat->setPlaceholderText(QApplication::translate("MainWindowDesign", "Latitude coordinate", 0, QApplication::UnicodeUTF8));
        input_box_long->setPlaceholderText(QApplication::translate("MainWindowDesign", "Longitude coordinate", 0, QApplication::UnicodeUTF8));
        quit_button->setText(QApplication::translate("MainWindowDesign", "Quit", 0, QApplication::UnicodeUTF8));
        button_connect->setText(QApplication::translate("MainWindowDesign", "Send", 0, QApplication::UnicodeUTF8));
        run_button->setText(QApplication::translate("MainWindowDesign", "Run", 0, QApplication::UnicodeUTF8));
        button_close->setText(QApplication::translate("MainWindowDesign", "Close .txt", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindowDesign: public Ui_MainWindowDesign {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
