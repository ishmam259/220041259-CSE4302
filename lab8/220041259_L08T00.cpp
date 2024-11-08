#include<iostream>
#include<cmath>
#include<string>

using namespace std;

class Shape {
public:
    virtual string whoAmI() const = 0;   
};

class TwoDimensionalShape : public Shape {
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
};

class ThreeDimensionalShape : public Shape {
public:
    virtual double surfaceArea() const = 0;
    virtual double volume() const = 0;
};

class Square : public TwoDimensionalShape {
    double side_length;

public:
    Square(double side_length) : side_length(side_length) {}

    double area() const override {
        return side_length * side_length;
    }

    double perimeter() const override {
        return 4 * side_length;
    }

    string whoAmI() const override {
        return "I am a Square. I am a two-dimensional shape.";
    }
};


class Circle : public TwoDimensionalShape {
    double radius;

public:
    Circle(double radius) : radius(radius) {}

    double area() const override {
        return 3.14 * radius * radius;
    }

    double perimeter() const override {
        return 2 * 3.14 * radius;
    }

    string whoAmI() const override {
        return "I am a Circle. I am a two-dimensional shape.";
    }
};



class Cube : public ThreeDimensionalShape {
    double side_length;

public:
    Cube(double side_length) : side_length(side_length) {}

    double surfaceArea() const override {
        return 6 * (side_length * side_length);
    }

    double volume() const override {
        return side_length * side_length * side_length;
    }

    string whoAmI() const override {
        return "I am a Cube. I am a three-dimensional shape.";
    }
};


class Sphere : public ThreeDimensionalShape {
    double radius;

public:
    Sphere(double radius) : radius(radius) {}

    double surfaceArea() const override {
        return 4 * 3.14 * radius * radius;
    }

    double volume() const override {
        return (4.0 / 3) * 3.14 * radius * radius * radius;
    }

    string whoAmI() const override {
        return "I am a Sphere. I am a three-dimensional shape.";
    }
};

int main() {
    Square square(4);
    Circle circle(3);
    

    TwoDimensionalShape* shapes2D[] = { &square, &circle};
    for (const auto& shape : shapes2D) {
        cout << shape->whoAmI() << endl;
        cout << "Area: " << shape->area() << endl;
        cout << "Perimeter: " << shape->perimeter() << "\n" << endl;
    }

    Cube cube(3);
    Sphere sphere(4);

    ThreeDimensionalShape* shapes3D[] = { &cube, &sphere};
    for (const auto& shape : shapes3D) {
        cout << shape->whoAmI() << endl;
        cout << "Surface Area: " << shape->surfaceArea() << endl;
        cout << "Volume: " << shape->volume() << "\n" << endl;
    }

    return 0;
}
