// ============================================================
// UNIT 6: TYPE CONVERSION
// UNIT 7: RUNTIME POLYMORPHISM
// UNIT 8: VIRTUAL FUNCTIONS
// ============================================================

#include<iostream>
using namespace std;

// ============================================================
// UNIT 6: TYPE CONVERSION
// ============================================================

// --- 6.1 Basic to Class Type (Converting Constructor) ---
class Celsius {
    float temp;
public:
    Celsius() { temp = 0; }
    Celsius(float t) {           // Converting constructor
        temp = t;
        cout << "[Basic→Class] " << t << "°C created" << endl;
    }
    float getTemp() { return temp; }
    void display()  { cout << temp << "°C" << endl; }
};

// --- 6.2 Class to Basic Type (Conversion Function) ---
class Kilogram {
    float kg;
public:
    Kilogram(float k = 0) { kg = k; }

    operator float() {           // Conversion function: Kg → float
        return kg;
    }
    operator int() {             // Conversion function: Kg → int
        return (int)kg;
    }
    void display() { cout << kg << " kg" << endl; }
};

// --- 6.3 Class to Class Type ---
class Fahrenheit {
    float temp;
public:
    Fahrenheit(float t = 0) { temp = t; }

    // Converting constructor: Celsius → Fahrenheit
    Fahrenheit(Celsius c) {
        temp = (c.getTemp() * 9.0/5.0) + 32;
        cout << "[Class→Class] Converted to "
             << temp << "°F" << endl;
    }
    void display() { cout << temp << "°F" << endl; }
};

// ============================================================
// UNIT 7: RUNTIME POLYMORPHISM
// ============================================================

// --- 7.1 Pointer to Object & this Pointer ---
class Employee {
    string name;
    int    id;
    double salary;
public:
    Employee(string name, int id, double salary) {
        this->name   = name;      // 'this' resolves name conflict
        this->id     = id;
        this->salary = salary;
    }

    // Method chaining using 'this'
    Employee& setName(string name) {
        this->name = name;
        return *this;             // Return current object
    }
    Employee& raiseSalary(double pct) {
        salary += salary * pct/100;
        return *this;
    }
    void display() {
        cout << "ID:" << id << " Name:" << name
             << " Salary:" << salary << endl;
    }
};

// --- 7.2 Pointer to Derived Class ---
class BaseClass {
public:
    virtual void show() {
        cout << "[Base] show() called"    << endl;
    }
    void info() {
        cout << "[Base] info() — non-virtual" << endl;
    }
};

class DerivedClass : public BaseClass {
public:
    void show() override {
        cout << "[Derived] show() called" << endl;
    }
    void extra() {
        cout << "[Derived] extra() function" << endl;
    }
};

// ============================================================
// UNIT 8: VIRTUAL FUNCTIONS
// ============================================================

// --- 8.1 Virtual Function ---
class Animal {
public:
    string name;
    virtual void sound() {      // VIRTUAL — runtime decision
        cout << name << ": generic animal sound" << endl;
    }
    virtual void move() {
        cout << name << ": moves somehow" << endl;
    }
    void breathe() {            // NON-VIRTUAL — compile time
        cout << name << ": breathes oxygen" << endl;
    }
    virtual ~Animal() {}        // Virtual destructor — IMPORTANT!
};

class DogV : public Animal {
public:
    void sound() override { cout << name << ": Woof! Woof!" << endl; }
    void move()  override { cout << name << ": runs on 4 legs" << endl; }
};

class CatV : public Animal {
public:
    void sound() override { cout << name << ": Meow! Meow!" << endl; }
    void move()  override { cout << name << ": walks silently" << endl; }
};

class BirdV : public Animal {
public:
    void sound() override { cout << name << ": Tweet! Tweet!" << endl; }
    void move()  override { cout << name << ": flies with wings" << endl; }
};

// --- 8.2 Pure Virtual Function & Abstract Class ---
class Shape {                          // Abstract Class
public:
    virtual float area()      = 0;    // Pure virtual
    virtual float perimeter() = 0;    // Pure virtual
    virtual void  describe()  = 0;    // Pure virtual

    void show() {                      // Concrete function — OK
        cout << "I am a shape. ";
        describe();
        cout << "  Area      = " << area()      << endl;
        cout << "  Perimeter = " << perimeter() << endl;
    }
};

class CircleV : public Shape {
    float r;
public:
    CircleV(float radius) : r(radius) {}
    float area()      override { return 3.14159 * r * r;  }
    float perimeter() override { return 2 * 3.14159 * r;  }
    void  describe()  override { cout << "Circle (r=" << r << ")" << endl; }
};

