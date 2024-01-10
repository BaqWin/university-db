#pragma once
#include <map>
#include <string>

enum class Gender {
    Male,
    Female
};

class Person {
public:
    Person(
        std::string name,
        std::string lastName,
        std::string address,
        std::string pesel,
        Gender gender);
    virtual std::string show() const = 0;
    virtual std::string getLastName() const = 0;
    virtual std::string getPesel() const = 0;
    virtual Gender getGender() const = 0;
    virtual ~Person();
    std::string getGenderString() const;

protected:
    std::string name_;
    std::string lastName_;
    std::string address_;
    std::string pesel_;
    Gender gender_;

private:
    static const std::map<Gender, std::string> genderMap;
};