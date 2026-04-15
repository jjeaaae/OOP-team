#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Shape {
protected:
    string name;
public:
    Shape(string n) {
        name = n;
    }

    string getName() {
        return name;
    }

    virtual double talbaiFlaah() = 0;
    virtual double perimetrFlaah() = 0;
};

class Shape2D : public Shape {
protected:
    double x, y;
public:
    Shape2D(string n, double x, double y) : Shape(n) {
        this->x = x;
        this->y = y;
    }
};

class Circle : public Shape2D {
private:
    double radius;
public:
    Circle(double cx, double cy, double r, string n)
        : Shape2D(n, cx, cy) {
        radius = r;
    }

    double talbaiFlaah() {
        return 3.14159 * radius * radius;
    }

    double perimetrFlaah() {
        return 2 * 3.14159 * radius;
    }
};
class Square : public Shape2D {
private:
    double side;
public:
    Square(double x, double y, double s, string n)
        : Shape2D(n, x, y) {
        side = s;
    }

    double talbaiFlaah() {
        return side * side;
    }

    double perimetrFlaah() {
        return 4 * side;
    }
};
class Triangle : public Shape2D {
private:
    double side;
public:
    Triangle(double x, double y, double s, string n)
        : Shape2D(n, x, y) {
        side = s;
    }

    double talbaiFlaah() {
        return (sqrt(3.0) / 4.0) * side * side;
    }

    double perimetrFlaah() {
        return 3 * side;
    }
};

int main() {
    Shape* dursuud[3];

    for(int i = 0; i < 3; i++) {
        cout << "\nDurs songo (1-toirog, 2-kvadrat, 3-triangle): ";
        int songolt;
        cin >> songolt;

        if(songolt == 1) {
            double x, y, r;
            cout << "Tov (x y): ";
            cin >> x >> y;
            cout << "Radius: ";
            cin >> r;

            dursuud[i] = new Circle(x, y, r, "toirog");
        }
        else if(songolt == 2) {
            double x, y, s;
            cout << "Zuun deed (x y): ";
            cin >> x >> y;
            cout << "Taliin urt: ";
            cin >> s;

            dursuud[i] = new Square(x, y, s, "kvadrat");
        }
        else if(songolt == 3) {
            double x, y, s;
            cout << "Deed oroi (x y): ";
            cin >> x >> y;
            cout << "Taliin urt: ";
            cin >> s;

            dursuud[i] = new Triangle(x, y, s, "triangle");
        }
        else {
            cout << "Buruu songolt! дахин оролдоно.\n";
            i--;
        }
    }

    // Bubble sort (talbaigaar erembleh ihees, baga ruu)
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2 - i; j++) {
            if(dursuud[j]->talbaiFlaah() > dursuud[j+1]->talbaiFlaah()) {
                Shape* temp = dursuud[j];
                dursuud[j] = dursuud[j+1];
                dursuud[j+1] = temp;
            }
        }
    }

   // erembe iig hevleh
    cout << "\n--- Talbaigaar eremblev ---\n";

    for(int i = 0; i < 3; i++) {
        cout << dursuud[i]->getName()
             << " | talbai = " << dursuud[i]->talbaiFlaah()
             << " | perimetr = " << dursuud[i]->perimetrFlaah()
             << endl;
    }

    return 0;
}

