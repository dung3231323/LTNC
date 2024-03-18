#include "student.h"
#include <iostream>

int main() {
    // Dynamically allocated array to store student objects
    Student **students = nullptr;
    int numStudents = 0;

    char choice;
    do {
        std::cout << "\nStudent Management System Menu\n";
        std::cout << "1. Add new student\n";
        std::cout << "2. Display all students\n";
        std::cout << "3. Display best student(s)\n";
        std::cout << "4. Remove a student\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch(choice) {
            case '1': {
                std::string name;
                int score;
                std::cout << "Enter student name: ";
                std::cin >> name;
                std::cout << "Enter student score: ";
                std::cin >> score;
                // Create a new student object using 'new' keyword
                Student *newStudent = new Student(name, score);

                // Resize the array to accommodate the new student
                Student **temp = new Student*[numStudents + 1];
                for (int i = 0; i < numStudents; ++i) {
                    temp[i] = students[i];
                }
                temp[numStudents] = newStudent;

                delete[] students;
                students = temp;
                numStudents++;

                std::cout << "Student added successfully.\n";
                break;
            }
            case '2': {
                std::cout << "\nList of all students:\n";
                for (int i = 0; i < numStudents; ++i) {
                    students[i]->display();
                }
                break;
            }
            case '3': {
                int maxScore = -1;
                std::cout << "\nBest student(s):\n";
                for (int i = 0; i < numStudents; ++i) {
                    if (students[i]->getScore() > maxScore) {
                        maxScore = students[i]->getScore();
                    }
                }
                for (int i = 0; i < numStudents; ++i) {
                    if (students[i]->getScore() == maxScore) {
                        students[i]->display();
                    }
                }
                break;
            }
            case '4': {
                std::string name;
                std::cout << "Enter the name of the student to remove: ";
                std::cin >> name;
                for (int i = 0; i < numStudents; ++i) {
                    if (students[i]->getName() == name) {
                        delete students[i]; // Free memory allocated to the student object
                        for (int j = i; j < numStudents - 1; ++j) {
                            students[j] = students[j + 1];
                        }
                        numStudents--;
                        std::cout << "Student removed successfully.\n";
                        break;
                    }
                }
                break;
            }
            case '5':
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != '5');

    // Free memory allocated to the array of student pointers
    for (int i = 0; i < numStudents; ++i) {
        delete students[i];
    }
    delete[] students;

    return 0;
}
