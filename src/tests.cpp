#include <gtest/gtest.h>
#include <memory>
#include "database.hpp"
#include "person.hpp"
#include "student.hpp"
#include "employee.hpp"

struct DatabaseTest : ::testing::Test {
    Database db;
    std::shared_ptr<Student> adam = std::make_shared<Student>(
        "Adam",
        "Kowalski",
        "ul. Dobra 134, 00-200 Warszawa",
        123456,
        "11223344567",
        Gender::Male
    );
    std::shared_ptr<Student> janusz = std::make_shared<Student>(
        "Janusz",
        "Tracz",
        "ul. Dobra 134, 00-200 Warszawa",
        123457,
        "11223344565",
        Gender::Male
    );
    std::shared_ptr<Student> maciek = std::make_shared<Student>(
        "Maciek",
        "Tkacz",
        "ul. Dobra 134, 00-200 Warszawa",
        123458,
        "11223344566",
        Gender::Male
    );
    std::shared_ptr<Student> lukasz = std::make_shared<Student>(
        "Łukasz",
        "Patrz",
        "ul. Dobra 134, 00-200 Warszawa",
        123459,
        "55030101193",
        Gender::Male
    );
    std::shared_ptr<Employee> aleksandra = std::make_shared<Employee>(
        "Aleksandra",
        "Daniel",
        "ul. Dobra 134, 00-200 Warszawa",
        "11223344567",
        Gender::Female,
        7000
    );
};
struct StudentTest : ::testing::Test{
    std::shared_ptr<Student> adam = std::make_shared<Student>(
        "Adam",
        "Kowalski",
        "ul. Dobra 134, 00-200 Warszawa",
        123456,
        "11223344567",
        Gender::Male
    );
};

struct EmployeeTest : ::testing::Test{
    std::shared_ptr<Employee> marcin = std::make_shared<Employee>(
        "Marcin",
        "Tracz",
        "ul. Dobra 134, 00-200 Warszawa",
        "11223344567",
        Gender::Male,
        7000
    );
};

TEST_F(DatabaseTest, DisplayEmptyDb) {
    auto content = db.show();
    auto expected = "";
    EXPECT_EQ(content, expected);
}

TEST_F(DatabaseTest, DisplayNonEmptyDb) {
    db.add(adam);
    db.add(janusz);
    db.add(aleksandra);
    db.add(aleksandra);
    //check adding the same person twice
    
    auto content = db.show();
    auto expected = "Adam Kowalski; ul. Dobra 134, 00-200 Warszawa; 123456; 11223344567; Male\nJanusz Tracz; ul. Dobra 134, 00-200 Warszawa; 123457; 11223344565; Male\nAleksandra Daniel; ul. Dobra 134, 00-200 Warszawa; 11223344567; Female; 7000\n";
    EXPECT_EQ(content, expected);
}

TEST_F(StudentTest, CheckGetterFunction){
    auto content = adam->getLastName();
    auto expected = "Kowalski";
    EXPECT_EQ(content, expected);
}

TEST_F(DatabaseTest, CheckStudentByNameSuccess){
    db.add(adam);
    auto content = db.findByName("Kowalski");
    auto expected = "Adam Kowalski; ul. Dobra 134, 00-200 Warszawa; 123456; 11223344567; Male";
    EXPECT_EQ(content, expected);
}

TEST_F(DatabaseTest, CheckStudentByNameFail){
    db.add(adam);
    auto content = db.findByName("Tracz");
    auto expected = "Nie ma takiego studenta";
    EXPECT_EQ(content, expected);
}

TEST_F(DatabaseTest, CheckStudentByPeselSuccess){
    db.add(adam);
    auto content = db.findByName("Kowalski");
    auto expected = "Adam Kowalski; ul. Dobra 134, 00-200 Warszawa; 123456; 11223344567; Male";
    EXPECT_EQ(content, expected);
}

TEST_F(DatabaseTest, CheckStudentByPeselFail){
    db.add(adam);
    auto content = db.findByName("Tracz");
    auto expected = "Nie ma takiego studenta";
    EXPECT_EQ(content, expected);
}

