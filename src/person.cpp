#include "person.hpp"

Person::Person() {}

Person::Person(std::string name, std::string lastName, std::string address, std::string pesel, Gender gender)
    : name_(name), lastName_(lastName), address_(address), pesel_(pesel), gender_(gender) {}

Person::~Person() {}

std::string Person::getGenderString() const {
    return genderMap.at(gender_);
}

const std::map<Gender, std::string> Person::genderMap{
    {Gender::Male, "Male"},
    {Gender::Female, "Female"}};

void Person::serializeString(const std::string& str, std::ostream& out) const{
    size_t length = str.size();
    out.write(reinterpret_cast<const char*>(&length), sizeof(length));
    out.write(str.data(), length);
}
void Person::deserializeString(std::string& str, std::istream& in) {
    size_t length;
    if (in.read(reinterpret_cast<char*>(&length), sizeof(length))) {
        str.resize(length);
        if (length > 0) {
            in.read(&str[0], length);
        }
    }
    if (!in) {
        return;
    }
}

void Person::setGenderFromString(const std::string& gender){
    if(gender == "Male"){
        gender_ = Gender::Male;
    }else if(gender == "Female"){
        gender_ = Gender::Female;
    }
}