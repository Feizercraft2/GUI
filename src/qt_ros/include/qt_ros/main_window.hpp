#ifndef qt_ros_MAIN_WINDOW_H
#define qt_ros_MAIN_WINDOW_H

/*****************************************************************************
** Includes
*****************************************************************************/

#include <QtGui/QMainWindow>
#include "ui_main_window.h"
#include "qnode.hpp"

/*****************************************************************************
** Namespace
*****************************************************************************/

namespace qt_ros {

/*****************************************************************************
** Interface [MainWindow]
*****************************************************************************/
class MainWindow : public QMainWindow {
Q_OBJECT

public:
    MainWindow(int argc, char** argv, QWidget *parent = 0);
    ~MainWindow();

  //  void ReadSettings(); // Load up qt program settings at startup
  //  void WriteSettings(); // Save qt program settings when closing

    void closeEvent(QCloseEvent *event); // Overloaded function
    void showWrongLatitudeMessage();
    void showWrongLongitudeMessage();
    void writeToFile();
    //void publishCoordinates();

public Q_SLOTS:
    /******************************************
    ** Auto-connections (connectSlotsByName())
    *******************************************/
    //void on_actionAbout_triggered();
	  void on_button_connect_clicked(bool check);
	//void on_checkbox_use_environment_stateChanged(int state);

    /******************************************
    ** Manual connections
    *******************************************/
    //void updateLoggingView(); // no idea why this can't connect automatically

private:
	Ui::MainWindowDesign ui;
	QNode qnode;
};

}  // namespace qt_ros

#endif // qt_ros_MAIN_WINDOW_H
