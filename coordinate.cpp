#include "coordinate.h"
#include <iostream>

coordinate::coordinate(int x, int y) {
    this->x = x;
    this->y = y;
}

int coordinate::getX() const {
    return this->x;
}

int coordinate::getY() const {
    return this->y;
}

void coordinate::setX(int x) {
    this->x = x;
}

void coordinate::setY(int y) {
    this->y = y;
}

std::string coordinate::toString() const {
    return "{" + std::to_string(this->x) + ";" +
        std::to_string(this->y) + "}";
}

void coordinate::print() const {
    std::cout << this->toString() << std::endl;
}