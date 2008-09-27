
#include "view_page.h"

ViewPage::ViewPage()
{
	currentFrame() -> setScrollBarPolicy(Qt::Vertical, Qt::ScrollBarAlwaysOff);
	currentFrame() -> setScrollBarPolicy(Qt::Horizontal, Qt::ScrollBarAlwaysOff);
}

void ViewPage::javaScriptAlert ( QWebFrame * frame, const QString & msg )
{
	emit jsAlert(msg);
}
void ViewPage::on_frameCreated( QWebFrame* frame)
{
	qDebug(" try to disable a scroll bar ");
	frame -> setScrollBarPolicy(Qt::Vertical, Qt::ScrollBarAlwaysOff);
	frame -> setScrollBarPolicy(Qt::Horizontal, Qt::ScrollBarAlwaysOff); 
}
