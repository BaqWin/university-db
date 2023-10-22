#include <gtest/gtest.h>
#include "database.hpp"
#include "student.hpp"

TEST(CheckStructure, CanAddStudentToDb_Req1_Req2) {
<<<<<<< HEAD
    Student adam{
        "Adam",
        "Kowalski",
        "ul. Dobra 134, 00-200 Warszawa",
        123456,
        "11223344567",
        Gender::Male
        };
=======
  Student adam{
      "Adam", 
      "Kowalski", 
      "ul. Dobra 134, 00-200 Warszawa",
      123456,
      "11223344567",
      Gender::Male
    };
>>>>>>> 962118dafb65266cd627f2ee5e12785540bf706e

    Database db;
    EXPECT_TRUE(db.add(adam));
    EXPECT_FALSE(db.add(adam));
<<<<<<< HEAD
}

TEST(DisplayDb, DisplayEmptyDb) {
    Database db;
    db.display();
}

/*TEST(DisplayDb, DisplayNonEmptyDb) {
    Database db;
    Student adam{
        "Adam",
        "Kowalski",
        "ul. Dobra 134, 00-200 Warszawa",
        123456,
        "11223344567",
        Gender::Male
      };
    EXPECT_TRUE(db.add(adam));
    db.display();
}*/
=======
}
>>>>>>> 962118dafb65266cd627f2ee5e12785540bf706e
