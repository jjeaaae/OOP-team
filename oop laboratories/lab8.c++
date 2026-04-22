#include <iostream>
#include <cmath>
#include <string>
using namespace std;

// ===================== SHAPE =====================
class Shape {
protected:
    string name;

public:
    static int count;

    Shape(string n) {
        this->name = n;
        count++;
    }

    string getName() {
        return this->name;
    }

    static void setCount(int c) {
        count = c;
    }

    static int getCount() {
        return count;
    }

    virtual double talbaiFlaah() = 0;
    virtual double perimetrFlaah() = 0;
};

int Shape::count = 0;


//SHAPE2D (PURE VIRTUAL )
class Shape2D : public Shape {
protected:
    double x, y;

public:
    Shape2D(string n, double x, double y) : Shape(n) {
        this->x = x;
        this->y = y;
    }

    // PURE VIRTUAL FUNCTIONS
    virtual double talbaiFlaah() = 0;
    virtual double perimetrFlaah() = 0;
};


// CIRCLE
class Circle : public Shape2D {
private:
    double radius;

public:
    Circle(double cx, double cy, double r, string n)
        : Shape2D(n, cx, cy) {
        this->radius = r;
    }

    double talbaiFlaah() {
        return 3.14159 * this->radius * this->radius;
    }

    double perimetrFlaah() {
        return 2 * 3.14159 * this->radius;
    }

    void haruulah() {
        cout << "Name: " << this->name << endl;
        cout << "Area: " << this->talbaiFlaah() << endl;
        cout << "Perimeter: " << this->perimetrFlaah() << endl;
        cout << "----------------------" << endl;
    }
};


// SQUARE
class Square : public Shape2D {
private:
    double side;

public:
    Square(double x, double y, double s, string n)
        : Shape2D(n, x, y) {
        this->side = s;
    }

    double talbaiFlaah() {
        return this->side * this->side;
    }

    double perimetrFlaah() {
        return 4 * this->side;
    }

    void haruulah() {
        cout << "Name: " << this->name << endl;
        cout << "Area: " << this->talbaiFlaah() << endl;
        cout << "Perimeter: " << this->perimetrFlaah() << endl;
        cout << "----------------------" << endl;
    }
};


//TRIANGLE 
class Triangle : public Shape2D {
private:
    double side;

public:
    Triangle(double x, double y, double s, string n)
        : Shape2D(n, x, y) {
        this->side = s;
    }

    double talbaiFlaah() {
        return (sqrt(3.0) / 4.0) * this->side * this->side;
    }

    double perimetrFlaah() {
        return 3 * this->side;
    }

    void haruulah() {
        cout << "Name: " << this->name << endl;
        cout << "Area: " << this->talbaiFlaah() << endl;
        cout << "Perimeter: " << this->perimetrFlaah() << endl;
        cout << "----------------------" << endl;
    }
};


// MAIN 
int main() {

    Circle myCircle(0, 0, 5, "toirog");
    Square mySquare(1, 4, 3, "kvadrat");
    Triangle myTriangle(0, 6, 4, "triangle");

    myCircle.haruulah();
    mySquare.haruulah();
    myTriangle.haruulah();

    cout << "Object count: " << Shape::getCount() << endl;

    //SORTING 
    Shape* arr[3];
    arr[0] = &myCircle;
    arr[1] = &mySquare;
    arr[2] = &myTriangle;

    int n = 3;

    // ---- SORT BY AREA ----
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j]->talbaiFlaah() > arr[j + 1]->talbaiFlaah()) {
                Shape* temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "\nSorted by area:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i]->getName()
             << " = " << arr[i]->talbaiFlaah() << endl;
    }

    // ---- SORT BY PERIMETER ----
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j]->perimetrFlaah() > arr[j + 1]->perimetrFlaah()) {
                Shape* temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "\nSorted by perimeter:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i]->getName()
             << " = " << arr[i]->perimetrFlaah() << endl;
    }

    return 0;
}
