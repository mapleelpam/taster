
#include "dlg_resize.h"

dlgResize ::dlgResize( QWidget * parent , Qt::WindowFlags f )
	: QDialog( parent, f)
{
	ui.setupUi( this );

}


void dlgResize::setSize(int w,int h )
{
	ui.sbWidth  ->setValue( w );
	ui.sbHeight ->setValue( h );
}
void dlgResize::getSize(int& w,int& h )
{
	w = ui.sbWidth->value();
	h = ui.sbHeight->value(); 
}
