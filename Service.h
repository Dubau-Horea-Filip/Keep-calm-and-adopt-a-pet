#pragma once
#include"Repo.h"

class Service {

private:
	Repository* repo;
	
public:
	//consructor
	Service(Repository* repo);

	std::vector<Dog> getDogList();

	std::vector<Dog> getadoptionlist();

	void addDog(std::string name, std::string breed, int age, std::string picture);

	void removeDog(std::string name, std::string breed, int age);

	void updateDog(std::string name, std::string breed, int age, std::string Nname, std::string Nbreed, int Nage, std::string picture);

	std::string SeeAll();

	std::string SeeAll_2();

	std::string Seedog(int i);

	void Seedog_atposition(int i);

	void addAdoptionList(Dog adopted_dog);

	void Adopt(int i);

	void filter(std::string breed, int age);

	std::vector<Dog> getfiltred();


	std::string SeeAll_condition(std::string breed, int age);

	int get_lengh();


	//deconstructer
	~Service();


	

	

};