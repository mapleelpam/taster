
#ifndef __DLG_RESIZE_H_
#define __DLG_RESIZE_H_

#include <QtGui>
#include "ui_dlg_resize.h"

class dlgResize : public QDialog
{
	Q_OBJECT
	public:
		dlgResize( QWidget * parent = 0, Qt::WindowFlags f = 0 );

		void setSize(int,int);
		void getSize(int&,int&);

	private:
		Ui::dlgResize ui;
};	

#endif
