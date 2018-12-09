#include <QtGui>
#include <QtCore>
#include <iostream>
#include "../include/qt_ros/main_window.hpp"
#include <sstream>
#include "../include/qt_ros/qnode.hpp"

double longitudeWindow;
double latitudeWindow;
int toggler=0;
double tempLatitude=0;
double tempLongitude=0;
QDateTime dateTime = QDateTime::currentDateTime();
QString dateTimeString = dateTime.toString();
QFile file(dateTimeString + ".txt"); //****************Needs to be changed everytime when creating a new waypoint .txt file
QTextStream stream(&file);
QString longitudeString;
QString latitudeString;

namespace qt_ros {

using namespace Qt;

MainWindow::MainWindow(int argc, char** argv, QWidget *parent)
	: QMainWindow(parent)
	, qnode(argc,argv)
{
	ui.setupUi(this);
	ui.input_box_lat->setValidator(new QDoubleValidator(this));
	ui.input_box_long->setValidator(new QDoubleValidator(this));
  QObject::connect(&qnode, SIGNAL(rosShutdown()), this, SLOT(close()));
}

MainWindow::~MainWindow() {}

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
	if(file.open(QFile::Append | QFile::Text)) {
		stream << latitudeString << " " << longitudeString << "\n";
	}
}

void MainWindow::on_button_connect_clicked(bool check ) {
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
		longitudeString = ui.input_box_long->text();
		latitudeString = ui.input_box_lat->text();

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
				qnode.publish(toggler);
			}
			else {
				tempLatitude = latitudeWindow;
				tempLongitude = longitudeWindow;
				writeToFile();
				qnode.publish(toggler);
			}
		}

	}
}//on_button_connect_clicked

void MainWindow::closeEvent(QCloseEvent *event)
{
	QMainWindow::closeEvent(event);
}

} //namespace qt_ros
