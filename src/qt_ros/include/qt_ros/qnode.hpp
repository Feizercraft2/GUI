/**
 * @file /include/qt_ros/qnode.hpp
 *
 * @brief Communications central!
 *
 * @date February 2011
 **/
/*****************************************************************************
** Ifdefs
*****************************************************************************/

#ifndef qt_ros_QNODE_HPP_
#define qt_ros_QNODE_HPP_

/*****************************************************************************
** Includes
*****************************************************************************/

// To workaround boost/qt4 problems that won't be bugfixed. Refer to
//    https://bugreports.qt.io/browse/QTBUG-22829
#ifndef Q_MOC_RUN
#include <ros/ros.h>
#endif
#include <string>
#include <QtGui>
#include <QtCore>
#include <iostream>
//#include <QThread>
//#include <QStringListModel>


/*****************************************************************************
** Namespaces
*****************************************************************************/
//float longitude = 0.0;
//float altitude = 0.0;

namespace qt_ros {

/*****************************************************************************
** Class
*****************************************************************************/

class QNode : public QThread {
    Q_OBJECT
public:
	QNode(int argc, char** argv );
	virtual ~QNode();
	//bool init();
	//bool init(const std::string &master_url, const std::string &host_url);
	void run();
  //double publish(const double &latitudeCoordinate, const double &longitudeCoordinate, const int &toggler);
  int publish(const int &toggler);


	/*********************
	** Logging
	**********************/
	/*enum LogLevel {
	         Debug,
	         Info,
	         Warn,
	         Error,
	         Fatal
	 };

	QStringListModel* loggingModel() { return &logging_model; }
	void log( const LogLevel &level, const std::string &msg);
*/
Q_SIGNALS:
	void loggingUpdated();
  void rosShutdown();

private:
	int init_argc;
	char** init_argv;
	ros::Publisher Publish;
  //QStringListModel logging_model;

};

}  // namespace qt_ros

#endif /* qt_ros_QNODE_HPP_ */
