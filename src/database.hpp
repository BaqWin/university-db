#pragma once
#include <vector>
#include "student.hpp"

class Database {
public:
    void add(const Student& s);
    void display() const;
    std::string show() const;
    std::string findByName(const std::string& name);
    std::string findByPesel(const std::string& pesel);
    void sortByPesel();
    void sortByLastName();
    std::string removeByIndexNumber(const int& index);
    bool peselValidation(const Student& s) const;

private:
    std::vector<Student> students_;
    bool lastNumberAlgorithm(const std::string& pesel) const;
};