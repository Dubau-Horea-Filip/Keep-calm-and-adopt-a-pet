#include <QVBoxLayout>
#include <qpushbutton.h>
#include <qgroupbox.h>
#include <qradiobutton.h>
#include <qfont.h>
#include <qaction.h>
#include <qlabel.h>
#include <QtWidgets/QApplication>
#include"pornire.h"
#include "Repo.h"
#include "Service.h"
#include <memory>

void csv()
{
	Repository* repo = new Repository();
	Service* service = new Service(repo);


	//GUI gui{ *service ,1 };
	//gui.show();

	GUI* gui = new GUI{ *service , 1 };
	gui->show();
}

void html()
{
	
	Repository* repo = new Repository();
	Service* service = new Service(repo);

	/// <summary>
	/// GUI gui{ *service };
	/// gui.show();
	/// </summary>
	GUI *gui = new GUI { *service , 2 };
	gui->show();
}



int main(int argc, char*argv[])  
{
	
	QApplication a(argc,argv);
	
		QWidget* buttonswidget = new QWidget{};
		QBoxLayout* layout = new QHBoxLayout{ buttonswidget };



		QPushButton* csvbutton = new QPushButton{ "csv" };
		QPushButton* htmlbutton = new QPushButton{ "html" };

		layout->addWidget(csvbutton);
		layout->addWidget(htmlbutton);
		layout->addWidget(buttonswidget);

		QObject::connect(csvbutton, &QPushButton::clicked,buttonswidget, &csv);
		QObject::connect(htmlbutton, &QPushButton::clicked,buttonswidget, &html);


		buttonswidget->show();

	return a.exec();
}
