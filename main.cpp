#include <string>
#include <iostream>
#include <cairommconfig.h>
#include <cairomm/context.h>
#include <cairomm/surface.h>

#include "math.h"
#include "turtle.h"

double colored_area; // Supported by turtle.cpp

struct Color {
    double r, g, b;
    Color(double r, double g, double b) {
        this->r = r;
        this->g = g;
        this->b = b;
    }
};

int main() {
    colored_area = 0;
//    Color* colors[3] = {new Color(1, 0, 0), new Color(0, 1, 0), new Color(0, 0, 1)};
    Color* colors[3] = {new Color(1, 0.45, 0), new Color(1, 0.59, 0.25), new Color(1, 0.7, 0.45)};
    Cairo::RefPtr<Cairo::ImageSurface> surface =
        Cairo::ImageSurface::create(Cairo::FORMAT_ARGB32, 800, 800);

    Cairo::RefPtr<Cairo::Context> cr = Cairo::Context::create(surface);

    // White background
    cr->save(); // save the state of the context
    cr->set_source_rgb(1, 1, 1);
    cr->paint(); // fill image with the color
    cr->restore(); // color is back to black now
    
    // Middle star
    double size = 150;
    double x = 400, y = 400;
    double a = 30;
    Turtle turtle0(cr, x, y, size, a);
    Color* color = new Color(0.65, 0.29, 0);
    cr->set_source_rgb(color->r, color->g, color->b);
    turtle0.print();
    
    // Next
    size /= sqrt(3);
    a += 30;
    x += size * cosd(a) * 2;
    y += size * sind(a) * 2;
    a += 60;
    Turtle turtle1(cr, x, y, size, a);
    color = colors[1];
    cr->set_source_rgb(color->r, color->g, color->b);
    for (int i = 0; i < 6; i++) turtle1.walk(1);
    
    // Rest
    for (int j = 2; j < 10; j++) {
        size /= sqrt(3);
        a += -90;
        x += size * cosd(a) * 2;
        y += size * sind(a) * 2;
        a += 60;
        Turtle turtle(cr, x, y, size, a);
        color = colors[j % (sizeof(colors) / sizeof(Color*))];
        cr->set_source_rgb(color->r, color->g, color->b);
        for (int i = 0; i < 6; i++) turtle.walk(j);
    }
    
    
    /*
    size /= sqrt(3);
    for (int i = 0; i < 360; i += 60)
        star(cr, x + size * 2 * cosd(a + i + 30), y + size * 2 * sind(a + i + 30), size, a + 30);
    */
    
    
    
    surface->write_to_png("result.png");
    
    std::cout << "colored area: " << colored_area << std::endl;
    std::cout << "expected: " << (double(150) / 3) * (double(150) / 3)
                                 * 30 * sqrt(3) << std::endl; // 150 is init size
}







