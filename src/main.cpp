#include <iostream>
#include "person.hpp"
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
        123457,
        "11223344565",
        Gender::Male
    };
    Student maciek{
        "Maciek",
        "Tkacz",
        "ul. Dobra 134, 00-200 Warszawa",
        123458,
        "11223344566",
        Gender::Male
    };
    Student lukasz{
        "Łukasz",
        "Patrz",
        "ul. Dobra 134, 00-200 Warszawa",
        123458,
        "55030101193",
        Gender::Male
    };
    db.add(adam);
    db.add(janusz);
    db.add(maciek);
    db.sortByLastName();
    std::cout << db.show();
    std::cout << "-------------------------------" << std::endl;
    db.sortByPesel();
    std::cout << db.removeByIndexNumber(123457) << std::endl;
    std::cout << db.show();
    std::cout << lukasz.getPesel() << std::endl;
    db.peselValidation(lukasz);
}