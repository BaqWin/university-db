#pragma once
#include "person.hpp"

class Student : public Person {
public:
    Student(
        std::string name,
        std::string lastName,
        std::string address,
        int indexNumber,
        std::string pesel,
        Gender gender);
    ~Student() override;

    std::string show() const override;
    std::string getLastName() const override;
    std::string getPesel() const override;
    int getIndexNumber() const;
    Gender getGender() const override;
    void serialize(std::ostream& out) const override;
    void deserialize(std::istream& in) override;

private:
    using Person::Person;
    int indexNumber_;
};