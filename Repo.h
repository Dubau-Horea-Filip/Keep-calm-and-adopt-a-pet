#pragma once
#include"Dog.h"
#include<string>
#include <iostream>
#include <vector>



class Repository {

private:
	std::vector<Dog> Dog_List;
	std::vector<Dog> adoption_List;
	std::vector<Dog> filtred_List;


	//DynamicArray<Dog>* Dog_List;
	//DynamicArray<Dog>* adoption_List;
public:

	//constructor
	Repository();

	std::vector<Dog> getDogList();

	std::vector<Dog> getAdoptionList();

	std::vector<Dog> getfiltredlist();

	void add(Dog newDog);

	void deleteDog(std::string name, std::string breed, int age);

	void update(std::string name, std::string breed, int age, std::string Nname, std::string Nbreed, int Nage,std::string picture);

	std::string seeAll();

	std::string seeAll_2();

	Dog Reposeedog(int poz);

	std::string seeAll_condition(std::string breed, int age);


	void createfiltredlist(std::string breed, int age);




	int lenght();

	void add_adoption_list(Dog a);

	//deconstructor
	~Repository();

	void save();

	void load();
};
