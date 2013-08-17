#include "turtle.h"
#include "math.h"

extern double colored_area;

void Turtle::triangle(Cairo::RefPtr<Cairo::Context> cr, double x, double y, double size, double a) {
    cr->save();
//    cr->set_source_rgb(0, 0, 0);
/*    
    if (first) {
        first = false;
        sand->set_source_rgb(0, 0, 1);
    }
*/    
    cr->move_to(x + size * cosd(a), y + size * sind(a));
    cr->line_to(x + size * cosd(a + 120), y + size * sind(a + 120));
    cr->line_to(x + size * cosd(a + 240), y + size * sind(a + 240));
    cr->fill();
    cr->close_path();
    cr->stroke();
    cr->restore();
    
    colored_area += sqrt(3) / 2 * size * size;
}

void Turtle::star() {
    for (int i = 0; i < 360; i += 60)
        triangle(sand, x + size * 2 / 3 * cosd(angle + i), y + size * 2 / 3 * sind(angle + i), size / 3, angle + i);
}

Turtle::Turtle(Cairo::RefPtr<Cairo::Context> sand, double x, double y, double size, double angle) {
    this->sand = sand;
    this->x = x;
    this->y = y;
    this->size = size;
    this->angle = angle;
    
    first = true;
}

void Turtle::walk(int depth) {
    if (depth > 1) {
        walk(depth - 1);
        walk(depth - 1);
        turn(-60);
        timeTravel();
        print();
    } else if (depth == 1) {
        turn(60);
        timeTravel();
        print();
    }
}

void Turtle::timeTravel() {
    x += size * cosd(angle) * 2;
    y += size * sind(angle) * 2;
}

void Turtle::turn(double a) {
    setAngle(angle + a);
}

void Turtle::setAngle(double a) {
    angle = a;
    while (angle < 0)
        angle += 360;
    while (angle >= 360)
        angle -= 360;
}

void Turtle::print() {
    first = true;
    star();
}








