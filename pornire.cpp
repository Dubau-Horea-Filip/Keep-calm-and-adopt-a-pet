#include "pornire.h"
#include "qlayout.h"
#include <qformlayout.h>
#include <qgridlayout.h>
#include<vector>
#include<qmessagebox.h>
#include <QTabWidget>
#include"HTMLadoptionList.h"
#include"CSVadoptionList.h"

using namespace std;

GUI::GUI(Service& s, int opt) : serv{ s } , option(opt)
{

	if (this->option == 2)
	{
		this->abs = new HTMLadoptionlist();
	}
	else
	{
		this->abs = new CSVdoptionlist();
	}
	this->startup();
	this->populate_list();
	this->conections();
}






void GUI::populate_list()
{
	this->DogsListWidget->clear();
	this->DogsListWidget_u->clear();
	this->AdoptionListWidget->clear();
	this->DogsListWidget_filter->clear();

	vector<Dog> allDogs = this->serv.getDogList();
	for (Dog& d : allDogs)
	{
		
		this->DogsListWidget->addItem(QString::fromStdString(d.getName() + " - " + d.getBreed() + " - " + d.getagestring()));
		this->DogsListWidget_u->addItem(QString::fromStdString(d.getName() + " - " + d.getBreed() + " - " + d.getagestring()));
		
		
	}

	vector<Dog> allDogs_adopt = this->serv.getadoptionlist();
	for (Dog& d : allDogs_adopt)
	{

		this->AdoptionListWidget->addItem(QString::fromStdString(d.getName() + " - " + d.getBreed() + " - " + d.getagestring()));
		


	}
	vector<Dog> allDogs_filtred = this->serv.getfiltred();
	for (Dog& d : allDogs_filtred)
	{

		this->DogsListWidget_filter->addItem(QString::fromStdString(d.getName() + " - " + d.getBreed() + " - " + d.getagestring()));



	}
}






int GUI::getselectedindex()
{
	QModelIndexList selectedindexs = this->DogsListWidget->selectionModel()->selectedIndexes();
	if (selectedindexs.size() == 0)
	{
		this->nameLineedit->clear();
		this->breedLineEdit->clear();
		this->ageLineedit->clear();
		this->photolinklineedit->clear();
		return -1;
	}
	int slectedINDEX = selectedindexs.at(0).row();
	return slectedINDEX;
}

int GUI::getselectedindex_u()
{
	QModelIndexList selectedindexs = this->DogsListWidget_u->selectionModel()->selectedIndexes();
	if (selectedindexs.size() == 0)
	{
		return -1;
	}
	int slectedINDEX = selectedindexs.at(0).row();
	return slectedINDEX;
}











