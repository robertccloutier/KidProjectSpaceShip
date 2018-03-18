
#ifndef point_h
#define point_h

#include <Arduino.h>

class velocity;

class point
{
    public:
        int x, y;
        
    public:
        point() : x(0), y(0) {}

        point(int x1, int y1) : x(x1), y(y1) {}
    
        point(const point &p2) : x(p2.x), y(p2.y) {}

        point& operator=(const point& other);

        point& operator+=(const velocity& rhs);
        bool operator==(const point& rhs) const;
        bool operator!=(const point& rhs) const;

        bool isNull() const;
        void clear();
        bool near(const point& position) const;
};

#endif