// ============================================================
// UNIT 3: FUNCTIONS & COMPILE-TIME POLYMORPHISM
// ============================================================
// 1. Call by Value & Call by Reference
// 2. Objects as Function Arguments
// 3. Inline Functions
// 4. Making Outside Function Inline
// 5. Friend Functions
// 6. Static Data Members & Functions
// 7. Function Overloading
// ============================================================

#include<iostream>
using namespace std;

// ============================================================
// 1. CALL BY VALUE vs CALL BY REFERENCE
// ============================================================
void swapByValue(int a, int b) {    // Copy — original unchanged
    int temp = a; a = b; b = temp;
    cout << "[ByValue]  Inside: a=" << a << " b=" << b << endl;
}

void swapByRef(int &a, int &b) {    // Alias — original changes
    int temp = a; a = b; b = temp;
    cout << "[ByRef]    Inside: a=" << a << " b=" << b << endl;
}

// ============================================================
// 2. OBJECTS AS FUNCTION ARGUMENTS
// ============================================================
class Distance {
public:
    float meters;
    Distance(float m = 0) { meters = m; }

    Distance add(Distance d) {       // Object as argument
        return Distance(meters + d.meters);
    }
    void display() {
        cout << "Distance: " << meters << " meters" << endl;
    }
};

// ============================================================
// 3. INLINE FUNCTIONS
// ============================================================
inline int    square(int x)    { return x * x;             }
inline float  cube(float x)    { return x * x * x;         }
inline bool   isEven(int x)    { return x % 2 == 0;        }
inline float  celToFahr(float c){ return (c * 9.0/5.0)+32; }

// ============================================================
// 4. MAKING OUTSIDE FUNCTION INLINE
// ============================================================
class Circle {
    float radius;
public:
    Circle(float r) { radius = r; }
    float area();
    float perimeter();
};

inline float Circle::area()      { return 3.14159 * radius * radius; }
inline float Circle::perimeter() { return 2 * 3.14159 * radius;      }

// ============================================================
// 5. FRIEND FUNCTIONS
// ============================================================
class Box {
    float length, width, height;
public:
    Box(float l, float w, float h): length(l), width(w), height(h) {}
    friend float volume(Box b);           // Friend declaration
    friend void  compareBoxes(Box, Box);  // Friend with two objects
};

float volume(Box b) {
    return b.length * b.width * b.height; // Access private members
}

void compareBoxes(Box b1, Box b2) {
    float v1 = b1.length * b1.width * b1.height;
    float v2 = b2.length * b2.width * b2.height;
    if(v1 > v2)      cout << "Box 1 is larger"  << endl;
    else if(v2 > v1) cout << "Box 2 is larger"  << endl;
    else             cout << "Both boxes equal"  << endl;
}

// ============================================================
// 6. STATIC DATA MEMBERS & FUNCTIONS
// ============================================================
class Counter {
    string name;
public:
    static int count;      // Shared by ALL objects

    Counter(string n) {
        name = n;
        count++;
        cout << "[Counter] " << name
             << " created. Total: " << count << endl;
    }

    static void showCount() {          // Static function
        cout << "Active counters: " << count << endl;
        // cout << name; // ERROR — static can't access non-static
    }

    ~Counter() {
        count--;
        cout << "[Counter] " << name
             << " destroyed. Remaining: " << count << endl;
    }
};
int Counter::count = 0;   // Static member definition outside

// ============================================================
// 7. FUNCTION OVERLOADING (Compile-time Polymorphism)
// ============================================================
class Calculator {
public:
    // Same name "calculate" — different params
    int    calculate(int a, int b)            { return a + b;           }
    float  calculate(float a, float b)        { return a + b;           }
    int    calculate(int a, int b, int c)     { return a + b + c;       }
    double calculate(double a, double b)      { return a * b;           } // multiply for double
    string calculate(string a, string b)      { return a + " " + b;    } // concat for string
};

// ============================================================
// MAIN
// ============================================================
int main() {

    // ----- 1. Call by Value vs Reference -----
    cout << "===== CALL BY VALUE vs REFERENCE =====" << endl;
    int x = 10, y = 20;
    cout << "Before swapByValue: x=" << x << " y=" << y << endl;
    swapByValue(x, y);
    cout << "After  swapByValue: x=" << x << " y=" << y << " (UNCHANGED)" << endl;

    cout << "\nBefore swapByRef: x=" << x << " y=" << y << endl;
    swapByRef(x, y);
    cout << "After  swapByRef: x=" << x << " y=" << y << " (CHANGED)" << endl;

    // ----- 2. Object as Argument -----
    cout << "\n===== OBJECTS AS ARGUMENTS =====" << endl;
    Distance d1(150), d2(250);
    Distance d3 = d1.add(d2);
    d1.display();
    d2.display();
    d3.display();

    // ----- 3. Inline Functions -----
    cout << "\n===== INLINE FUNCTIONS =====" << endl;
    cout << "square(7)      = " << square(7)        << endl;
    cout << "cube(3.0)      = " << cube(3.0)        << endl;
    cout << "isEven(8)      = " << isEven(8)        << endl;
    cout << "celToFahr(100) = " << celToFahr(100)   << endl;

    // ----- 4. Outside Inline -----
    cout << "\n===== OUTSIDE INLINE FUNCTION =====" << endl;
    Circle c(7.0);
    cout << "Circle Area      = " << c.area()      << endl;
    cout << "Circle Perimeter = " << c.perimeter() << endl;

    // ----- 5. Friend Function -----
    cout << "\n===== FRIEND FUNCTION =====" << endl;
    Box b1(3,4,5), b2(2,6,4);
    cout << "Volume of Box1 = " << volume(b1) << endl;
    cout << "Volume of Box2 = " << volume(b2) << endl;
    compareBoxes(b1, b2);

    // ----- 6. Static Members -----
    cout << "\n===== STATIC MEMBERS =====" << endl;
    Counter::showCount();         // Before any object
    {
        Counter c1("Alpha");
        Counter c2("Beta");
        Counter c3("Gamma");
        Counter::showCount();
    }  // c1,c2,c3 destroyed here
    Counter::showCount();

    // ----- 7. Function Overloading -----
    cout << "\n===== FUNCTION OVERLOADING =====" << endl;
    Calculator calc;
    cout << "int+int         = " << calc.calculate(3, 4)           << endl;
    cout << "float+float     = " << calc.calculate(3.5f, 2.5f)     << endl;
    cout << "int+int+int     = " << calc.calculate(1, 2, 3)        << endl;
    cout << "double*double   = " << calc.calculate(2.5, 4.0)       << endl;
    cout << "string+string   = " << calc.calculate("Hello","World") << endl;

    return 0;
}

// ============================================================
// VIVA POINTS:
// Q: Can overloading be done by return type alone?
//    A: NO — return type not part of function signature
//
// Q: Is inline guaranteed?
//    A: NO — only a hint/request to compiler
//
// Q: Is friendship mutual or inherited?
//    A: NO to both — not mutual, not inherited
//
// Q: Can static function access non-static member?
//    A: NO — static has no 'this' pointer
//
// Q: What is name mangling?
//    A: Compiler internally renames overloaded functions based
//       on parameter types to distinguish them
// ============================================================
