#pragma once
#include "person.hpp"

class Employee : public Person {
public:
    Employee();
    Employee(
        std::string name,
        std::string lastName,
        std::string address,
        std::string pesel,
        Gender gender,
        int salary);
    ~Employee() override;

    std::string show() const override;
    std::string getLastName() const override;
    std::string getPesel() const override;
    Gender getGender() const override;
    int getSalary() const;
    void setSalary(const int& salary);
    void serialize(std::ostream& out) const override;
    void deserialize(std::istream& in) override;
    std::type_index getType() const override;

private:
    int salary_;
};