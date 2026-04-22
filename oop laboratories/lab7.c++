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
//байгуулагч функц. :Shape(n) гэдэг нь эх классын Shape(n) байгуулагч функцийг эхлээд дуудаж ажиллуулна гэж зааж байна.
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




// 4-р класс: Square / Квадрат (Shape2D-аас удамшина)
class Square : public Shape2D {
private:
    double side;  // Талын урт
    // Дөрвөн оройн координат
    double x1, y1;  // Зүүн дээд
    double x2, y2;  // Баруун дээд
    double x3, y3;  // Баруун доод
    double x4, y4;  // Зүүн доод
public:
    // Байгуулагч: зүүн дээд оройн координат, талын урт, нэр
    Square(double topX, double topY, double s, string n) : Shape2D(n, topX, topY) {
        side = s;
        // Зүүн дээд оройноос бусад оройг тооцно
        x1 = topX;        y1 = topY;         // Зүүн дээд
        x2 = topX + side; y2 = topY;         // Баруун дээд
        x3 = topX + side; y3 = topY - side;  // Баруун доод
        x4 = topX;        y4 = topY - side;  // Зүүн доод
    }
    // Талбай = side * side
    double talbaiFlaah() {
        return side * side;
    }
    // Периметр = 4 * side
    double perimetrFlaah() {
        return 4 * side;
    }
    void haruulah() {
        cout << "------------------------------" << endl;
        cout << "durs       : " << name        << endl;
        cout << "taliin urt   : " << side         << endl;
        cout << "zuun deed   : (" << x1 << ", " << y1 << ")" << endl;
        cout << "baruun deed : (" << x2 << ", " << y2 << ")" << endl;
        cout << "baruun dood : (" << x3 << ", " << y3 << ")" << endl;
        cout << "zuun dood   : (" << x4 << ", " << y4 << ")" << endl;
        cout << "talbai      : " << talbaiFlaah()   << endl;
        cout << "perimetr    : " << perimetrFlaah() << endl;
        cout << "-------------------------------" << endl;
    }
};
// 5-р класс: Triangle / Зөв гурвалжин (Shape2D-аас удамшина)
class Triangle : public Shape2D {
private:
    double side;  // Талын урт (зөв гурвалжин = бүх тал тэнцүү)
    // Гурван оройн координат
    double x1, y1;  // Дээд орой
    double x2, y2;  // Зүүн доод орой
    double x3, y3;  // Баруун доод орой
public:
    // Байгуулагч: дээд оройн координат, талын урт, нэр
    Triangle(double topX, double topY, double s, string n) : Shape2D(n, topX, topY) {
        side = s;
        // Зөв гурвалжингийн өндөр = (√3 / 2) * side
        double ondor = (sqrt(3.0) / 2.0) * side;
        x1 = topX;             y1 = topY;          // Дээд орой
        x2 = topX - side / 2;  y2 = topY - ondor;  // Зүүн доод
        x3 = topX + side / 2;  y3 = topY - ondor;  // Баруун доод
    }
    // Талбай = (√3 / 4) * side * side
    double talbaiFlaah() {
        return (sqrt(3.0) / 4.0) * side * side;
    }
    // Периметр = 3 * side
    double perimetrFlaah() {
        return 3 * side;
    }
    void haruulah() {
        cout << "------------------------------" << endl;
        cout << "durs        : " << name         << endl;
        cout << "taliin urt   : " << side          << endl;
        cout << "deed oroi   : (" << x1 << ", " << y1 << ")" << endl;
        cout << "zuun dood   : (" << x2 << ", " << y2 << ")" << endl;
        cout << "baruun dood : (" << x3 << ", " << y3 << ")" << endl;
        cout << "talbai      : " << talbaiFlaah()   << endl;
        cout << "perimetr    : " << perimetrFlaah() << endl;
        cout << "------------------------------" << endl;
    }
};
// main функц - объект үүсгэж туршина
int main() {
    // --- Тойрог үүсгэх ---
    // Төв цэг (0, 0), радиус 5
    Circle myCircle(0, 0, 5, "toirog");
    myCircle.haruulah();
    // --- Квадрат үүсгэх ---
    // Зүүн дээд орой (1, 4), тал 3
    Square mySquare(1, 4, 3, "kvadrat");
    mySquare.haruulah();
    // --- Зөв гурвалжин үүсгэх ---
    // Дээд орой (0, 6), тал 4
    Triangle myTriangle(0, 6, 4, "zov gurvaljin");
    myTriangle.haruulah();
    return 0;
}
