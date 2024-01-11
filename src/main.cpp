#include <iostream>
#include <memory>
#include <fstream>
#include "database.hpp"
#include "person.hpp"
#include "student.hpp"

void showInfo(){
    std::cout << "Type: 1 - To Show the Database\n"
    << "Type: 2 - To add new Person to the Database\n"
    << "Type: 3 - To search for a student by his Last Name\n"
    << "Type: 4 - To search for a student by his PESEL\n"
    << "Type: 5 - To sort Database by PESEL\n"
    << "Type: 6 - To sort Database by Last Name\n"
    << "Type: 7 - Delete user by his Index Number\n"
    << "Type: 8 - To Save state of Database\n"
    << "Type: 9 - To Save state of Database\n"
    << "Type: 0 - To leave the application\n"
    << "-------------------------------------------------------\n";
}

void addService(){
    int n = -1;
    std::cout << "Type a number of a person you want to add to the Database:\n"
    << "Type: 1 - To add new Student\n"
    << "Type: 2 - To Show new Employee\n";
    std::cin >> n;
    if(n == 1){
        std::cout << "Adding Student\n";
    }else if(n == 2){
        std::cout << "Adding Employee\n";
    }else{
        std::cout << "\033[1;31mWrong number!\033[0m\n";
        return;
    }
}

void start(){
    Database db;
    bool loop = true;
    while (loop){
        int n = -1;
        showInfo();
        std::cout << "Type a number to a corresponding action:";
        std::cin >> n;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\033[1;31mInvalid input. Please provide a number.\033[0m\n";
        } else if(n < 10 && n >= 0){
            switch(n){
                case 0:
                    std::cout << "Thank you for checking the app :)\n";
                    loop = false;
                    break;
                case 1:
                    std::cout << db.show() << std::endl;
                    break;
                case 2:
                    addService();
                    break;
            }
        }else{
            std::cout << "\033[1;31mPlease provide numbers between 0-10\033[0m\n";
        }
    }
}

int main() {
    start();

    // auto ptr1 = std::make_shared<Student>(
    //     "Adam",
    //     "Kowalski",
    //     "ul. Dobra 134, 00-200 Warszawa",
    //     123456,
    //     "11223344567",
    //     Gender::Male);
    // auto ptr2 = std::make_shared<Student>(
    //     "Janusz",
    //     "Tracz",
    //     "ul. Dobra 134, 00-200 Warszawa",
    //     123457,
    //     "11223344565",
    //     Gender::Male);
    // auto ptr3 = std::make_shared<Student>(
    //     "Maciek",
    //     "Tkacz",
    //     "ul. Dobra 134, 00-200 Warszawa",
    //     123458,
    //     "11223344566",
    //     Gender::Male);
    // auto ptr4 = std::make_shared<Student>(
    //     "Łukasz",
    //     "Patrz",
    //     "ul. Dobra 134, 00-200 Warszawa",
    //     123459,
    //     "55030101193",
    //     Gender::Male);
    // auto ptr5 = std::make_shared<Employee>(
    //     "Marcin",
    //     "Tracz",
    //     "ul. Dobra 134, 00-200 Warszawa",
    //     "11223344570",
    //     Gender::Male,
    //     7000);
    // std::shared_ptr<Employee> aleksandra = std::make_shared<Employee>(
    //     "Aleksandra",
    //     "Daniel",
    //     "ul. Dobra 134, 00-200 Warszawa",
    //     "55030101231",
    //     Gender::Female,
    //     8500);
    // db.add(ptr1);
    // db.add(ptr1);
    // db.add(ptr2);
    // db.add(ptr3);
    // db.add(ptr4);
    // db.add(ptr5);
    // std::cout << "--------------------------------------------------------------\n";
    // std::cout << db.findByName(ptr1->getLastName()) << std::endl;
    // std::cout << db.findByPesel(ptr2->getPesel())->show() << std::endl;
    // std::cout << "--------------------------------------------------------------\n";
    // db.sortByPesel();
    // std::cout << "--------------------------------------------------------------\n";
    // db.sortByLastName();
    // std::cout << "--------------------------------------------------------------\n";
    // std::cout << ptr1->getIndexNumber() << std::endl;
    // std::cout << db.removeByIndexNumber(ptr1->getIndexNumber()) << std::endl;
    // std::cout << "--------------------------------------------------------------\n";
    // db.add(aleksandra);
    // db.sortBySalary();

    // std::cout << db.show();
    // db.registerType<Employee>("Employee");
    // db.registerType<Student>("Student");
    // // std::ofstream outFile("database.bin", std::ios::binary);
    // // db.serialize(outFile);
    // // outFile.close();
    // std::ifstream inFile("database.bin", std::ios::binary);
    // db.deserialize(inFile);
    // inFile.close();
    // std::cout << db.show();


    // TODO Program loop
    //TODO zrobic typ danych dla adresu
}