#pragma once
#include <QVBoxLayout>
#include <qpushbutton.h>
#include <qgroupbox.h>
#include <qradiobutton.h>
#include <qfont.h>
#include <qaction.h>
#include <qlabel.h>
#include <QtWidgets/QApplication>
#include "Service.h"
#include <QWidgetList>
#include <QListWidget>
#include <qlineedit>
#include "AbstractAdoptionList.h"

class GUI : public QWidget
{
	Q_OBJECT

private:
	Service& serv;
	int& option;
	AbstractAdoptionList* abs;

	QListWidget* DogsListWidget;
	QListWidget* DogsListWidget_filter;
	QListWidget* DogsListWidget_u;
	QListWidget* AdoptionListWidget;
	QLineEdit* nameLineedit, *ageLineedit, *photolinklineedit, *breedLineEdit,* breedfilterLineEdit, * agefiltreLineedit;
	QPushButton* addButton, * deletebutton, *updateButton, *adoptButton, *nextButton, *pictureButton,*filterbutton, *showlist,*showadoptionlistuser;

	QLabel* nameLable,* BreedLable,* AgeLable;

	QTabWidget* tab;
	QWidget *administrator,*user;

	int listindex=0;

	void populate_list();
	void conections();
	void startup();

	int getselectedindex();
	int getselectedindex_u();
	void addDog();
	void filter();
	void deleteDog();
	void updateDog();
	void addoptdog();
	void nextbutton_pres();
	void show_picture();
	void show_csv_html();
	void show_csv_html_adoption();

public:

	GUI(Service& s , int opt);
	


};

