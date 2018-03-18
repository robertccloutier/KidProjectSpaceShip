
#include "Point.h"
#include "Velocity.h"

point& point::operator=(const point& other) // copy assignment
{
    if (this != &other) { // self-assignment check expected
        x = other.x;
        y = other.y;
    }
    return *this;
}

point& point::operator+=(const velocity& rhs) 
{       
    x += rhs.x;
    y += rhs.y;
    return *this; 
}

bool point::operator==(const point& rhs) const {
    return (x == rhs.x && y == rhs.y);
}

bool point::operator!=(const point& rhs) const {
    return !(x == rhs.x && y == rhs.y);
}

bool point::isNull() const {
    return (x == 0 && y == 0);
}

void point::clear() {
    x = 0; y = 0;
}

bool point::near(const point& position) const {
    int x1 = position.x - x;
    int y1 = position.y - y;
    return (abs(x1) < 3) && (abs(y1) < 3);
}