void GUI::startup()   //init
{
	this->setWindowTitle("Adopt a pet");

	this->DogsListWidget = new QListWidget{};
	this->DogsListWidget_u = new QListWidget{};
	this->AdoptionListWidget = new QListWidget{};
	this->DogsListWidget_filter = new QListWidget{};

	this->nameLineedit = new QLineEdit{};
	this->ageLineedit = new QLineEdit{};
	this->photolinklineedit = new QLineEdit{};
	this->breedLineEdit = new QLineEdit{};
	this->agefiltreLineedit = new QLineEdit{};
	this->breedfilterLineEdit = new QLineEdit{};

	 nameLable = new QLabel;
	 BreedLable = new QLabel;
	 AgeLable = new QLabel;
	 Dog d = this->serv.getDogList()[listindex];
	 this->nameLable->setText(QString::fromStdString(d.getname()));
	 this->AgeLable->setText(QString::fromStdString(d.getagestring()));
	 this->BreedLable->setText(QString::fromStdString(d.getbreed()));

	this->addButton = new QPushButton{"Add"};
	this->deletebutton = new QPushButton{"Delete"};
	this->updateButton = new QPushButton{"Update"};

	this->adoptButton = new QPushButton{"Adopt"};
	this->nextButton = new QPushButton{"Next"};
	this->pictureButton = new QPushButton{"Picture"};

	this->filterbutton = new QPushButton{"filtre"};
	this->showlist = new QPushButton{"show list"};
	this->showadoptionlistuser = new QPushButton{"show adoption list"};

	QVBoxLayout* mainLayout = new QVBoxLayout{ this };


	//mainLayout->addWidget(this->DogsListWidget);    ///  first
	
	QFormLayout* DogDetails = new QFormLayout{};
	DogDetails->addRow("Name", this->nameLineedit);
	DogDetails->addRow("Breed", this->breedLineEdit);
	DogDetails->addRow("Age", this->ageLineedit);
	DogDetails->addRow("Photo", this->photolinklineedit);

	//mainLayout->addLayout(DogDetails);          // second

	QGridLayout* buttonsLayout = new QGridLayout{};
	buttonsLayout->addWidget(this->addButton, 0, 0);
	buttonsLayout->addWidget(this->deletebutton, 0, 1);
	buttonsLayout->addWidget(this->updateButton, 0, 2);

	
	

	//mainLayout->addLayout(buttonsLayout);    // third

	//Create the QTabWidget
	tab = new QTabWidget(this);

	//Create tabs
	 administrator = new QWidget;
	 user = new QWidget;

	//Create a boxlayout (vertical here)
	QFormLayout *vbox_ad;
	QFormLayout *vbox_us;
	QFormLayout *vbox_us_1;
	QGridLayout* User;
	User = new QGridLayout{};

	vbox_ad = new QFormLayout;

	vbox_us_1 = new QFormLayout;
	vbox_us = new QFormLayout;

	vbox_us_1->addRow(this->DogsListWidget_filter);
	vbox_us_1->addRow("breed",breedfilterLineEdit);
	vbox_us_1->addRow("age",agefiltreLineedit);
	vbox_us_1->addRow(filterbutton);



	

	//Set the layout for your tab             xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
	administrator->setLayout(vbox_ad);

	User->addLayout(vbox_us, 0, 0);
	User->addLayout(vbox_us_1, 0, 1);
	User->addWidget(showadoptionlistuser,1,0);

	user->setLayout(User);
	

	//If you want to add widgets into your tab1
	vbox_ad->addRow(this->DogsListWidget);
	vbox_ad->addRow(DogDetails);
	vbox_ad->addRow(buttonsLayout);
	vbox_ad->addRow(showlist);



	QGridLayout* Layout = new QGridLayout{};

	QFormLayout* lableslayout = new QFormLayout;
	lableslayout->addRow(nameLable);
	lableslayout->addRow(BreedLable);
	lableslayout->addRow(AgeLable);
	lableslayout->addRow(pictureButton);
	
	Layout->addWidget(this->AdoptionListWidget,0,1);
	Layout->addLayout(lableslayout,0,0);

	QGridLayout* buttonsLayout_u = new QGridLayout{};
	buttonsLayout_u->addWidget(nextButton,0,0); 
	buttonsLayout_u->addWidget(adoptButton,0,1); 
	 

	vbox_us->addRow(Layout);
	vbox_us->addRow(buttonsLayout_u);
	
	



	//Add tabs to the QTabWidget
	tab->addTab(administrator, "administrator");
	tab->addTab(user, "user ");
	
	mainLayout->addWidget(tab);
}














void GUI::conections()
{
	QObject::connect(this->DogsListWidget, &QListWidget::itemSelectionChanged, [this]() {

		int selectedIndex = this->getselectedindex();
		if (selectedIndex < 0)
		{	return;}
		Dog d = this->serv.getDogList()[selectedIndex];
		this->nameLineedit->setText(QString::fromStdString(d.getname()));
		this->ageLineedit->setText(QString::fromStdString(d.getagestring()));
		this->breedLineEdit->setText(QString::fromStdString(d.getBreed()));
		this->photolinklineedit->setText(QString::fromStdString(d.getLink()));
	});

	QObject::connect(this->addButton, &QPushButton::clicked, this,&GUI::addDog);

	QObject::connect(this->deletebutton, &QPushButton::clicked, this,&GUI::deleteDog);

	QObject::connect(this->updateButton, &QPushButton::clicked, this,&GUI::updateDog);

	QObject::connect(this->adoptButton, &QPushButton::clicked, this ,&GUI::addoptdog);

	QObject::connect(this->nextButton, &QPushButton::clicked, this ,&GUI::nextbutton_pres);

	QObject::connect(this->pictureButton, &QPushButton::clicked, this ,&GUI::show_picture);

	QObject::connect(this->filterbutton, &QPushButton::clicked, this ,&GUI::filter);

	QObject::connect(this->showlist, &QPushButton::clicked, this ,&GUI::show_csv_html);

	QObject::connect(this->showadoptionlistuser, &QPushButton::clicked, this ,&GUI::show_csv_html_adoption);

}










