#pragma once
#include <string>
#include <stdio.h>
#include <string>
using namespace std;

class Dog
{
private:
	std::string name;
	std::string breed;
	int age;
	std::string linkToPhoto;

public:

	std::string toChar();
	std::string toChar_file();
	std::string toChar_csv();
	std::string toChar_P();

	std::string toChar_csv_1() const { return this->name + "," + this->breed + "," + to_string(this->age) + "," + this->linkToPhoto + ","; }
	

	
	friend bool operator==(const Dog& f, const Dog& s);

	friend std::ostream& operator<<(std::ostream& out, const Dog& d);

	//default constructer
	Dog();

	std::string getName() const { return this->name; }
	std::string getBreed() const { return this->breed; }
	std::string getLink() const { return this->linkToPhoto; }
	int getAge() const { return this->age; }
	

	std::string getname();
	std::string getbreed();
	std::string getlink();
	std::string getagestring();
	int getage();

	void setname(std::string name);
	void setbreed(std::string breed);
	void setlink(std::string linkToPhoto);
	void setage(int age);

	//constructor
	Dog(std::string name, std::string breed, int age, std::string linkToPhoto);


	//coppy constructer
	Dog(const Dog& d);


	// assignment operator
	Dog& operator=(const Dog& dv);

	
	
	
}; 

