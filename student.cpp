#include "student.h"
#include <iostream>

student::student(const std::string& name, int* grades,
    int count, bool owns) {
    this->name = name;
    this->grades = grades;
    this->gradesCount = count;
    this->ownsGrades = owns;
}

student::~student() {
    if (this->ownsGrades && this->grades != nullptr) {
        delete[] this->grades;
    }
}

int* student::getGrades() const {
    return this->grades;
}

int student::getGradesCount() const {
    return this->gradesCount;
}

void student::setGradesShallow(int* newGrades, int count) {
    if (this->ownsGrades && this->grades != nullptr) {
        delete[] this->grades;
    }
    this->grades = newGrades;
    this->gradesCount = count;
    this->ownsGrades = false;
}

void student::setGradesDeep(const int* sourceGrades, int count) {
    if (this->ownsGrades && this->grades != nullptr) {
        delete[] this->grades;
    }
    this->gradesCount = count;
    if (count > 0 && sourceGrades != nullptr) {
        this->grades = new int[count];
        for (int i = 0; i < count; ++i) {
            this->grades[i] = sourceGrades[i];
        }
        this->ownsGrades = true;
    }
    else {
        this->grades = nullptr;
        this->ownsGrades = false;
    }
}

void student::setGradeAt(int index, int value) {
    if (index >= 0 && index < this->gradesCount &&
        this->grades != nullptr) {
        this->grades[index] = value;
    }
}

std::string student::toString() const {
    std::string res = this->name + ": [";
    for (int i = 0; i < this->gradesCount; ++i) {
        res += std::to_string(this->grades[i]);
        if (i + 1 < this->gradesCount) {
            res += ", ";
        }
    }
    res += "]";
    return res;
}

void student::print() const {
    std::cout << this->toString() << std::endl;
}