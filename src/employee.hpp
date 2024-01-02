#pragma once
#include "person.hpp"

class Employee : public Person{
public:
    Employee(
        std::string name,
        std::string lastName,
        std::string address,
        std::string pesel,
        Gender gender,
        int salary
    );
    ~Employee() override;

    std::string show() const override;
    std::string getLastName() const override;
    std::string getPesel() const override;
    Gender getGender() const override;
private:
    int salary_;
};