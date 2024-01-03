#pragma once
#include <vector>
#include <memory>
#include "student.hpp"
#include "employee.hpp"

class Database {
public:
    void add(const std::shared_ptr<Person>& ptr);
    void display() const;
    std::string show() const;
    std::string findByName(const std::string& name);
    std::string findByPesel(const std::string& pesel);
    void sortByPesel();
    void sortByLastName();
    std::string removeByIndexNumber(const int& index);
    bool peselValidation(const std::shared_ptr<Person>& ptr) const;

private:
    std::vector<std::shared_ptr<Person>> students_;
    bool lastNumberAlgorithm(const std::string& pesel) const;
    bool checkPeselString(const std::string& pesel) const;
};