#pragma once
#include <vector>
#include <memory>
#include "student.hpp"
#include "employee.hpp"

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

private:
    std::vector<std::shared_ptr<Person>> students_;
    bool lastNumberAlgorithm(const std::string& pesel) const;
    bool checkPeselString(const std::string& pesel) const;
};