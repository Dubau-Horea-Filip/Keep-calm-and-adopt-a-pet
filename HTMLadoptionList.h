#pragma once
#include "AbstractAdoptionList.h"
#include <fstream>
#include <Windows.h>
#pragma comment(lib, "SHELL32.LIB")

#define FILE_PATH_HTML "adoption_list.html"

class HTMLadoptionlist : public AbstractAdoptionList {

	std::ofstream output_file;

	void create_start();

	void create_end();

public:

	void write(const std::vector < Dog > adoption_list) override;

	void open() const override;

};