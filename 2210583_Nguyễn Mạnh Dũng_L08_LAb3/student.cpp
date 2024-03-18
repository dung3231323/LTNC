#include "student.h"
#include <iostream>

// Constructor
Student::Student(std::string name, float score) : name(name), score(score) {}

// Destructor
Student::~Student() {}

// Accessors
std::string Student::getName() const {
    return name;
}

float Student::getScore() const {
    return score;
}

// Display student information
void Student::display() const {
    std::cout << "Name: " << name << ", Score: " << score << std::endl;
}
