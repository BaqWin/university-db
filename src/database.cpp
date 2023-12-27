#include "database.hpp"
#include <iostream>

void Database::add(const Student& s) {
    students_.push_back(s);
}

void Database::display() const {
    std::cout << show();
}

std::string Database::show() const{
    std::string result = "";
    for(auto && student : students_){
        result += student.show() + "\n";
    }
    return result;
}

std::string Database::findByName(const std::string& name){
    for(auto student : students_){
        if(student.getLastName() == name){
            return student.show();
        }
    }
    return "Nie ma takiego studenta";
}

std::string Database::findByPesel(const std::string& pesel){
    for(auto student : students_){
        if(student.getPesel() == pesel){
            return student.show();
        }
    }
    return "Nie ma takiego studenta";
}