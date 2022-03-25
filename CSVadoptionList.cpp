#include "CSVadoptionList.h"
#include <fstream>
#include<iostream>


void CSVdoptionlist::write(const std::vector<Dog> adoption_list)
{
	std::ofstream fout;
	std::string rez, rez2;
	fout.open("adopted.csv");
	if (!fout.is_open())
		return;
	for (auto& d : adoption_list)

	{
		
		rez = d.toChar_csv_1();
		rez2 = rez2 + "\n" + rez;
	}

	fout << rez2;
	fout.close();

}



void CSVdoptionlist::open() const
{
	system("adopted.csv");
	//system(FILE_PATH_CSV);
}
