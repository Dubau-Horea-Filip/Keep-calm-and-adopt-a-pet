
#include "DogValidator.h"

using namespace std;

    ValidationException::ValidationException(std::string _message) : message{ _message } {
    }

    std::string ValidationException::getMessage() const {
        return this->message;
    }


   


    void DogValidator::validate(const Dog& s) {
        
        string errors;
        
        if (s.getName().size() < 3)
            errors += string("The dog name cannot be less than 2 characters!\n");
        if (!isupper(s.getName()[0]))
            errors += string("The Dog's name must start with a capital letter!\n");
        if (s.getBreed().size() < 3)
            errors += string("The dog s breed cannot be less than 2 characters!\n");
        if(s.getAge()<0)
            errors += string("The dog can`t be younger then 0 years old   \n");
        if (errors.size() > 0)
            throw ValidationException(errors);
    }