void GUI::addDog()
{
	string name = this->nameLineedit->text().toStdString();
	string agee = this->ageLineedit->text().toStdString();
	string breed = this->breedLineEdit->text().toStdString();
	string photoLink = this->photolinklineedit->text().toStdString();
	int age = std::stoi(agee);

	Dog newDog{ name, breed, age, photoLink };
	std::vector<Dog> list = this->serv.getDogList();
	auto iter = std::find(list.begin(),list.end(), newDog);
	if (iter != list.end())
	{
		QMessageBox::critical(this, "Error", "Dog already in shelter\n");
		return;
	}



	this->serv.addDog(name, breed, age, photoLink);
	this->populate_list();
	int lastelement = this->serv.getDogList().size() - 1;
	this->DogsListWidget->setCurrentRow(lastelement);
}



void GUI::deleteDog()
{	
	int selected = this->getselectedindex();
	if (selected < 0)
	{
		QMessageBox::critical(this, "Error", "No Dog selected");
		return;
	}
	string name = this->nameLineedit->text().toStdString();
	string agee = this->ageLineedit->text().toStdString();
	string breed = this->breedLineEdit->text().toStdString();
	int age = std::stoi(agee);
	this->serv.removeDog(name, breed, age);
	this->populate_list();
	
}




void GUI::updateDog()
{
	int selected = this->getselectedindex();
	if (selected < 0)
	{
		QMessageBox::critical(this, "Error", "No Dog selected");
		return;
	}
	Dog d = this->serv.getDogList()[selected];
	string name = this->nameLineedit->text().toStdString();
	string agee = this->ageLineedit->text().toStdString();
	int age = std::stoi(agee);
	string breed = this->breedLineEdit->text().toStdString();
	string photoLink = this->photolinklineedit->text().toStdString();
	this->serv.updateDog(d.getName(), d.getbreed(), d.getAge(), name, breed, age, photoLink);
	this->populate_list();
	int lastelement = this->serv.getDogList().size() - 1;
	this->DogsListWidget->setCurrentRow(selected);
}


void GUI::nextbutton_pres()
{

	if (this->listindex == this->serv.getDogList().size() - 1)
	{
		this->listindex = 0;
	}
	else
	{
		this->listindex++;
	}

	Dog d = this->serv.getDogList()[listindex];
	this->nameLable->setText(QString::fromStdString(d.getname()));
	this->AgeLable->setText(QString::fromStdString(d.getagestring()));
	this->BreedLable->setText(QString::fromStdString(d.getbreed()));
}

void GUI::show_picture()
{
	this->serv.Seedog_atposition(this->listindex);
	
}

void GUI::addoptdog()
{



	Dog d = this->serv.getDogList()[listindex];
	string name = d.getname();
	int age = d.getAge();
	string breed = d.getbreed();
	
	this->serv.removeDog(name, breed, age);
	this->serv.addAdoptionList(d);

	this->listindex = 0;
	Dog dd = this->serv.getDogList()[listindex];
	this->nameLable->setText(QString::fromStdString(dd.getname()));
	this->AgeLable->setText(QString::fromStdString(dd.getagestring()));
	this->BreedLable->setText(QString::fromStdString(dd.getbreed()));

	
	this->populate_list();

}





void GUI::filter()
{

	if (agefiltreLineedit->text().toStdString() == "")
	{
		QMessageBox::critical(this, "Error", "No age stated");
		return;
	}

	string breed = this->breedfilterLineEdit->text().toStdString();
	string agee = this->agefiltreLineedit->text().toStdString();
	int age = std::stoi(agee);

	this->serv.filter(breed,age);
	this->populate_list();
}

void GUI::show_csv_html()
{
	abs->write(this->serv.getDogList());
	abs->open();
}

void GUI::show_csv_html_adoption()
{
	abs->write(this->serv.getadoptionlist());
	abs->open();
}