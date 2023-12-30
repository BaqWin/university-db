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

void Database::sortByLastName(){
    sort(students_.begin(), students_.end(), [](const Student& s1, const Student & s2){
        return (s1.getLastName() < s2.getLastName());
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

bool Database::peselValidation(const Student& s) const{
    //TODO Birth Date validation
    auto peselString = s.getPesel();
    if(peselString.length() == 11 && checkPeselString(peselString)){
        if((int(peselString.at(9)) % 2) == 0 && s.getGender() == Gender::Female){
            return lastNumberAlgorithm(peselString);
        }else if((int(peselString.at(9)) % 2) != 0 && s.getGender() == Gender::Male){
            return lastNumberAlgorithm(peselString);
        }
    }
    return false;
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