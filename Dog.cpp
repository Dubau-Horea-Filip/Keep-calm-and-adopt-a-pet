#include"Dog.h"
#include <exception>
#include<string>
using namespace std;



string Dog::toChar()
{
	string result = "name:" + this->name + " breed:" + this->breed + " age:" + to_string(this->age) ;
	return result;
}

string Dog::toChar_P()
{
	string result = "name:" + this->name + " breed:" + this->breed + " age:" + to_string(this->age) + " picture: " + this->linkToPhoto;
	return result;
}

bool operator==(const Dog& f, const Dog& s)
{
	return f.name == s.name && f.breed == s.breed && f.age == s.age;
}




Dog::Dog(const Dog& v) {
	this->age = v.age;
	this->breed = v.breed;
	this->name = v.name;
	this->linkToPhoto = v.linkToPhoto;

}

Dog& Dog::operator=(const Dog& dv)
{
	this->age = dv.age;
	this->breed = dv.breed;
	this->name = dv.name;
	this->linkToPhoto = dv.linkToPhoto;

	return *this;

}




Dog::Dog(std::string name, std::string breed, int age, std::string linkToPhoto)
{
	this->age = age;
	this->breed = breed;
	this->linkToPhoto = linkToPhoto;
	this->name = name;
	
}

Dog::Dog() {}

std::string Dog::getname()
{
	return this->name;
}

std::string Dog::getbreed()
{
	return this->breed;
}

int Dog::getage()
{
	return this->age;
}

void Dog::setname(std::string name)
{
	this->name = name;
}

void Dog::setbreed(std::string breed)
{
	this->breed = breed;
}

void Dog::setlink(std::string linkToPhoto)
{
	this->linkToPhoto = linkToPhoto;
}

void Dog::setage(int age)
{
	this->age = age;
}

std::string Dog::getlink()
{
	return this->linkToPhoto;
}


std::string Dog::getagestring()
{
	std::string a;
	a = to_string(this->age);
	return a;
	
}

std::ostream& operator<<(std::ostream& out, const Dog& d)
{
	std::string age;
	age = to_string(d.age);
	//out << age;


	string semicolum = ";";
	string enter = "\n";
	
	//std::string out

	//out  << d.name << semicolum << d.breed << semicolum << age << semicolum << d.linkToPhoto << enter;
	
	return out;
}
//
//std::istream& operator>>(std::istream& in, Event& e) {
//
//	in.clear(); in.sync();
//
//	//First line
//	std::string title,description,link,date,time,line,line2;
//	
//}

std::string Dog::toChar_file()
{
	string result = this->name + ";" + this->breed + ";" + to_string(this->age) + ";" + this->linkToPhoto+";";
	return result;
}
std::string Dog::toChar_csv()
{
	string result = this->name + "," + this->breed + "," + to_string(this->age) + "," + this->linkToPhoto + ",";
	return result;
}