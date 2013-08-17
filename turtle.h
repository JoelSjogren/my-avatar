#ifndef TURTLE_H
#define TURTLE_H

#include <cairommconfig.h>
#include <cairomm/context.h>
#include <cairomm/surface.h>

class Turtle {
    Cairo::RefPtr<Cairo::Context> sand;
    double x, y;
    double size;
    double speed, angle;
    void triangle(Cairo::RefPtr<Cairo::Context> cr, double x, double y, double size, double a);  
    void star();
public:
    bool first;
    Turtle(Cairo::RefPtr<Cairo::Context> sand, double x, double y, double size, double angle);
    
    void walk(int depth);
    void timeTravel();
    
    void turn(double a);
    void setAngle(double a);
    
    void print();


};

#endif
