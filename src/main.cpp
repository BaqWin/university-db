#include <iostream>
#include <memory>
#include <fstream>
#include "database.hpp"
#include "person.hpp"
#include "student.hpp"

int main() {
    Database db;

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

    std::cout << db.show();
    db.registerType<Employee>("Employee");
    db.registerType<Student>("Student");
    // std::ofstream outFile("database.bin", std::ios::binary);
    // db.serialize(outFile);
    // outFile.close();
    std::ifstream inFile("database.bin", std::ios::binary);
    db.deserialize(inFile);
    inFile.close();
    std::cout << db.show();


    // TODO Program loop
}