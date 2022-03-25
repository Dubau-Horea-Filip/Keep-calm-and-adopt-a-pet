#include"Repo.h"
#include<exception>
#include"Dog.h"
#include<algorithm>
#include <fstream>
#include<iostream>
#include "DogValidator.h"


Repository::Repository()
{
	this->load();
	//this->Dog_List = new DynamicArray<Dog>(1);
	//this->adoption_List = new DynamicArray<Dog>(1);
}

std::vector<Dog> Repository::getAdoptionList()
{
	return this->adoption_List;
}

std::vector<Dog> Repository::getDogList()
{
	return this->Dog_List;
}

std::vector<Dog> Repository::getfiltredlist()
{
	return this->filtred_List;
}


void Repository::add(Dog newDog)
{	
	auto iter = std::find(this->Dog_List.begin(), this->Dog_List.end(), newDog);
	if (iter != this->Dog_List.end())
		throw ValidationException("Dog already in shelter\n");
		//throw std::exception("Dog already in shelter\n");
	try
	{
		DogValidator::validate(newDog);
		this->Dog_List.push_back(newDog);
		this->save();
	}
	catch (ValidationException& ex)
	{
		std::cout << ex.getMessage() << "\n";
		
	}

	

	//for (auto& dog : this->Dog_List)
	//{
	//	if (dog == newDog)
	//	{
	//		throw std::exception("Dog already in shelter");
	//	}
	//}

	/*std::vector<Dog>::iterator
	iterator = this->Dog_List.begin();
	while (iterator != this->Dog_List.end())
	{
		
		

		if (*iterator == newDog)
		{
			throw std::exception("Dog already in shelter");
		}
		iterator++;
	}
	*/
	
	
	//DynamicArrayIterator<Dog> iterator = this->Dog_List->search(newDog);
	//if (iterator.valid())
	//throw std::exception("Dog already in shelter");
	//this->Dog_List->add(newDog);
}

void Repository::deleteDog(std::string name, std::string breed, int age)
{
	auto iter = std::remove_if(this->Dog_List.begin(), this->Dog_List.end(),
		[name, breed, age](Dog d) {return d.getage() == age && d.getbreed() == breed && d.getname() == name; }	);  

	if (iter == this->Dog_List.end())
		throw ValidationException("Dog not in shelter\n");
		//throw std::exception("Dog not in shelter\n");


	this->Dog_List.erase(iter);

	/*std::vector<Dog>::iterator
	iterator = this->Dog_List.begin();
	Dog currentDog;
	
	while (iterator != this->Dog_List.end())
	{
		
		if ((*iterator).getname() == name && (*iterator).getage() == age && (*iterator).getbreed()==breed)
		{
			this->Dog_List.erase(iterator);
			return;
		}
		iterator++;
	}*/
	




	/*iterator.first();
	* //DynamicArrayIterator<Dog> iterator = this->Dog_List->iterator();
	while (iterator.valid())
	{
		currentdog = iterator.getcurrent();
		if (currentdog.getname() == name && currentdog.getbreed() == breed && currentdog.getage() == age)
			break;
		else {
			iterator.next();
		}
	}
	if (iterator.valid())
	{
		this->dog_list->removeelement(iterator);
		
	}
	else
	{
		throw std::exception("remove coud not be completed, element nonexistant");
	}*/
	this->save();
}

void Repository::update(std::string name, std::string breed, int age, std::string Nname, std::string Nbreed, int Nage, std::string picture)
{




	auto iter = std::find_if(this->Dog_List.begin(), this->Dog_List.end(),
		[name, breed, age](Dog d) {return d.getage() == age && d.getbreed() == breed && d.getname() == name; });

	if (iter == this->Dog_List.end())
		throw ValidationException("Dog not in shelter\n");
		//throw std::exception("Dog not in shelter\n");


	(*iter).setage(Nage);
	(*iter).setbreed(Nbreed);
	(*iter).setlink(picture);
	(*iter).setname(Nname);


	/*std::vector<Dog>::iterator
	iterator = this->Dog_List.begin();
	Dog currentDog;

	while (iterator != this->Dog_List.end())
	{

		if ((*iterator).getname() == name && (*iterator).getage() == age && (*iterator).getbreed() == breed)
		{
			(*iterator).setage(Nage);
			(*iterator).setbreed(Nbreed);
			(*iterator).setlink(picture);
			(*iterator).setname(Nname);
			break;
		}
		iterator++;
	}*/

	/*DynamicArrayIterator<Dog> iterator = this->Dog_List->iterator();
	Dog currentDog;
	iterator.first();
	while (iterator.valid())
	{
		currentDog = iterator.getcurrent();
		if (currentDog.getname() == name && currentDog.getbreed() == breed && currentDog.getage() == age)
		{
			Dog a = Dog(Nname, Nbreed, Nage, picture);
			this->Dog_List->setItem(iterator, a);
			break;
		}

		iterator.next();
	}
	

	if (!iterator.valid())
	{
		throw std::exception("update coud not be completed, element nonexistant");
		
	}*/
	this->save();
}

