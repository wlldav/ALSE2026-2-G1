#include "sphere.h"
#include <cmath>
#include <stdexcept>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

Sphere::Sphere() : radius_{1.0} {}

Sphere::Sphere(double radius) {
    set_radius(radius);
}

double Sphere::get_radius() const {
    return radius_;
}

void Sphere::set_radius(double radius) {
    if (radius < 0) {
        throw std::invalid_argument("El radio no puede ser negativo.");
    }
    radius_ = radius;
}

double Sphere::volume() const {
    return (4.0 / 3.0) * M_PI * std::pow(radius_, 3);
}

double Sphere::surface_area() const {
    return 4.0 * M_PI * std::pow(radius_, 2);
}
