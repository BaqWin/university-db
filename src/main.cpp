#include <iostream>
#include <memory>
#include "person.hpp"
#include "student.hpp"
#include "database.hpp"

int main(){
    Database db;
    auto ptr1 = std::make_shared<Student>(
        "Adam",
        "Kowalski",
        "ul. Dobra 134, 00-200 Warszawa",
        123456,
        "11223344567",
        Gender::Male
    );
    auto ptr2 = std::make_shared<Student>(
        "Janusz",
        "Tracz",
        "ul. Dobra 134, 00-200 Warszawa",
        123457,
        "11223344565",
        Gender::Male
    );
    auto ptr3 = std::make_shared<Student>(
        "Maciek",
        "Tkacz",
        "ul. Dobra 134, 00-200 Warszawa",
        123458,
        "11223344566",
        Gender::Male
    );
    auto ptr4 = std::make_shared<Student>(
        "Łukasz",
        "Patrz",
        "ul. Dobra 134, 00-200 Warszawa",
        123459,
        "55030101193",
        Gender::Male
    );
    auto ptr5 = std::make_shared<Employee>(
        "Marcin",
        "Tracz",
        "ul. Dobra 134, 00-200 Warszawa",
        "11223344567",
        Gender::Male,
        7000
    );
    db.add(ptr1);
    db.add(ptr2);
    db.add(ptr3);
    db.add(ptr4);
    db.add(ptr5);
    db.display();
    std::cout << "--------------------------------------------------------------\n";
    std::cout << db.findByName(ptr1->getLastName()) << std::endl;
    std::cout << db.findByPesel(ptr2->getPesel()) << std::endl;
    std::cout << "--------------------------------------------------------------\n";
    db.sortByPesel();
    db.display();
    std::cout << "--------------------------------------------------------------\n";
    db.sortByLastName();
    db.display();
    std::cout << "--------------------------------------------------------------\n";
    //auto ptr5 = std::dynamic_pointer_cast<Student>(ptr1);
    std::cout << ptr1->getIndexNumber() << std::endl;
    std::cout << db.removeByIndexNumber(ptr1->getIndexNumber()) << std::endl;
    db.display();
}