std::string Repository::seeAll_condition(std::string breed, int age)
{
	std::string rezult;

	if (breed == "")
	{	
		for (auto& dog : this->Dog_List)
		{
			if (dog.getage() <= age)
			{
				std::string rez;
				rez = dog.toChar();
				rezult.append(rez);
				rezult.append("\n");
			}
		}

	/*	std::vector<Dog>::iterator
		iterator = this->Dog_List.begin();
		while (iterator != this->Dog_List.end())

		{
			
			if ((*iterator).getage() <= age)
			{
				std::string rez;
				rez = (*iterator).toChar();
				rezult.append(rez);
				rezult.append("\n");
			}


			iterator++;
		}*/
	}
	else
	{
		for (auto& dog : this->Dog_List)   // & anpersant?
		{
			if (dog.getbreed() == breed && dog.getage() <= age)
			{
				std::string rez;
				rez = dog.toChar();
				rezult.append(rez);
				rezult.append("\n");
			}
		}

	/*	std::vector<Dog>::iterator
			iterator = this->Dog_List.begin();
		while (iterator != this->Dog_List.end())
		{
			
			if ((*iterator).getbreed() == breed && (*iterator).getage() <= age)
			{
				std::string rez;
				rez = (*iterator).toChar();
				rezult.append(rez);
				rezult.append("\n");
			}


			iterator++;
		}*/
	}
	
	return rezult;
}

void Repository::createfiltredlist(std::string breed, int age)
{

	this->filtred_List.clear();

	if (breed == "")
	{
		for (auto& dog : this->Dog_List)
		{
			if ( dog.getage() <= age)
			{
				this->filtred_List.push_back(dog);
			}
		}
	}
	else
	{
		for (auto& dog : this->Dog_List)
		{
			if (dog.getbreed() == breed && dog.getage() <= age)
			{
				this->filtred_List.push_back(dog);
			}
		}
	}
	
}

std::string Repository::seeAll()
{

	std::string result;

	for (auto& dog : this->Dog_List)
	{
		std::string rez;
		rez =dog.toChar();
		result.append(rez);
		result.append("\n");
	}



	
	/*std::vector<Dog>::iterator
		iterator = this->Dog_List.begin();
	while (iterator != this->Dog_List.end())

	{
		
		std::string rez;
		rez = (*iterator).toChar();
		rezult.append(rez);
		rezult.append("\n");
		
		iterator++;
	}*/
	return result;
}

std::string Repository::seeAll_2()
{
	std::string rezult;




	std::vector<Dog>::iterator
		iterator = this->Dog_List.begin();
	while (iterator != this->Dog_List.end())
	{
		
		std::string rez;
		rez = (*iterator).toChar();
		rezult.append(rez);
		rezult.append("\n");

		iterator++;
	}
	return rezult;
}

Repository::~Repository()
{

	this->Dog_List.clear();
	this->adoption_List.clear();

	/*delete this->Dog_List;
	delete this->adoption_List;*/
}

int Repository::lenght()
{
	return this->Dog_List.size();
	//return this->Dog_List->getLengh();
}

Dog Repository::Reposeedog(int poz)
{

	return this->Dog_List[poz];


	/*std::string rezult;

	std::vector<Dog>::iterator
	iterator = this->Dog_List.begin();
	Dog currentDog;

	while (poz)
		{
		poz--;
		iterator++;
		}

	return *iterator;*/
	

	//DynamicArrayIterator<Dog> iterator = this->Dog_List->iterator();
	//Dog currentDog;
	//iterator.first();
	//while (poz)
	//{
	//	poz--;
	//	iterator.next();
	//}
	//Dog dog;
	//dog = iterator.getcurrent();
	//
	//return dog;
}

void Repository::add_adoption_list(Dog a)
{
	//this->adoption_List->add(a);
	this->adoption_List.push_back(a);
}


void Repository::save()
{
	std::ofstream fout;
	std::string rez,rez2;
	fout.open("input.csv");
	if (!fout.is_open())
		return;
	for (auto& d : this->Dog_List)

	{
		rez = d.toChar_csv();
		rez2 = rez2 + "\n"+ rez;
	}
	
	fout << rez2;
	fout.close();
}

void Repository::load()
{
	
	std::ifstream file("input.csv");
	std::string str;
	std::getline(file, str);
	while (std::getline(file, str)) {
		//std::cout << str << "\n";
		std::vector<std::string> parameters;
		int prev = -1;
		int current = -1;
		for (int i = 0; i < str.size(); i++)
			if ( str[i] == ',')
			{
				std::string aux;
				current = i;
				int len = i - prev - 1;
				aux = str.substr(prev + 1, len);
				parameters.push_back(aux);
				prev = i;
			}
		
		std::string name, breed, age, link;

		
		name = parameters[0];
		

		breed = parameters[1];
		age = parameters[2];
		int aage;
		aage = stoi(age);
		link = parameters[3];
		
		Dog newdog(name,breed,aage,link);
		this->add(newdog);/**/
	}
}

