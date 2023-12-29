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

void Database::sortByPesel(){
    sort(students_.begin(), students_.end(), [](const Student& s1, const Student & s2){
        return (std::stol(s1.getPesel()) < std::stol(s2.getPesel()));
    });
}

std::string Database::removeByIndexNumber(const int& indexNumber){
    auto it = find_if(students_.begin(), students_.end(), [&](const Student& s){
        return (s.getIndexNumber() == indexNumber);
    });
    
    if(it != students_.end()){
        students_.erase(it);
        return "Student deleted!";
    }else{
        return "There is no student with this index number";
    }
}