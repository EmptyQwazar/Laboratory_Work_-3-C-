
#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>

class student {
private:
    std::string name;
    int* grades = nullptr;
    int gradesCount = 0;
    bool ownsGrades = false;

public:
    student(const std::string& name, int* grades, int count, bool owns = false);
    ~student();

    int* getGrades() const;
    int getGradesCount() const;

    void setGradesShallow(int* newGrades, int count);
    void setGradesDeep(const int* sourceGrades, int count);
    void setGradeAt(int index, int value);

    std::string toString() const;
    void print() const;
};

#endif  // STUDENT_H_