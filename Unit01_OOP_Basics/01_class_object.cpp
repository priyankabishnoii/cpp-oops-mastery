// ============================================================
// UNIT 1 - TOPIC 1: CLASS AND OBJECT
// ============================================================
// Definition: A class is a user-defined blueprint that bundles
// data members and member functions. An object is a real
// instance of that class occupying memory.
//
// Real-life Analogy: Car (class) vs My Red Honda (object)
// ============================================================

#include<iostream>
using namespace std;

// ---- Defining a Class ----
class Student {
    // Data Members
    public:
        string name;
        int    roll;
        float  marks;

    // Member Functions
    void display() {
        cout << "Name  : " << name  << endl;
        cout << "Roll  : " << roll  << endl;
        cout << "Marks : " << marks << endl;
    }
};

// ---- Another Class Example ----
class Car {
    public:
        string brand;
        string color;
        int    speed;

        void showDetails() {
            cout << "\n--- Car Details ---"   << endl;
            cout << "Brand : " << brand << endl;
            cout << "Color : " << color << endl;
            cout << "Speed : " << speed << " km/h" << endl;
        }

        void accelerate(int inc) {
            speed += inc;
            cout << brand << " accelerated! New speed: "
                 << speed << " km/h" << endl;
        }
};

int main() {
    // ---- Creating Objects ----
    Student s1;          // Object 1
    Student s2;          // Object 2

    // Assigning values to Object 1
    s1.name  = "Rahul";
    s1.roll  = 101;
    s1.marks = 89.5;

    // Assigning values to Object 2
    s2.name  = "Priya";
    s2.roll  = 102;
    s2.marks = 95.0;

    cout << "======= STUDENT 1 =======" << endl;
    s1.display();

    cout << "\n======= STUDENT 2 =======" << endl;
    s2.display();

    // ---- Car Object ----
    Car myCar;
    myCar.brand = "Honda";
    myCar.color = "Red";
    myCar.speed = 0;

    myCar.showDetails();
    myCar.accelerate(60);
    myCar.accelerate(40);

    return 0;
}

// ============================================================
// OUTPUT:
// ======= STUDENT 1 =======
// Name  : Rahul
// Roll  : 101
// Marks : 89.5
//
// ======= STUDENT 2 =======
// Name  : Priya
// Roll  : 102
// Marks : 95
//
// --- Car Details ---
// Brand : Honda
// Color : Red
// Speed : 0 km/h
// Honda accelerated! New speed: 60 km/h
// Honda accelerated! New speed: 100 km/h
// ============================================================

// ============================================================
// VIVA POINTS:
// Q: What is the difference between class and object?
// A: Class = Blueprint (no memory), Object = Instance (has memory)
//
// Q: Where is memory allocated — class or object?
// A: Memory is allocated when OBJECT is created, not at class definition
//
// Q: Can we create multiple objects of the same class?
// A: YES — each object has its own copy of data members
// ============================================================
