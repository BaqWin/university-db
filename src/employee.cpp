#include "employee.hpp"

Employee::Employee() {}

Employee::Employee(std::string name, std::string lastName, std::string address, std::string pesel, Gender gender, int salary)
    : Person(name, lastName, address, pesel, gender), salary_(salary) {}

Employee::~Employee() {}

std::string Employee::show() const {
    return name_ + " " + lastName_ + "; " + address_ + "; " + pesel_ + "; " + getGenderString() + "; " + std::to_string(salary_);
};
std::string Employee::getLastName() const {
    return lastName_;
};
std::string Employee::getPesel() const {
    return pesel_;
};
Gender Employee::getGender() const {
    return gender_;
};

int Employee::getSalary() const {
    return salary_;
}

void Employee::setSalary(const int& salary) {
    salary_ = salary;
}

void Employee::serialize(std::ostream& out) const{
    serializeString(name_, out);
    serializeString(lastName_, out);
    serializeString(address_, out);
    serializeString(pesel_, out);
    serializeString(getGenderString(), out);
    out.write(reinterpret_cast<const char*>(&salary_), sizeof(salary_));
}

void Employee::deserialize(std::istream& in){
    deserializeString(name_, in);
    deserializeString(lastName_, in);
    deserializeString(address_, in);
    deserializeString(pesel_, in);
    std::string gender;
    deserializeString(gender, in);
    setGenderFromString(gender);
    in.read(reinterpret_cast<char*>(&salary_), sizeof(salary_));
}

std::type_index Employee::getType() const{
    return typeid(*this);
}
