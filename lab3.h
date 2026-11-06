#ifndef LAB3_H_
#define LAB3_H_

#include <cmath>
#include <iostream>
#include <string>

int readInt();

class coordinate {
private:
    int x = 0;
    int y = 0;

public:
    coordinate(int x, int y);

    int getX() const;
    int getY() const;
    void setX(int x);
    void setY(int y);

    std::string toString() const;
    void print() const;
};


class line {
private:
    coordinate* start = nullptr;
    coordinate* end = nullptr;
    bool ownsStart = false;
    bool ownsEnd = false;

public:
    line(coordinate* start, coordinate* end);

    line(const coordinate& start, const coordinate& end);

    line(int x1, int y1, int x2, int y2);

    ~line();

    coordinate* getStart() const;
    coordinate* getEnd() const;
    void setStart(coordinate* newStart);
    void setEnd(coordinate* newEnd);
    void setStart(int x, int y);
    void setEnd(int x, int y);

    int getLength() const;

    std::string toString() const;
    void print() const;
};

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

void task1();
void task2();
void task3();
void task4();
void task5();

#endif