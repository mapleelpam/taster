
#ifndef _VIEW_PAGE_H
#define _VIEW_PAGE_H

#include <QWebPage>
#include <QWebFrame>

QT_BEGIN_NAMESPACE
QT_END_NAMESPACE

class ViewPage: public QWebPage 
{
	Q_OBJECT

	public:
		ViewPage();

		virtual void javaScriptAlert ( QWebFrame * frame, const QString & msg );
	signals:
		void jsAlert( QString );

	private slots:
		void on_frameCreated( QWebFrame* );

	private:
};

#endif
