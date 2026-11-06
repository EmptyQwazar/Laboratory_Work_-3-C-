#include "line.h"
#include <cmath>
#include <iostream>

line::line(coordinate* start, coordinate* end) {
    this->start = start;
    this->end = end;
    this->ownsStart = false;
    this->ownsEnd = false;
}

line::line(const coordinate& start, const coordinate& end) {
    this->start = new coordinate(start.getX(), start.getY());
    this->end = new coordinate(end.getX(), end.getY());
    this->ownsStart = true;
    this->ownsEnd = true;
}

line::line(int x1, int y1, int x2, int y2) {
    this->start = new coordinate(x1, y1);
    this->end = new coordinate(x2, y2);
    this->ownsStart = true;
    this->ownsEnd = true;
}

line::~line() {
    if (this->ownsStart && this->start != nullptr) {
        delete this->start;
    }
    if (this->ownsEnd && this->end != nullptr) {
        delete this->end;
    }
}

coordinate* line::getStart() const {
    return this->start;
}

coordinate* line::getEnd() const {
    return this->end;
}

void line::setStart(coordinate* newStart) {
    if (this->ownsStart && this->start != nullptr) {
        delete this->start;
    }
    this->start = newStart;
    this->ownsStart = false;
}

void line::setEnd(coordinate* newEnd) {
    if (this->ownsEnd && this->end != nullptr) {
        delete this->end;
    }
    this->end = newEnd;
    this->ownsEnd = false;
}

void line::setStart(int x, int y) {
    if (this->start != nullptr) {
        this->start->setX(x);
        this->start->setY(y);
    }
}

void line::setEnd(int x, int y) {
    if (this->end != nullptr) {
        this->end->setX(x);
        this->end->setY(y);
    }
}

int line::getLength() const {
    double dx = static_cast<double>(
        this->end->getX() - this->start->getX()
        );
    double dy = static_cast<double>(
        this->end->getY() - this->start->getY()
        );
    return static_cast<int>(std::round(
        std::sqrt(dx * dx + dy * dy)
    ));
}

std::string line::toString() const {
    return "Линия от " + this->start->toString() +
        " до " + this->end->toString();
}

void line::print() const {
    std::cout << this->toString() << std::endl;
}