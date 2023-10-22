#include <gtest/gtest.h>
#include "database.hpp"
#include "student.hpp"

TEST(CheckStructure, CanAddStudentToDb_Req1_Req2) {
  Student adam{
      "Adam", 
      "Kowalski", 
      "ul. Dobra 134, 00-200 Warszawa",
      123456,
      "11223344567",
      Gender::Male
    };

    Database db;
    EXPECT_TRUE(db.add(adam));
    EXPECT_FALSE(db.add(adam));
}