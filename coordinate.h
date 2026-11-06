
#ifndef COORDINATE_H_
#define COORDINATE_H_

#include <string>

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

#endif  // COORDINATE_H_