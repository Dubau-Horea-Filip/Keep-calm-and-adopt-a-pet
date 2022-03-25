#pragma once

#include <string>
#include "Dog.h"


class ValidationException {
private:
    std::string message;

public:
    ValidationException(std::string _message);

    std::string getMessage() const;
};



class DogValidator {
public:
    static void validate(const Dog& s);
};
