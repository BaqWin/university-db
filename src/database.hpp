#pragma once
#include <memory>
#include <vector>
#include <iostream>
#include <map>
#include "employee.hpp"
#include "student.hpp"

class Database {
public:
    std::string add(const std::shared_ptr<Person>& ptr);
    std::string show() const;
    std::string findByName(const std::string& name);
    std::shared_ptr<Person> findByPesel(const std::string& pesel);
    void sortByPesel();
    void sortByLastName();
    std::string removeByIndexNumber(const int& index);
    bool peselValidation(const std::shared_ptr<Person>& ptr) const;
    void sortBySalary();
    std::string findByPeselAndChangeSalary(const std::string& pesel, const int& salary);
    void serialize(std::ostream& out);
    void deserialize(std:: istream& in);

    template<typename T>
    void registerType(const std::string& typeName){
        typeMap[typeName] = []() -> std::unique_ptr<Person> {
            return std::make_unique<T>();
        };
        reverseTypeMap[typeid(T)] = typeName;
    }

private:
    std::vector<std::shared_ptr<Person>> people_;
    bool lastNumberAlgorithm(const std::string& pesel) const;
    bool checkPeselString(const std::string& pesel) const;
    std::map<std::string, std::unique_ptr<Person>(*)()> typeMap;
    std::map<std::type_index, std::string> reverseTypeMap;
};