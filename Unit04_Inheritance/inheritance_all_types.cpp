// ============================================================
// UNIT 4: INHERITANCE — ALL TYPES
// ============================================================
// 1. Single Inheritance
// 2. Making Private Member Inheritable (protected)
// 3. Multilevel Inheritance
// 4. Hierarchical Inheritance
// 5. Multiple Inheritance + Ambiguity
// 6. Hybrid Inheritance + Diamond Problem
// ============================================================

#include<iostream>
using namespace std;

// ============================================================
// 1. SINGLE INHERITANCE
// Diagram: Animal → Dog
// ============================================================
class Animal {
public:
    string name;
    void eat()   { cout << name << " eats food."  << endl; }
    void sleep() { cout << name << " is sleeping." << endl; }
};

class Dog : public Animal {    // Single Inheritance
public:
    string breed;
    void bark() { cout << name << " says: Woof! Woof!" << endl; }
    void fetch(){ cout << name << " fetches the ball!"  << endl; }
};

// ============================================================
// 2. MAKING PRIVATE MEMBER INHERITABLE — protected
// ============================================================
class Person {
protected:              // accessible in derived class
    string name;
    int    age;
private:
    string password;    // NOT accessible in derived class
public:
    void setData(string n, int a) { name = n; age = a; }
};

class Employee : public Person {
    double salary;
public:
    void setSalary(double s) { salary = s; }
    void display() {
        cout << "Name  : " << name   << endl;  // OK — protected
        cout << "Age   : " << age    << endl;  // OK — protected
        cout << "Salary: " << salary << endl;
        // cout << password; // ERROR — private not accessible
    }
};

// ============================================================
// 3. MULTILEVEL INHERITANCE
// Diagram: Vehicle → Car → ElectricCar
// ============================================================
class Vehicle {
public:
    string brand;
    void start() { cout << brand << " vehicle started."      << endl; }
    void stop()  { cout << brand << " vehicle stopped."      << endl; }
};

class Car : public Vehicle {
public:
    int doors;
    void drive() { cout << brand << " car is driving."        << endl; }
    void honk()  { cout << brand << " car honks: Beep Beep!" << endl; }
};

class ElectricCar : public Car {       // Level 3
public:
    int batteryPercent;
    void charge() {
        cout << brand << " electric car charging. Battery: "
             << batteryPercent << "%" << endl;
    }
    void showRange() {
        cout << "Estimated range: " << batteryPercent * 4
             << " km" << endl;
    }
};

// ============================================================
// 4. HIERARCHICAL INHERITANCE
// Diagram: Shape → Circle, Rectangle, Triangle
// ============================================================
class Shape {
protected:
    float area;
public:
    virtual void calcArea() = 0;
    void display() {
        cout << "Area = " << area << endl;
    }
};

class CircleShape : public Shape {
    float radius;
public:
    CircleShape(float r) { radius = r; }
    void calcArea() { area = 3.14159 * radius * radius; }
    void info() { cout << "Circle (r=" << radius << "): "; }
};

class RectShape : public Shape {
    float l, w;
public:
    RectShape(float a, float b) { l=a; w=b; }
    void calcArea() { area = l * w; }
    void info() { cout << "Rectangle (" << l << "x" << w << "): "; }
};

class TriShape : public Shape {
    float base, height;
public:
    TriShape(float b, float h) { base=b; height=h; }
    void calcArea() { area = 0.5 * base * height; }
    void info() { cout << "Triangle (b=" << base << ",h=" << height << "): "; }
};

// ============================================================
// 5. MULTIPLE INHERITANCE
// Diagram: Father + Mother → Child
// ============================================================
class Father {
public:
    void businessSkill() { cout << "Business skills from Father." << endl; }
    void tall()          { cout << "Height inherited from Father." << endl; }
};

class Mother {
public:
    void cookingSkill()  { cout << "Cooking skills from Mother."  << endl; }
    void intelligence()  { cout << "Intelligence from Mother."    << endl; }
};

class Child : public Father, public Mother {   // Multiple Inheritance
public:
    void ownTalent()     { cout << "Child's own: Painting skill." << endl; }
};

