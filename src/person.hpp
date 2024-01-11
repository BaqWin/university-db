#pragma once
#include <map>
#include <string>
#include <iostream>
#include <typeindex>

enum class Gender {
    Male,
    Female
};

class Person {
public:
    Person();
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
    virtual void serialize(std::ostream& out) const = 0;
    virtual void deserialize(std::istream& in) = 0;
    void serializeString(const std::string& str, std::ostream& out) const;
    void deserializeString(std::string& str, std::istream& in);
    void setGenderFromString(const std::string& gender);
    virtual std::type_index getType() const = 0;

protected:
    std::string name_;
    std::string lastName_;
    std::string address_;
    std::string pesel_;
    Gender gender_;

private:
    static const std::map<Gender, std::string> genderMap;
};