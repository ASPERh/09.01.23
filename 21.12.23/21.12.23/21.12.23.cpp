#include <iostream>
#include <string>
#include "Student.h"

using namespace std;

class Group {
private:
    Student** students;
    int numOfStudents;
    string groupName;
    string specialization;
    int courseNumber;

public:
    Group() : students(nullptr), numOfStudents(0), groupName(""), specialization(""), courseNumber(0) {}

    Group(const Group& other) : numOfStudents(other.numOfStudents), groupName(other.groupName),
        specialization(other.specialization), courseNumber(other.courseNumber) {
        students = new Student * [numOfStudents];
        for (int i = 0; i < numOfStudents; ++i) {
            students[i] = new Student(*(other.students[i]));
        }
    }

    ~Group() {

        for (int i = 0; i < numOfStudents; ++i) {
            delete students[i];
        }
        delete[] students;
    }
};