// Ambiguity in Multiple Inheritance
class ClassA { public: void show() { cout << "ClassA::show()" << endl; } };
class ClassB { public: void show() { cout << "ClassB::show()" << endl; } };
class ClassC : public ClassA, public ClassB {
public:
    void display() {
        ClassA::show();   // Resolved with scope resolution
        ClassB::show();
        // show();        // AMBIGUOUS — compile error
    }
};

// ============================================================
// 6. HYBRID INHERITANCE — Diamond Problem + Virtual Base Class
// Diagram:
//         Base
//        /    \
//      Mid1   Mid2
//        \    /
//         Child
// ============================================================
class Base {
public:
    int data;
    Base() { data = 100; }
    void showBase() { cout << "Base data = " << data << endl; }
};

class Mid1 : virtual public Base {    // virtual — only ONE Base copy
public:
    void showMid1() { cout << "Mid1: data = " << data << endl; }
};

class Mid2 : virtual public Base {    // virtual — only ONE Base copy
public:
    void showMid2() { cout << "Mid2: data = " << data << endl; }
};

class HybridChild : public Mid1, public Mid2 {
public:
    void showAll() {
        cout << "Child: data = " << data << endl;  // No ambiguity!
        showBase();   // Only ONE copy of Base
        showMid1();
        showMid2();
    }
};

// ============================================================
// CONSTRUCTOR ORDER DEMO
// ============================================================
class BaseOrder {
public:
    BaseOrder()  { cout << "  → Base Constructor"    << endl; }
    ~BaseOrder() { cout << "  → Base Destructor"     << endl; }
};

class DerivedOrder : public BaseOrder {
public:
    DerivedOrder()  { cout << "  → Derived Constructor" << endl; }
    ~DerivedOrder() { cout << "  → Derived Destructor"  << endl; }
};

// ============================================================
// MAIN
// ============================================================
int main() {
    cout << "===== 1. SINGLE INHERITANCE =====" << endl;
    Dog d;
    d.name  = "Tommy";
    d.breed = "Labrador";
    d.eat();
    d.sleep();
    d.bark();
    d.fetch();

    cout << "\n===== 2. PROTECTED — PRIVATE INHERITABLE =====" << endl;
    Employee e;
    e.setData("Priya", 28);
    e.setSalary(75000);
    e.display();

    cout << "\n===== 3. MULTILEVEL INHERITANCE =====" << endl;
    ElectricCar tesla;
    tesla.brand          = "Tesla";
    tesla.doors          = 4;
    tesla.batteryPercent = 80;
    tesla.start();
    tesla.drive();
    tesla.charge();
    tesla.showRange();
    tesla.stop();

    cout << "\n===== 4. HIERARCHICAL INHERITANCE =====" << endl;
    CircleShape cs(7);    cs.calcArea(); cs.info(); cs.display();
    RectShape   rs(5,4);  rs.calcArea(); rs.info(); rs.display();
    TriShape    ts(6,8);  ts.calcArea(); ts.info(); ts.display();

    cout << "\n===== 5. MULTIPLE INHERITANCE =====" << endl;
    Child child;
    child.businessSkill();
    child.cookingSkill();
    child.tall();
    child.intelligence();
    child.ownTalent();

    cout << "\n--- Ambiguity Resolution ---" << endl;
    ClassC obj;
    obj.display();

    cout << "\n===== 6. HYBRID (DIAMOND PROBLEM) =====" << endl;
    HybridChild hc;
    hc.showAll();

    cout << "\n===== CONSTRUCTOR/DESTRUCTOR ORDER =====" << endl;
    cout << "Creating DerivedOrder object:" << endl;
    {
        DerivedOrder dobj;
        cout << "Object in use..." << endl;
    }
    cout << "(Object destroyed)" << endl;

    return 0;
}

// ============================================================
// VIVA POINTS:
// Q: Access of protected member?
//    A: Same class + derived class. NOT from main/outside
//
// Q: Are constructors inherited?
//    A: NO. Base constructor called automatically first though.
//
// Q: Constructor/Destructor order?
//    A: Base constructor FIRST, Derived constructor SECOND
//       Derived destructor FIRST, Base destructor SECOND
//
// Q: What is diamond problem?
//    A: Two copies of base class in derived → ambiguity
//
// Q: How to solve diamond problem?
//    A: virtual keyword in intermediate inheritance
//
// Q: What is IS-A relationship?
//    A: Dog IS-A Animal. Inheritance represents IS-A.
// ============================================================
