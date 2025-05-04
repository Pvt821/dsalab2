#include <iostream>
using namespace std;
class Shape {
public:
    double length;
public:
    Shape(double l) {
        if (l <= 0) {
            cout << "Invalid value! Length must be positive." << endl;
            length = 1;
        } else {
            length = l;
        }
    }
};
class Square : public Shape {
public:
    Square(double l) : Shape(l) {}
    double calculateArea() {
        return length * length;
    }
};
class Rectangle {
private:
    double length, width;
public:
    Rectangle(double l, double w) {
        if (l <= 0 || w <= 0) {
            cout << "Invalid values! Dimensions must be positive." << endl;
            length = width = 1;
        } else {
            length = l;
            width = w;
        }
    }
    double calculateArea() {
        return length * width;
    }
};
class Cuboid : public Shape {
private:
    double width, height;
public:
    Cuboid(double l, double w, double h) : Shape(l) {
        if (w <= 0 || h <= 0) {
            cout << "Invalid values! Dimensions must be positive. Setting default to 1." << endl;
            width = height = 1;
        } else {
            width = w;
            height = h;
        }
    }
    double calculateSurfaceArea() {
        return 2 * (length * width + width * height + height * length);
    }
};
int main() {
    int choice;
    do {
        cout << "\nMenu:"
             << "\n1. Calculate Area of Square"
             << "\n2. Calculate Area of Rectangle"
             << "\n3. Calculate Surface Area of Cuboid"
             << "\n4. Exit"
             << "\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                double side;
                cout << "Enter side length of the square: ";
                cin >> side;
                Square sq(side);
                cout << "Area of Square: " << sq.calculateArea() << endl;
                break;
            }
            case 2: {
                double length, width;
                cout << "Enter length and width of the rectangle: ";
                cin >> length >> width;
                Rectangle rect(length, width);
                cout << "Area of Rectangle: " << rect.calculateArea() << endl;
                break;
            }
            case 3: {
                double length, width, height;
                cout << "Enter length, width, and height of the cuboid: ";
                cin >> length >> width >> height;
                Cuboid cuboid(length, width, height);
                cout << "Surface Area of Cuboid: " << cuboid.calculateSurfaceArea() << endl;
                break;
            }
            case 4:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Please enter a valid option." << endl;
        }
    } while (choice != 4);
    return 0;
}