#include "student.hpp"

Student::Student(std::string name, std::string lastName, std::string address, int indexNumber, std::string pesel, Gender gender)
    : Person(name, lastName, address, pesel, gender), indexNumber_(indexNumber) {}

std::string Student::show() const {
    return name_ + " " + lastName_ + "; " + address_ + "; " + std::to_string(indexNumber_) + "; " + pesel_ + "; " + getGenderString();
}

std::string Student::getLastName() const {
    return lastName_;
}

std::string Student::getPesel() const {
    return pesel_;
}

int Student::getIndexNumber() const {
    return indexNumber_;
}

Gender Student::getGender() const {
    return gender_;
}

Student::~Student() {}
