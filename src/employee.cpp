#include "employee.hpp"

Employee::Employee(std::string name, std::string lastName, std::string address, 
    std::string pesel, Gender gender, int salary) 
    :Person(name, lastName, address, pesel, gender), salary_(salary){}

Employee::~Employee(){}

std::string Employee::show() const{
    return name_ + " " + lastName_ + "; " + address_ + "; " 
    + pesel_ + "; " + getGenderString() + "; " + std::to_string(salary_);
};
std::string Employee::getLastName() const{
    return lastName_;
};
std::string Employee::getPesel() const{
    return pesel_;
};
Gender Employee::getGender() const{
    return gender_;
};