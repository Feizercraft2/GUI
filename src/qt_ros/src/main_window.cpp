/*****************************************************************************
** Includes
*****************************************************************************/

#include <QtGui>
#include <QtCore>
#include <iostream>
#include "../include/qt_ros/main_window.hpp"
#include <sstream>
#include "../include/qt_ros/qnode.hpp"

/*****************************************************************************
** Namespaces
*****************************************************************************/
double longitudeWindow;
double latitudeWindow;
int toggler=0;
double tempLatitude=0;
double tempLongitude=0;
QDateTime dateTime = QDateTime::currentDateTime();
QString dateTimeString = dateTime.toString();

QFile file(dateTimeString + ".txt"); //****************Needs to be changed everytime when creating a new waypoint .txt file
QTextStream stream(&file);
//double newLongitude;
//double newLatitude;
//ros::Publisher sendCoords;
//ros::NodeHandle n;

namespace qt_ros {

using namespace Qt;

/*****************************************************************************
** Implementation [MainWindow]
*****************************************************************************/

MainWindow::MainWindow(int argc, char** argv, QWidget *parent)
	: QMainWindow(parent)
	, qnode(argc,argv)
{
	ui.setupUi(this); // Calling this incidentally connects all ui's triggers to on_...() callbacks in this class.
    //QObject::connect(ui.actionAbout_Qt, SIGNAL(triggered(bool)), qApp, SLOT(aboutQt())); // qApp is a global variable for the application
		ui.input_box_lat->setValidator(new QDoubleValidator(this));
		ui.input_box_long->setValidator(new QDoubleValidator(this));
	//	QFile file("2018_12_05_1152.txt");
	//	QTextStream stream(&file);
    //ReadSettings();
		//setWindowIcon(QIcon(":/images/icon.png"));
//	ui.tab_manager->setCurrentIndex(0); // ensure the first tab is showing - qt-designer should have this already hardwired, but often loses it (settings?).
    QObject::connect(&qnode, SIGNAL(rosShutdown()), this, SLOT(close()));
    /*********************
    ** Logging
    **********************/
    //ui.view_logging->setModel(qnode.loggingModel());
    //QObject::connect(&qnode, SIGNAL(loggingUpdated()), this, SLOT(updateLoggingView()));

    /*********************
    ** Auto Start
    **********************/
/*    if ( ui.checkbox_remember_settings->isChecked() ) {
        on_button_connect_clicked(true);
    }*/
}

MainWindow::~MainWindow() {}

/*****************************************************************************
** Implementation [Slots]
*****************************************************************************/

void MainWindow::showWrongLatitudeMessage() {
	QMessageBox msgBox;
	msgBox.setText("The Latitude coordinate is incorrect, try entering in the range between -90 and 90");
	msgBox.exec();
}

void MainWindow::showWrongLongitudeMessage() {
	QMessageBox msgBox;
	msgBox.setText("The Longitude coordinate is incorrect, try entering in the range between -180 and 180");
	msgBox.exec();
}

void MainWindow::writeToFile() {
	//QFile file("2018_12_05_1152.txt");

    if(file.open(QIODevice::Append | QIODevice::Text)) {
		//QTextStream stream(&file);

		stream << latitudeWindow << " " << longitudeWindow << "\n";

		//stream.flush();
		//file.close();
	}
}

/*
 * These triggers whenever the button is clicked, regardless of whether it
 * is already checked or not.
 */

void MainWindow::on_button_connect_clicked(bool check ) {
    /*if ( ui.checkbox_use_environment->isChecked() ) {
		if ( !qnode.init() ) {
			showNoMasterMessage();
		} else {
			ui.button_connect->setEnabled(false);
		}
	} else {
		if ( ! qnode.init(ui.line_edit_master->text().toStdString(),
				   ui.line_edit_host->text().toStdString()) ) {
			showNoMasterMessage();
		} else {
			ui.button_connect->setEnabled(false);
			ui.line_edit_master->setReadOnly(true);
			ui.line_edit_host->setReadOnly(true);
			ui.line_edit_topic->setReadOnly(true);
		}
	}*/
	if ( ui.button_close ) {
		stream.flush();
		file.close();
	}

	if ( ui.button_connect ) {
		if (ui.run_button->isChecked()) {
			toggler = 1;
		}
		else {
			toggler = 0;
		}
		QString longitudeString = ui.input_box_long->text();
		QString latitudeString = ui.input_box_lat->text();

		longitudeWindow = longitudeString.toDouble();
		latitudeWindow = latitudeString.toDouble();

		ui.input_box_long->setText("");
		ui.input_box_lat->setText("");

		if (latitudeWindow > 85.05112878 || latitudeWindow < -85.05112878) {
			showWrongLatitudeMessage();
		}
		else if (longitudeWindow > 180 || longitudeWindow < -180) {
			showWrongLongitudeMessage();
		}
		else {
			if (tempLatitude == latitudeWindow && tempLongitude == longitudeWindow) {
				//qnode.publish(latitudeWindow,longitudeWindow,toggler);
				qnode.publish(toggler);
			}
			else {
				tempLatitude = latitudeWindow;
				tempLongitude = longitudeWindow;
				writeToFile();
				//qnode.publish(latitudeWindow,longitudeWindow,toggler);
				qnode.publish(toggler);
			}
			//ui.enteredCoords->addItem();
		}

	}
}//on_button_connect_clicked


/*void MainWindow::on_checkbox_use_environment_stateChanged(int state) {
	bool enabled;
	if ( state == 0 ) {
		enabled = true;
	} else {
		enabled = false;
	}
	ui.line_edit_master->setEnabled(enabled);
	ui.line_edit_host->setEnabled(enabled);
	//ui.line_edit_topic->setEnabled(enabled);
}
*/
/*****************************************************************************
** Implemenation [Slots][manually connected]
*****************************************************************************/

/**
 * This function is signalled by the underlying model. When the model changes,
 * this will drop the cursor down to the last line in the QListview to ensure
 * the user can always see the latest log message.
 */
/*void MainWindow::updateLoggingView() {
        ui.view_logging->scrollToBottom();
}

/*****************************************************************************
** Implementation [Menu]
*****************************************************************************/

//void MainWindow::on_actionAbout_triggered() {
//    QMessageBox::about(this, tr("About ..."),tr("<h2>PACKAGE_NAME Test Program 0.10</h2><p>Copyright Yujin Robot</p><p>This package needs an about description.</p>"));
//}

/*****************************************************************************
** Implementation [Configuration]
*****************************************************************************/

/*void MainWindow::ReadSettings() {
    QSettings settings("Qt-Ros Package", "qt_ros");
    restoreGeometry(settings.value("geometry").toByteArray());
    restoreState(settings.value("windowState").toByteArray());
    //QString master_url = settings.value("master_url",QString("http://192.168.1.2:11311/")).toString();
    QString Input_long = settings.value("Input_long", QString("Longitude coordinate")).toString();
		QString Input_lat = settings.value("Input_lat", QString("Latitude coordinate")).toString();
    //QString topic_name = settings.value("topic_name", QString("/chatter")).toString();
    //ui.line_edit_master->setText(master_url);
    ui.input_box_long->setText(Input_long);
		ui.input_box_lat->setText(Input_lat);
    //ui.line_edit_topic->setText(topic_name);
    //bool remember = settings.value("remember_settings", false).toBool();
    //ui.checkbox_remember_settings->setChecked(remember);
    //bool checked = settings.value("use_environment_variables", false).toBool();
    //ui.checkbox_use_environment->setChecked(checked);
    /*if ( checked ) {
    	//ui.line_edit_master->setEnabled(false);
    	ui.line_edit_host->setEnabled(false);
    	//ui.line_edit_topic->setEnabled(false);
    }*/
//}

/*void MainWindow::WriteSettings() {
    QSettings settings("Qt-Ros Package", "qt_ros");
    //settings.setValue("master_url",ui.line_edit_master->text());
    settings.setValue("Input_long",ui.input_box_long->text());
		settings.setValue("Input_lat",ui.input_box_lat->text());
    //settings.setValue("topic_name",ui.line_edit_topic->text());
    //settings.setValue("use_environment_variables",QVariant(ui.checkbox_use_environment->isChecked()));
    settings.setValue("geometry", saveGeometry());
    settings.setValue("windowState", saveState());
    //settings.setValue("remember_settings",QVariant(ui.checkbox_remember_settings->isChecked()));

}
*/
void MainWindow::closeEvent(QCloseEvent *event)
{
	//WriteSettings();
	QMainWindow::closeEvent(event);
}

}  // namespace qt_ros
