// ============================================================
// UNIT 2: CONSTRUCTORS & DESTRUCTORS — ALL TYPES
// ============================================================
// 1. Default Constructor
// 2. Parameterized Constructor
// 3. Copy Constructor (Shallow vs Deep)
// 4. Dynamic Constructor
// 5. Multiple Constructors (Overloading)
// 6. Default Arguments Constructor
// 7. Dynamic Initialization
// 8. Destructor
// ============================================================

#include<iostream>
#include<cstring>
using namespace std;

// ============================================================
// 1. DEFAULT CONSTRUCTOR
// ============================================================
class Account {
    string owner;
    double balance;
public:
    Account() {                   // Default Constructor
        owner   = "Unknown";
        balance = 0.0;
        cout << "[Default Constructor] Account created for: "
             << owner << endl;
    }
    void display() {
        cout << "Owner: " << owner << " | Balance: " << balance << endl;
    }
};

// ============================================================
// 2. PARAMETERIZED CONSTRUCTOR
// ============================================================
class Student {
    string name;
    int    roll;
    float  marks;
public:
    Student(string n, int r, float m) {  // Parameterized
        name  = n;
        roll  = r;
        marks = m;
        cout << "[Param Constructor] Student: " << name << " created" << endl;
    }
    void display() {
        cout << "Name: " << name << " Roll: " << roll
             << " Marks: " << marks << endl;
    }
};

// ============================================================
// 3. COPY CONSTRUCTOR — Shallow vs Deep Copy
// ============================================================
class ShallowDemo {
public:
    int *data;
    ShallowDemo(int val) {
        data  = new int(val);
        cout << "[Shallow] Created, data=" << *data << endl;
    }
    // Default copy = Shallow (compiler generated)
    ~ShallowDemo() { delete data; }
};

class DeepDemo {
public:
    int *data;
    DeepDemo(int val) {
        data = new int(val);
        cout << "[Deep] Created, data=" << *data << endl;
    }
    // Custom Copy Constructor = Deep Copy
    DeepDemo(DeepDemo &obj) {
        data  = new int(*obj.data);   // New memory!
        cout << "[Deep] Copied, data=" << *data
             << " (different address)" << endl;
    }
    ~DeepDemo() { delete data; }
};

