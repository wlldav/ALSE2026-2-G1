#ifndef SPHERE_H
#define SPHERE_H

class Sphere {
private:
    double radius_;

public:
    Sphere();
    explicit Sphere(double radius);

    double get_radius() const;
    void set_radius(double radius);

    double volume() const;
    double surface_area() const;
};

#endif
