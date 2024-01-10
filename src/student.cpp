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

void Student::serialize(std::ostream& out) const{
    serializeString(name_, out);
    serializeString(lastName_, out);
    serializeString(address_, out);
    serializeString(pesel_, out);
    serializeString(getGenderString(), out);
    out.write(reinterpret_cast<const char*>(&indexNumber_), sizeof(indexNumber_));
}

void Student::deserialize(std::istream& in){
    deserializeString(name_, in);
    deserializeString(lastName_, in);
    deserializeString(address_, in);
    deserializeString(pesel_, in);
    std::string gender;
    deserializeString(gender, in);
    setGenderFromString(gender);
    in.read(reinterpret_cast<char*>(&indexNumber_), sizeof(indexNumber_));
}