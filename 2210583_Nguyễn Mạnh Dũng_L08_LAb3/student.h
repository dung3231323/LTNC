#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
private:
    std::string name;
    float score;

public:
    // Constructor
    Student(std::string name, float score);

    // Destructor
    ~Student();

    // Accessors
    std::string getName() const;
    float getScore() const;

    // Display student information
    void display() const;
};



#endif // STUDENT_H
