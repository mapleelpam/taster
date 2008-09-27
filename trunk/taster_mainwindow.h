
#ifndef _TASTER_H_
#define _TASTER_H_

#include <QMainWindow>
#include <QtGui>
#include "ui_taster_mainwindow.h"

QT_BEGIN_NAMESPACE
QT_END_NAMESPACE

class TasterMainWindow: public QMainWindow
{
	Q_OBJECT

	public:
		TasterMainWindow();
	public slots:
		// make connection by self
		void slot_leUrl_returnPressed();
		void slot_coResolution_activated( const QString & str_resolution );
		void slotJsAlert( QString );

		// make connection automatically
		void on_actOpen_triggered();

		void on_actResize_triggered();
	private:
		void setupUi();
		void resetCbResolution();

	private:
		Ui::TasterMainWindow ui;
		QLineEdit* _leUrl;
		QLabel* _lbUrl;
		QComboBox* _coResolution;
		QStringList _rslList;
};

#endif
