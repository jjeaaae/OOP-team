#include <iostream>
#include <cmath>
#include <string>
using namespace std;
// 1-р класс: Shape (эх класс)
class Shape {
protected:
    string name;  // Дүрсийн нэр
public:
    // Байгуулагч - нэр оноох
    Shape(string n) {
        name = n;
    }
    string getName() {
        return name;
    }
   
    virtual double talbaiFlaah() = 0;
    virtual double perimetrFlaah() = 0;
};
// 2-р класс: Shape2D (Shape-аас удамшина)
class Shape2D : public Shape {
protected:
    double x;  // Байрлалын x координат
    double y;  // Байрлалын y координат
public:
    Shape2D(string n, double x, double y) : Shape(n) {
        this->x = x;
        this->y = y;
    }
};
// 3-р класс: Circle / Тойрог (Shape2D-аас удамшина)
class Circle : public Shape2D {
private:
    double radius;  // Радиус
public:
    // Байгуулагч: төвийн координат, радиус, нэр
    Circle(double cx, double cy, double r, string n) : Shape2D(n, cx, cy) {
        radius = r;
    }
    // Талбай = PI * r * r
    double talbaiFlaah() {
        return 3.14159 * radius * radius;
    }
    // Тойргийн урт = 2 * PI * r
    double perimetrFlaah() {
        return 2 * 3.14159 * radius;
    }
    void haruulah() {
        cout << "------------------------------" << endl;
        cout << "durs     : " << name           << endl;
        cout << "tov     : (" << x << ", " << y << ")" << endl;
        cout << "radius   : " << radius          << endl;
        cout << "talbai   : " << talbaiFlaah()   << endl;
        cout << "toirgiin urt: " << perimetrFlaah() << endl;
        cout << "------------------------------" << endl;
    }
};
