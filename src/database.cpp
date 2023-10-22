#include "database.hpp"

<<<<<<< HEAD
bool Database::add(const Student& s) {
    if (isAdded_) {
=======
bool Database::add(const Student & s) {
    if(isAdded_) {
>>>>>>> 962118dafb65266cd627f2ee5e12785540bf706e
        return false;
    } else {
        isAdded_ = true;
        return true;
    }
<<<<<<< HEAD
}

void Database::display() const {
    
=======
>>>>>>> 962118dafb65266cd627f2ee5e12785540bf706e
}