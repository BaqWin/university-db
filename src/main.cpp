#include <fstream>
#include <iostream>
#include <memory>
#include "database.hpp"
#include "person.hpp"
#include "student.hpp"

void showInfo() {
    std::cout << "Type: 1 - To Show the Database\n"
              << "Type: 2 - To add new Person to the Database\n"
              << "Type: 3 - To search for a student by his Last Name\n"
              << "Type: 4 - To search for a student by his PESEL\n"
              << "Type: 5 - To sort Database by PESEL\n"
              << "Type: 6 - To sort Database by Last Name\n"
              << "Type: 7 - Delete user by his Index Number\n"
              << "Type: 8 - To Save state of Database\n"
              << "Type: 9 - To Load state of Database\n"
              << "Type: 0 - To leave the application\n"
              << "-------------------------------------------------------\n";
}

void addService(Database& db) {
    int n = -1;
    std::cout << "Type: 1 - To add new Student\n"
              << "Type: 2 - To add new Employee\n"
              << "Type a number of a person you want to add to the Database:";
    std::cin >> n;
    if (n != 1 && n != 2) {
        std::cout << "\033[1;31mWrong number!\033[0m\n";
        return;
    }
    std::string name;
    std::string lastName;
    std::string address;
    std::string pesel;
    std::string gender;
    Gender genderType;
    std::cout << "Adding Student\n"
              << "Type First Name:";
    std::cin >> name;
    std::cout << "Type Last Name:";
    std::cin >> lastName;
    std::cout << "Type Address:";
    std::cin >> address;
    std::cout << "Type PESEL (11 Numbers):";
    std::cin >> pesel;
    if(pesel.length() != 11){
        std::cout << "\033[1;31mWrong PESEL number!\033[0m\n";
        return;
    }
    std::cout << "Type Gender (Male or Female):";
    std::cin >> gender;
    if (gender == "Male") {
        genderType = Gender::Male;
    } else if (gender == "Female") {
        genderType = Gender::Female;
    }else {
        std::cout << "\033[1;31mWrong gender!\033[0m\n";
        return;
    }
    if (n == 1) {
        int index;
        std::cout << "Type Index Number:";
        std::cin >> index;
        std::cout << db.add(std::make_shared<Student>(name, lastName, address, index, pesel, genderType))
        << '\n';
    } else if (n == 2) {
        int salary;
        std::cout << "Type Salary:";
        std::cin >> salary;
        std::cout << db.add(std::make_shared<Employee>(name, lastName, address, pesel, genderType, salary))
        << '\n';
    }
}

void start() {
    Database db;
    db.registerType<Employee>("Employee");
    db.registerType<Student>("Student");

    std::ofstream outFile;
    std::ifstream inFile;
    std::string temp;

    bool loop = true;
    while (loop) {
        int n = -1;
        showInfo();
        std::cout << "Type a number to a corresponding action:";
        std::cin >> n;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\033[1;31mInvalid input. Please provide a number.\033[0m\n";
        } else if (n < 10 && n >= 0) {
            switch (n) {
            case 0:
                std::cout << "Thank you for checking the app :)\n";
                loop = false;
                break;
            case 1:
                std::cout << '\n' << db.show() << std::endl;
                break;
            case 2:
                addService(db);
                break;
            case 3:
                std::cout << "Type Last Name you want to find:";
                std::cin >> temp;
                std::cout << db.findByName(temp) << '\n';
                break;
            case 8:
                outFile.open("database.bin", std::ios::binary);
                db.serialize(outFile);
                outFile.close();
                break;
            case 9:
                inFile.open("database.bin", std::ios::binary);
                db.deserialize(inFile);
                inFile.close();
                std::cout << "Database loaded!\n";
                break;
            }
        } else {
            std::cout << "\033[1;31mPlease provide numbers between 0-10\033[0m\n";
        }
        std::cout << "-------------------------------------------------------\n";
    }
}

int main() {
    start();
    // TODO Program loop
    // TODO zrobic typ danych dla adresu
}