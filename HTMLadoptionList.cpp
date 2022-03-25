#include "HTMLadoptionList.h"
#include <QtCore\qurl.h>


void HTMLadoptionlist::write(const std::vector<Dog> adoption_list)
{

	create_start();
	output_file.open(FILE_PATH_HTML, std::ios::app);

	output_file << "<table border=\"1\" class=\" table table-striped\">" << std::endl;

	//output_file << "<threads>" << std::endl;
	output_file << "<tr>" << std::endl;

	output_file << "<th>" << "no." << "</th>" << std::endl;
	output_file << "<th>" << "Name" << "</th>" << std::endl;
	output_file << "<th>" << "Breed" << "</th>" << std::endl;
	output_file << "<th>" << "Age" << "</th>" << std::endl;
	output_file << "<th>" << "Link photo" << "</th>" << std::endl;

	output_file << "</tr>" << std::endl;
	//output_file << "</threads>" << std::endl;
	output_file << "<tbody>" << std::endl;

	int index = 1;
	for (auto &Dog : adoption_list) {
		output_file << "<tr>" << std::endl;
		output_file << "<th>" << index << "</th>" << std::endl;
		output_file << "<td>" << Dog.getName() << "</td>" << std::endl;
		output_file << "<td>" << Dog.getBreed() << "</td>" << std::endl;
		output_file << "<td>" << Dog.getAge() << "</td>" << std::endl;
		output_file << "<td>" << "<a href=\"" << Dog.getLink()  << "class=\"link-info\"" << "\">" << "Link" <<"</a>"  << "</td>" << std::endl;
		output_file << "</tr>" << std::endl;
		index++;
	}

	output_file << "</tbody>" << std::endl;
	output_file << "</table>" << std::endl;
	output_file.close();
	create_end();
}

void HTMLadoptionlist::open() const
{

	/*ShellExecute(NULL, "open", "adoption_list.html",
		NULL, NULL, SW_SHOWNORMAL);*/
	system(std::string("start ").append("adoption_list.html").c_str());
}

void HTMLadoptionlist::create_start()
{
	output_file.open(FILE_PATH_HTML, std::ios::out);
	output_file << "<!DOCTYPE html>" << std::endl;
	output_file << "<html>" << std::endl;
	output_file << "<head>" << std::endl;

	output_file << "<title>  Adoption List </title>" << std::endl;
	output_file << "</head>" << std::endl;
	output_file << "<body>" << std::endl;
	output_file << "<div class= \"container\" >" << std::endl;
	output_file.close();
}

void HTMLadoptionlist::create_end()
{
	output_file.open(FILE_PATH_HTML, std::ios::app);
	output_file << "</div>" << std::endl;
	output_file << "</body>" << std::endl;
	output_file << "</html>" << std::endl;
	output_file.close();
}



//char filename[] = "adoption_list.html";
//char fullname[MAX_PATH];
//
//GetFullPathName(filename, MAX_PATH, fullname, nullptr);