TEST_F(DatabaseTest, CheckSortingByPesel){
    db.add(adam);
    db.add(janusz);
    db.sortByPesel();
    auto content = db.show();
    auto expected = "Janusz Tracz; ul. Dobra 134, 00-200 Warszawa; 123457; 11223344565; Male\nAdam Kowalski; ul. Dobra 134, 00-200 Warszawa; 123456; 11223344567; Male\n";
    EXPECT_EQ(content, expected);
}

TEST_F(DatabaseTest, CheckDeletingStudent){
    db.add(adam);
    db.add(janusz);
    db.add(maciek);
    auto content = db.removeByIndexNumber(123457);
    auto expected = "Student deleted!";
    EXPECT_EQ(content, expected);
}

TEST_F(DatabaseTest, CheckDeletingStudentAndSortingByPesel){
    db.add(adam);
    db.add(janusz);
    db.add(maciek);
    db.sortByPesel();
    db.removeByIndexNumber(123457);
    auto content = db.show();
    auto expected = "Maciek Tkacz; ul. Dobra 134, 00-200 Warszawa; 123458; 11223344566; Male\nAdam Kowalski; ul. Dobra 134, 00-200 Warszawa; 123456; 11223344567; Male\n";
    EXPECT_EQ(content, expected);
}

TEST_F(DatabaseTest, CheckSortingByLastName){
    db.add(adam);
    db.add(janusz);
    db.add(maciek);
    db.sortByLastName();
    auto content = db.show();
    auto expected = "Adam Kowalski; ul. Dobra 134, 00-200 Warszawa; 123456; 11223344567; Male\nMaciek Tkacz; ul. Dobra 134, 00-200 Warszawa; 123458; 11223344566; Male\nJanusz Tracz; ul. Dobra 134, 00-200 Warszawa; 123457; 11223344565; Male\n";
    EXPECT_EQ(content, expected);
}

TEST_F(DatabaseTest, CheckPeselValidationTrue){
    std::shared_ptr<Student> lukasz = std::make_shared<Student>(
        "Łukasz",
        "Patrz",
        "ul. Dobra 134, 00-200 Warszawa",
        123458,
        "55030101193",
        Gender::Male
    );
    EXPECT_TRUE(db.peselValidation(lukasz));
}

TEST_F(DatabaseTest, CheckPeselValidationTrueSecond){
    std::shared_ptr<Student> patryk = std::make_shared<Student>(
        "Patryk",
        "Patrz",
        "ul. Dobra 134, 00-200 Warszawa",
        123458,
        "55030101230",
        Gender::Male
    );
    EXPECT_TRUE(db.peselValidation(patryk));
}

TEST_F(DatabaseTest, CheckPeselValidationFalse){
    EXPECT_FALSE(db.peselValidation(maciek));
}

TEST_F(DatabaseTest, CheckPeselValidationWrongPeselString){
    std::shared_ptr<Student> patryk = std::make_shared<Student>(
        "Patryk",
        "Patrz",
        "ul. Dobra 134, 00-200 Warszawa",
        123458,
        "5503a101230",
        Gender::Male
    );
    EXPECT_FALSE(db.peselValidation(patryk));
}

TEST_F(EmployeeTest, CheckEmployeeInitialization){
    auto content = marcin->show();
    auto expected = "Marcin Tracz; ul. Dobra 134, 00-200 Warszawa; 11223344567; Male; 7000";
    EXPECT_EQ(content, expected);
}

TEST_F(EmployeeTest, CheckEmployeeGender){
    Employee aleksandra{
        "Aleksandra",
        "Daniel",
        "ul. Dobra 134, 00-200 Warszawa",
        "11223344567",
        Gender::Female,
        7000
    };
    auto content = aleksandra.show();
    auto expected = "Aleksandra Daniel; ul. Dobra 134, 00-200 Warszawa; 11223344567; Female; 7000";
    EXPECT_EQ(content, expected);
}