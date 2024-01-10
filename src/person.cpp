#include "person.hpp"

Person::Person(std::string name, std::string lastName, std::string address, std::string pesel, Gender gender)
    : name_(name), lastName_(lastName), address_(address), pesel_(pesel), gender_(gender) {}

Person::~Person() {}

std::string Person::getGenderString() const {
    return genderMap.at(gender_);
}

const std::map<Gender, std::string> Person::genderMap{
    {Gender::Male, "Male"},
    {Gender::Female, "Female"}};