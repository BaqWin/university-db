#include <iostream>
#include "student.hpp"
#include "database.hpp"

int main(){
    Database db;
    Student adam{
        "Adam",
        "Kowalski",
        "ul. Dobra 134, 00-200 Warszawa",
        123456,
        "11223344567",
        Gender::Male
    };
    Student janusz{
        "Janusz",
        "Tracz",
        "ul. Dobra 134, 00-200 Warszawa",
        123456,
        "11223344565",
        Gender::Male
    };
    db.add(adam);
    db.add(janusz);
    std::cout << db.show();
    std::cout << "-------------------------------" << std::endl;
    db.sortByPesel();
    std::cout << db.show();
}