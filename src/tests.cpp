#include <gtest/gtest.h>
#include "database.hpp"
#include "student.hpp"

struct DatabaseTest : ::testing::Test {
    Database db;
};
struct StudentTest : ::testing::Test{
    Student adam{
        "Adam",
        "Kowalski",
        "ul. Dobra 134, 00-200 Warszawa",
        123456,
        "11223344567",
        Gender::Male
    };
};

TEST_F(DatabaseTest, DisplayEmptyDb) {
    auto content = db.show();
    auto expected = "";
    EXPECT_EQ(content, expected);
}

TEST_F(DatabaseTest, DisplayNonEmptyDb) {
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
        "11223344567",
        Gender::Male
    };
    db.add(adam);
    
    db.add(janusz);
    //check adding the same person twice
    
    auto content = db.show();
    auto expected = "Adam Kowalski; ul. Dobra 134, 00-200 Warszawa; 123456; 11223344567; Male\nJanusz Tracz; ul. Dobra 134, 00-200 Warszawa; 123456; 11223344567; Male\n";
    EXPECT_EQ(content, expected);
}

TEST_F(StudentTest, CheckGetterFunction){
    auto content = adam.getLastName();
    auto expected = "Kowalski";
    EXPECT_EQ(content, expected);
}
