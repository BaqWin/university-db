#pragma once
#include "student.hpp"

class Database {
public:
    bool add(const Student& s);
<<<<<<< HEAD
    void display() const;

=======
>>>>>>> 962118dafb65266cd627f2ee5e12785540bf706e
private:
    bool isAdded_ = false;
};