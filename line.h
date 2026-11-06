#ifndef LINE_H_
#define LINE_H_

#include <string>
#include "coordinate.h"

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

#endif  