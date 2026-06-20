// ============================================================
// UNIT 1 - TOPICS 3,4,5: MEMBER FUNCTIONS + NESTING + ARRAYS
// ============================================================
// Member functions: defined inside OR outside class using ::
// Nesting: calling one member function from another
// Arrays in class: array declared as data member
// ============================================================

#include<iostream>
using namespace std;

// ============================================================
// PART A: MEMBER FUNCTIONS (Inside + Outside definition)
// ============================================================
class Rectangle {
    private:
        float length, width;

    public:
        void setData(float l, float w) {  // Defined INSIDE class
            length = l;
            width  = w;
        }
        float area();        // Only DECLARED inside
        float perimeter();   // Only DECLARED inside
        void  display();
};

// Defined OUTSIDE using Scope Resolution Operator ::
float Rectangle::area() {
    return length * width;
}

float Rectangle::perimeter() {
    return 2 * (length + width);
}

void Rectangle::display() {
    cout << "Length    : " << length     << endl;
    cout << "Width     : " << width      << endl;
    cout << "Area      : " << area()     << endl;  // Nesting!
    cout << "Perimeter : " << perimeter()<< endl;  // Nesting!
}

// ============================================================
// PART B: NESTING OF MEMBER FUNCTIONS
// ============================================================
class Calculator {
    private:
        int a, b;

        // Private member functions — can't call from outside
        int add()      { return a + b; }
        int subtract() { return a - b; }
        int multiply() { return a * b; }

    public:
        void setValues(int x, int y) { a = x; b = y; }

        // showAll() NESTS private functions — calls them internally
        void showAll() {
            cout << a << " + " << b << " = " << add()      << endl;
            cout << a << " - " << b << " = " << subtract() << endl;
            cout << a << " * " << b << " = " << multiply() << endl;
        }
};

// ============================================================
// PART C: ARRAYS WITHIN A CLASS
// ============================================================
class Student {
    private:
        string name;
        int    roll;
        float  marks[5];    // Array as data member

    public:
        void getData() {
            cout << "Enter name : "; cin >> name;
            cout << "Enter roll : "; cin >> roll;
            cout << "Enter 5 marks: ";
            for(int i = 0; i < 5; i++)
                cin >> marks[i];
        }

        void display() {
            float total = 0;
            cout << "\n--- Student Report ---" << endl;
            cout << "Name : " << name << endl;
            cout << "Roll : " << roll << endl;
            for(int i = 0; i < 5; i++) {
                cout << "Subject " << (i+1) << ": " << marks[i] << endl;
                total += marks[i];
            }
            cout << "Total   : " << total       << endl;
            cout << "Average : " << total / 5.0 << endl;
            cout << "Result  : " << (total/5.0 >= 40 ? "PASS" : "FAIL") << endl;
        }
};

int main() {
    cout << "===== MEMBER FUNCTIONS =====" << endl;
    Rectangle r;
    r.setData(8.0, 5.0);
    r.display();

    cout << "\n===== NESTING OF FUNCTIONS =====" << endl;
    Calculator c;
    c.setValues(15, 4);
    c.showAll();
    // c.add();  // ERROR — add() is private

    cout << "\n===== ARRAYS IN CLASS =====" << endl;
    Student s;
    s.getData();
    s.display();

    return 0;
}

// ============================================================
// SAMPLE OUTPUT:
// ===== MEMBER FUNCTIONS =====
// Length    : 8
// Width     : 5
// Area      : 40
// Perimeter : 26
//
// ===== NESTING OF FUNCTIONS =====
// 15 + 4 = 19
// 15 - 4 = 11
// 15 * 4 = 60
//
// ===== ARRAYS IN CLASS =====
// Enter name : Rahul
// Enter roll : 101
// Enter 5 marks: 80 75 90 85 70
// --- Student Report ---
// Name : Rahul
// Roll : 101
// Subject 1: 80
// Subject 2: 75
// Subject 3: 90
// Subject 4: 85
// Subject 5: 70
// Total   : 400
// Average : 80
// Result  : PASS
// ============================================================

// ============================================================
// VIVA POINTS:
// Q: What is :: operator?
// A: Scope Resolution Operator — tells compiler which class
//    the function belongs to when defined outside
//
// Q: What is nesting of member functions?
// A: Calling one member function from within another member
//    function of the SAME class
//
// Q: Can private member functions be called from main()?
// A: NO — only other member functions of the same class can call them
// ============================================================
