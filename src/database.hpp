#pragma once
#include "student.hpp"

class Database {
public:
    bool add(const Student& s);
    void display() const;

private:
    bool isAdded_ = false;
};