class RectangleV : public Shape {
    float l, w;
public:
    RectangleV(float a, float b) : l(a), w(b) {}
    float area()      override { return l * w;       }
    float perimeter() override { return 2*(l+w);     }
    void  describe()  override {
        cout << "Rectangle (" << l << "x" << w << ")" << endl;
    }
};

class TriangleV : public Shape {
    float a, b, c;
public:
    TriangleV(float x, float y, float z) : a(x), b(y), c(z) {}
    float area()  override {
        float s = (a+b+c)/2;
        return sqrt(s*(s-a)*(s-b)*(s-c));
    }
    float perimeter() override { return a+b+c; }
    void  describe()  override {
        cout << "Triangle (" << a << "," << b << "," << c << ")" << endl;
    }
};

// --- 8.3 Virtual Destructor Demo ---
class BaseVDest {
public:
    BaseVDest()          { cout << "[Base]    Constructor" << endl; }
    virtual ~BaseVDest() { cout << "[Base]    Destructor"  << endl; } // VIRTUAL!
};

class DerivedVDest : public BaseVDest {
    int *data;
public:
    DerivedVDest() {
        data = new int[100];
        cout << "[Derived] Constructor — memory allocated" << endl;
    }
    ~DerivedVDest() {
        delete[] data;
        cout << "[Derived] Destructor  — memory freed"    << endl;
    }
};

// ============================================================
// MAIN
// ============================================================
int main() {
    cout << "===== UNIT 6: TYPE CONVERSION =====" << endl;

    // Basic to Class
    Celsius c1 = 36.6;          // float → Celsius
    Celsius c2 = 100.0;         // float → Celsius
    c1.display();
    c2.display();

    // Class to Basic
    Kilogram k(75.6);
    float  f = k;               // Kilogram → float
    int    i = k;               // Kilogram → int
    cout << "float: " << f << " | int: " << i << endl;

    // Class to Class
    Fahrenheit fahr(c2);        // Celsius → Fahrenheit
    fahr.display();

    cout << "\n===== UNIT 7: this POINTER =====" << endl;
    Employee emp("Alice", 1, 50000);
    emp.display();
    // Method chaining using this:
    emp.setName("Alicia").raiseSalary(20);
    emp.display();

    cout << "\n===== UNIT 7: POINTER TO DERIVED =====" << endl;
    BaseClass    *bptr;
    DerivedClass  dobj;
    bptr = &dobj;

    bptr->show();    // Calls DERIVED show() — virtual!
    bptr->info();    // Calls BASE info() — non-virtual

    DerivedClass *dptr = &dobj;
    dptr->show();
    dptr->extra();   // Only accessible via Derived pointer

    cout << "\n===== UNIT 8: VIRTUAL FUNCTIONS =====" << endl;
    Animal *ptr;
    DogV  dog;  dog.name  = "Tommy";
    CatV  cat;  cat.name  = "Kitty";
    BirdV bird; bird.name = "Tweety";

    Animal* animals[] = { &dog, &cat, &bird };

    for(int idx = 0; idx < 3; idx++) {
        animals[idx]->sound();    // Runtime: calls correct version
        animals[idx]->move();
        animals[idx]->breathe();  // Always Animal's version
        cout << "---" << endl;
    }

    cout << "\n===== UNIT 8: ABSTRACT CLASS =====" << endl;
    // Shape s; // ERROR — cannot instantiate abstract class

    Shape *shapes[] = {
        new CircleV(7),
        new RectangleV(5, 4),
        new TriangleV(3, 4, 5)
    };

    for(int idx = 0; idx < 3; idx++) {
        shapes[idx]->show();
        cout << endl;
    }

    for(int idx = 0; idx < 3; idx++)
        delete shapes[idx];

    cout << "\n===== UNIT 8: VIRTUAL DESTRUCTOR =====" << endl;
    BaseVDest *vptr = new DerivedVDest();
    delete vptr;   // Both destructors called — CORRECT behavior

    return 0;
}

// ============================================================
// VIVA POINTS:
// Q: What is this pointer?
//    A: Implicit pointer to current object in non-static functions
//
// Q: Can constructor be virtual?
//    A: NO — object not fully created, VTable not ready
//
// Q: Should destructor be virtual?
//    A: YES — in base class, to avoid memory leak in polymorphism
//
// Q: What is abstract class?
//    A: Class with at least one pure virtual function (=0)
//       Cannot be instantiated
//
// Q: What is VTable?
//    A: Compiler-generated table of virtual function pointers
//
// Q: Difference between virtual and non-virtual function call?
//    A: Virtual → runtime lookup via VTable
//       Non-virtual → compile-time direct call
// ============================================================
