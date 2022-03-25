#pragma once
#include "AbstractAdoptionList.h"

//#define FILE_PATH_CSV "adoption_list.csv"

class CSVdoptionlist : public AbstractAdoptionList {

	
public:

	void write(const std::vector < Dog > adoption_list) override;

	void open() const override;

};