// ============================================================
// 4. MULTIPLE CONSTRUCTORS (Overloaded)
// ============================================================
class Complex {
    float real, imag;
public:
    Complex() {                     // Constructor 1
        real = 0; imag = 0;
        cout << "[Complex] Default: 0+0i" << endl;
    }
    Complex(float r) {              // Constructor 2
        real = r; imag = 0;
        cout << "[Complex] One-arg: " << r << "+0i" << endl;
    }
    Complex(float r, float i) {     // Constructor 3
        real = r; imag = i;
        cout << "[Complex] Two-arg: " << r << "+" << i << "i" << endl;
    }
    // Copy Constructor
    Complex(Complex &c) {           // Constructor 4
        real = c.real; imag = c.imag;
        cout << "[Complex] Copied: " << real << "+" << imag << "i" << endl;
    }
    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

// ============================================================
// 5. CONSTRUCTOR WITH DEFAULT ARGUMENTS
// ============================================================
class Box {
    float l, w, h;
public:
    Box(float length=1.0, float width=1.0, float height=1.0) {
        l = length; w = width; h = height;
    }
    void display() {
        cout << "Box(" << l << "x" << w << "x" << h
             << ") Volume=" << l*w*h << endl;
    }
};

// ============================================================
// 6. DYNAMIC CONSTRUCTOR
// ============================================================
class DynamicArray {
    int *arr;
    int  size;
public:
    DynamicArray(int s) {
        size = s;
        arr  = new int[size];       // Dynamic allocation in constructor
        cout << "[Dynamic] Allocated " << size << " integers" << endl;
        for(int i = 0; i < size; i++) arr[i] = (i+1) * 10;
    }
    void display() {
        cout << "Array: ";
        for(int i = 0; i < size; i++) cout << arr[i] << " ";
        cout << endl;
    }
    ~DynamicArray() {
        delete[] arr;
        cout << "[Destructor] Memory freed for array of size "
             << size << endl;
    }
};

// ============================================================
// 7. DESTRUCTOR ORDER DEMO
// ============================================================
class Room {
    string guest;
public:
    Room(string g) {
        guest = g;
        cout << "[CONSTRUCTOR] " << guest << " checked IN"  << endl;
    }
    ~Room() {
        cout << "[DESTRUCTOR]  " << guest << " checked OUT" << endl;
    }
};

// ============================================================
// MAIN
// ============================================================
int main() {
    cout << "\n========== 1. DEFAULT CONSTRUCTOR ==========" << endl;
    Account a1;
    a1.display();

    cout << "\n========== 2. PARAMETERIZED CONSTRUCTOR ==========" << endl;
    Student s1("Rahul", 101, 89.5);
    Student s2 = Student("Priya", 102, 95.0);  // Explicit call
    s1.display();
    s2.display();

    cout << "\n========== 3. COPY CONSTRUCTOR (DEEP) ==========" << endl;
    DeepDemo d1(100);
    DeepDemo d2(d1);           // Copy constructor called
    *d1.data = 999;            // Change d1 — d2 should NOT change
    cout << "d1.data = " << *d1.data << endl;
    cout << "d2.data = " << *d2.data << " (independent copy)" << endl;

    cout << "\n========== 4. MULTIPLE CONSTRUCTORS ==========" << endl;
    Complex c1;                // Default
    Complex c2(3.5);           // One arg
    Complex c3(2.0, 4.0);      // Two args
    Complex c4(c3);            // Copy

    cout << "\n========== 5. DEFAULT ARGUMENTS ==========" << endl;
    Box b1;                    // All defaults: 1x1x1
    Box b2(4.0);               // l=4, w=1, h=1
    Box b3(3.0, 2.0, 5.0);     // All specified
    b1.display();
    b2.display();
    b3.display();

    cout << "\n========== 6. DYNAMIC CONSTRUCTOR ==========" << endl;
    int n = 5;
    DynamicArray da(n);
    da.display();

    cout << "\n========== 7. DESTRUCTOR ORDER (LIFO) ==========" << endl;
    {
        Room r1("Alice");
        Room r2("Bob");
        Room r3("Charlie");
        cout << "--- Scope ends here ---" << endl;
    }   // Destructor order: Charlie → Bob → Alice (LIFO)

    cout << "\nProgram ending..." << endl;
    return 0;
}

// ============================================================
// OUTPUT:
// ========== 1. DEFAULT CONSTRUCTOR ==========
// [Default Constructor] Account created for: Unknown
// Owner: Unknown | Balance: 0
//
// ========== 2. PARAMETERIZED CONSTRUCTOR ==========
// [Param Constructor] Student: Rahul created
// [Param Constructor] Student: Priya created
// Name: Rahul Roll: 101 Marks: 89.5
// Name: Priya Roll: 102 Marks: 95
//
// ========== 3. COPY CONSTRUCTOR (DEEP) ==========
// [Deep] Created, data=100
// [Deep] Copied, data=100 (different address)
// d1.data = 999
// d2.data = 100 (independent copy)
//
// ========== 7. DESTRUCTOR ORDER (LIFO) ==========
// [CONSTRUCTOR] Alice checked IN
// [CONSTRUCTOR] Bob checked IN
// [CONSTRUCTOR] Charlie checked IN
// --- Scope ends here ---
// [DESTRUCTOR]  Charlie checked OUT
// [DESTRUCTOR]  Bob     checked OUT
// [DESTRUCTOR]  Alice   checked OUT
// ============================================================

// ============================================================
// VIVA POINTS:
// Q: Can constructor have return type?           A: NO
// Q: Why copy constructor takes reference?
//    A: Avoid infinite recursion — value copy would call itself
// Q: Shallow vs Deep copy?
//    A: Shallow = same address, Deep = new memory same value
// Q: Destructor order?                          A: LIFO
// Q: Can we have multiple destructors?          A: NO — only one
// Q: Can constructor be private?
//    A: YES — used in Singleton design pattern
// ============================================================
