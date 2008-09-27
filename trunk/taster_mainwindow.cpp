
#include <QtGui>
#include <QtWebKit>
#include "taster_mainwindow.h"
#include "view_page.h"

TasterMainWindow::TasterMainWindow()
	: _leUrl( NULL )
{
	_rslList << "230x320" << "480x640" << "640x480";

	_leUrl = new QLineEdit;
	_leUrl -> setObjectName( "_leUrl" );
	_leUrl -> setSizePolicy(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
	_leUrl -> setMinimumWidth( 240 );
	_lbUrl = new QLabel("URL:");
	_coResolution = new QComboBox;
	resetCbResolution();

	ui.setupUi(this);
	setupUi();
}

void TasterMainWindow::setupUi()
{
	addDockWidget(Qt::LeftDockWidgetArea, ui.dwPreview );
	addDockWidget(Qt::RightDockWidgetArea, ui.dwJsInput );
	addDockWidget(Qt::RightDockWidgetArea, ui.dwLogs);
	tabifyDockWidget( ui.dwJsInput, ui.dwLogs);

	ui.toolBar->addWidget( _lbUrl );
	ui.toolBar->addWidget( _leUrl );
	ui.toolBar2->addWidget( _coResolution ); 
	connect( _leUrl, SIGNAL(returnPressed()), this, SLOT( slot_leUrl_returnPressed() ));
	connect( _coResolution, SIGNAL(activated(const QString&)), this, SLOT( slot_coResolution_activated(const QString&) ));



	ViewPage* vp = new ViewPage;
	ui.wkPreview -> setPage( vp );

	connect( vp, SIGNAL(jsAlert(QString)), this, SLOT( slotJsAlert(QString) ));
}

void TasterMainWindow::slot_leUrl_returnPressed()
{
	ui.wkPreview -> load( QUrl(_leUrl->text()) );
}

void TasterMainWindow::slot_coResolution_activated( const QString & str_resolution )
{
	bool ok = false;
	int w,h;
	QStringList sl = str_resolution . split("x" , QString::SkipEmptyParts );
	qDebug( )<< "str "<<str_resolution ;
	if( sl . count() != 2 ){
		ui.actResize->trigger();			
		sl.clear();
		return;
	}

	w = sl . at( 0 ) . toInt( &ok );	if( !ok ) goto slot_coResolution_activated_error;
	h = sl . at( 1 ) . toInt( &ok );	if( !ok ) goto slot_coResolution_activated_error; 
	ui.wkPreview -> resize( w, h );
	ui.wkPreview -> setMaximumSize( w, h );
	ui.wkPreview -> setMinimumSize( w, h );
	sl.clear();

	return;
slot_coResolution_activated_error:
		qFatal(" Error : unkown resolution string");
}
void TasterMainWindow::on_actOpen_triggered()
{
	printf(" exec onec two \n");
	QString fileName = QFileDialog::getOpenFileName(this,
			tr("Open HTML"), "./", tr("HTML Files (*.html)"));

	_leUrl -> setText( "file://"+fileName );

	slot_leUrl_returnPressed();
}

void TasterMainWindow::slotJsAlert( QString msg )
{
	ui.lwAlertLog-> insertItem( ui.lwAlertLog->count(), msg );
}

#include "dlg_resize.h"
void TasterMainWindow::on_actResize_triggered()
{
	dlgResize dlg(this);
	dlg.setSize( ui.wkPreview->width(), ui.wkPreview->height());
	if( dlg.exec() == QDialog::Accepted ){
		int w=0,h=0;
		dlg.getSize(w,h);
		ui.wkPreview -> resize( w, h );
		ui.wkPreview -> setMaximumSize( w, h );
		ui.wkPreview -> setMinimumSize( w, h );
		
		QString tmpStr;
		tmpStr.sprintf("%dx%d",w,h); 
		_rslList << tmpStr;
		resetCbResolution();
	}
}
void TasterMainWindow::resetCbResolution()
{
	_coResolution -> clear();
	_coResolution -> addItems(_rslList);
	_coResolution -> addItem("...");

	_coResolution -> setCurrentIndex( _coResolution->count()-2);
}
