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

private:
    std::vector<Student> students_;
    //static bool compareIntervalPesel(Student& s1, Student& s2);

};