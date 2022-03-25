#include"Service.h"
#include<exception>
#include <windows.h>
#include <shellapi.h>
#include <atlbase.h>
#include <atlconv.h>


Service::Service(Repository* repo)
{
	this->repo = repo;
}

std::vector<Dog> Service::getDogList()
{
	std::vector<Dog> Dog_List;
	Dog_List = this->repo->getDogList();

	return Dog_List;
}

std::vector<Dog> Service::getfiltred()
{

	std::vector<Dog> Dog_List;
	Dog_List = this->repo->getfiltredlist();

	return Dog_List;
}


std::vector<Dog> Service::getadoptionlist()
{
	std::vector<Dog> Dog_List;
	Dog_List = this->repo->getAdoptionList();
	return Dog_List;
}

Service::~Service()
{
	delete this->repo;
}


void Service::addDog(std::string name, std::string breed, int age, std::string picture)
{
	Dog a =  Dog(name, breed, age, picture);
	
	this->repo->add(a);
}

void Service::removeDog(std::string name, std::string breed, int age)
{
	this->repo->deleteDog(name, breed, age);
}
std::string Service::SeeAll()
{
	//this->repo->seeAll();

	std::string rezult;
	rezult = this->repo->seeAll();
	return rezult;
}

std::string Service::SeeAll_2()
{
	std::string rezult;
	rezult = this->repo->seeAll_2();
	return rezult;
}

std::string Service::SeeAll_condition(std::string breed, int age)
{
	std::string rezult;
	rezult = this->repo->seeAll_condition(breed,age);
	return rezult;
}

void Service::updateDog(std::string name, std::string breed, int age, std::string Nname, std::string Nbreed, int Nage, std::string picture)
{
	this->repo->update(name, breed, age, Nname, Nbreed, Nage, picture);
}

int Service::get_lengh()
{
	return this->repo->lenght();
}

std::string Service::Seedog(int i)
{	
	Dog a;
	std::string b;
	a = this->repo->Reposeedog(i);
	b = a.toChar();

	system(a.getlink().c_str());

	//system("<mybrowser> a.getlink().c_str()");
	
	/*#include <fstream>
	std::fstream fs;
	fs.open(a.getlink().c_str());*/


	/*ShellExecute(NULL, "open", a.getlink().c_str(),
		NULL, NULL, SW_SHOWNORMAL);*/

	return b;

}

void Service::Seedog_atposition(int i)
{
	Dog a;
	std::string b;
	a = this->repo->Reposeedog(i);

	
	system(std::string("start ").append(a.getlink()).c_str());


}

void Service::Adopt(int i)
{
	Dog a;
	
	a = this->repo->Reposeedog(i);
	this->removeDog(a.getname(), a.getbreed(), a.getage());
	this->repo->add_adoption_list(a);
	
}

void Service::addAdoptionList(Dog adopted_dog)
{
	this->repo->add_adoption_list(adopted_dog);
}

void Service::filter(std::string breed, int age)
{
	this->repo->createfiltredlist(breed, age);
}