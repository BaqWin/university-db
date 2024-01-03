#include "database.hpp"
#include <iostream>
#include <array>
#include <algorithm>

void Database::add(const std::shared_ptr<Person>& ptr) {
    for(auto x : students_){
        if(x->getPesel() == ptr->getPesel()){
            std::cout << "This Person already exists!\n";
            return;
        }
    }
    students_.push_back(ptr);
}

void Database::display() const {
    std::cout << show();
}

std::string Database::show() const{
    std::string result = "";
    for(auto && ptr : students_){
        result += ptr->show() + "\n";
    }
    return result;
}

std::string Database::findByName(const std::string& name){
    for(auto ptr : students_){
        if(ptr->getLastName() == name){
            return ptr->show();
        }
    }
    return "Nie ma takiego studenta";
}

std::string Database::findByPesel(const std::string& pesel){
    for(auto ptr : students_){
        if(ptr->getPesel() == pesel){
            return ptr->show();
        }
    }
    return "Nie ma takiego studenta";
}

void Database::sortByPesel(){
    std::sort(students_.begin(), students_.end(), [](const auto& s1, const auto & s2){
        return (std::stol(s1->getPesel()) < std::stol(s2->getPesel()));
    });
}

void Database::sortByLastName(){
    std::sort(students_.begin(), students_.end(), [](const auto& s1, const auto & s2){
        return (s1->getLastName() < s2->getLastName());
    });
}

std::string Database::removeByIndexNumber(const int& indexNumber){
    auto it = std::find_if(students_.begin(), students_.end(), [&](const auto& s){
        auto ptr = std::dynamic_pointer_cast<Student>(s);
        return (ptr->getIndexNumber() == indexNumber);
    });
    
    if(it != students_.end()){
        students_.erase(it);
        return "Student deleted!";
    }else{
        return "There is no student with this index number";
    }
}

bool Database::peselValidation(const std::shared_ptr<Person>& ptr) const{
    //TODO Birth Date validation
    auto peselString = ptr->getPesel();
    if(peselString.length() == 11 && checkPeselString(peselString)){
        if((int(peselString.at(9)) % 2) == 0 && ptr->getGender() == Gender::Female){
            return lastNumberAlgorithm(peselString);
        }else if((int(peselString.at(9)) % 2) != 0 && ptr->getGender() == Gender::Male){
            return lastNumberAlgorithm(peselString);
        }
    }
    return false;
}

void Database::sortBySalary(){
    std::sort(students_.begin(), students_.end(), [](const auto& s1, const auto & s2){
        auto ptr1 = std::dynamic_pointer_cast<Employee>(s1);
        auto ptr2 = std::dynamic_pointer_cast<Employee>(s2);
        if(ptr1 != NULL && ptr2 != NULL){
            return (ptr1->getSalary() < ptr2->getSalary());
        }
        return true;
    });
}

bool Database::lastNumberAlgorithm(const std::string& pesel) const{
    int sum = 0;
    std::array<int,4> multiplier{1, 3, 7, 9};
    for(size_t i = 0, j = 0; i < pesel.length() - 1; i++){
        if(j >= multiplier.size()){
            j = 0;
        }
        sum += int(pesel.at(i) - '0') * multiplier.at(j);
        j++;
    }
    int m = int(std::to_string(sum).back() - '0');
    int finalChar = int(pesel.back() - '0');
    if(m == 0 && finalChar == 0){
        return true;
    }else if((10 - m) == finalChar){
        return true;
    }else{
        return false;
    }
}

bool Database::checkPeselString(const std::string& pesel) const{
    int tmp = -1;
    for(auto c : pesel){
        tmp = int(c - '0');
        if(tmp > 9 || tmp < 0){
            return false;
        }
    }
    return true;
}