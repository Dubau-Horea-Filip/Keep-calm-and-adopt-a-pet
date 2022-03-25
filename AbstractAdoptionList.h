#pragma once 
#include "Dog.h"
#include <vector>

class AbstractAdoptionList {

public:
	virtual void write(const std::vector<Dog> adoption_List) = 0;
	virtual void open() const = 0;
};