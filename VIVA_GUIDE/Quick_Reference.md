# ⚡ C++ OOP QUICK REFERENCE CHEAT SHEET
## All 14 Units | One-Page Summary

---

## 🔑 UNIT 1 — OOP BASICS

```cpp
class MyClass {           // Class definition
private:
    int secret;           // private — only inside class
protected:
    int shared;           // protected — class + derived
public:
    int open;             // public — everywhere
    void show();          // Member function declaration
};
void MyClass::show() { }  // :: = Scope Resolution Operator
```

| Concept | Key Point |
|---|---|
| Class default access | **private** |
| Struct default access | **public** |
| `::` operator | Scope Resolution — used to define outside |
| Nesting | Calling member function from another member function |

---

## 🔑 UNIT 2 — CONSTRUCTORS & DESTRUCTORS

```cpp
class Demo {
public:
    Demo()              { }   // Default constructor
    Demo(int x)         { }   // Parameterized constructor
    Demo(Demo &d)       { }   // Copy constructor (MUST be reference!)
    Demo(int x = 0)     { }   // Default argument constructor
    ~Demo()             { }   // Destructor (only ONE, no params)
};
```

| Rule | Detail |
|---|---|
| Constructor return type | **NONE** |
| Destructor symbol | **~** |
| Destructor count | **Only ONE** |
| Destruction order | **LIFO** |
| Copy constructor param | **Reference** (avoid infinite recursion) |
| Shallow copy | Same pointer address (DANGEROUS) |
| Deep copy | New memory, same value (SAFE) |

---

## 🔑 UNIT 3 — FUNCTIONS & COMPILE-TIME POLYMORPHISM

```cpp
inline int sq(int x)  { return x*x; }  // Inline (hint only!)

class A {
    friend void f(A a); // Friend — non-member, accesses private
    static int count;   // Static — ONE copy for ALL objects
    static void show(); // Static function — no 'this' pointer
};
int A::count = 0;       // Static member MUST be defined outside
```

| Concept | Key Point |
|---|---|
| Call by Value | Copy passed — original UNCHANGED |
| Call by Reference | Alias (`&`) — original CHANGED |
| Inline | Hint to compiler — NOT guaranteed |
| Friend | Not member, not mutual, not inherited |
| Static function | No `this`, call as `Class::func()` |
| Function overloading | Diff params — NOT by return type alone |

---

## 🔑 UNIT 4 — INHERITANCE

```cpp
class Derived : public Base { };          // Single
class C : public A, public B { };         // Multiple
class Mid : virtual public Base { };      // Virtual base (diamond fix)
```

| Type | Diagram |
|---|---|
| Single | A → B |
| Multilevel | A → B → C |
| Hierarchical | A → B, A → C, A → D |
| Multiple | A + B → C |
| Hybrid | Diamond shape |

| Rule | Detail |
|---|---|
| Constructor order | Base FIRST, Derived SECOND |
| Destructor order | Derived FIRST, Base SECOND |
| Constructors inherited? | **NO** |
| Diamond problem solution | `virtual` base class |
| private in base | NOT accessible in derived |
| protected in base | Accessible in derived |

---

## 🔑 UNIT 5 — OPERATOR OVERLOADING

```cpp
// Member function (unary)
Vector operator-()          { return Vector(-x,-y); }

// Member function (binary — left operand = this)
Complex operator+(Complex c){ return Complex(r+c.r, i+c.i); }

// Friend function (binary — both operands explicit)
friend Complex operator+(Complex c1, Complex c2);
```

| CANNOT Overload | Reason |
|---|---|
| `::` | Scope resolution |
| `.` | Member access |
| `.*` | Member pointer |
| `?:` | Ternary |
| `sizeof` | Built-in |

---

## 🔑 UNIT 6 — TYPE CONVERSION

```cpp
// Basic → Class (converting constructor)
Class(float f) { val = f; }        // float auto-converts to Class

// Class → Basic (conversion function)
operator float() { return val; }   // No return type! No params!

// Class → Class
DestClass(SrcClass s) { /* convert */ }
```

---

## 🔑 UNIT 7 — RUNTIME POLYMORPHISM

```cpp
// this pointer
MyClass(int x) { this->x = x; }     // Resolve name conflict
MyClass& set() { /* ... */ return *this; } // Method chaining

// Base pointer → Derived object
Base *ptr = &derivedObj;            // Valid!
ptr->virtualFunc();                 // Calls DERIVED version ✓
ptr->normalFunc();                  // Calls BASE version ✗
```

---

## 🔑 UNIT 8 — VIRTUAL FUNCTIONS

```cpp
class Base {
public:
    virtual  void show() { }   // Virtual — can be overridden
    virtual  void draw() = 0;  // Pure virtual — MUST override
    virtual ~Base()      { }   // Virtual destructor — ALWAYS!
};
// Class with pure virtual = ABSTRACT CLASS (cannot instantiate)
```

| Concept | Detail |
|---|---|
| Virtual constructor | ❌ NOT possible |
| Virtual destructor | ✅ MUST in base class |
| Abstract class | Has at least one `= 0` function |
| VTable | Compiler table of virtual function pointers |
| VPtr | Hidden pointer in object → points to VTable |
| Early binding | Compile time (normal functions) |
| Late binding | Runtime (virtual functions via VTable) |

---

## 🔑 UNIT 9 & 10 — FILE HANDLING

```cpp
ofstream fout("file.txt");            // Write
ifstream fin("file.txt");             // Read
fstream  frw("file.txt", ios::in | ios::out | ios::binary);

// File Pointer
f.seekg(5, ios::beg);   // Move GET pointer 5 from start
f.seekp(-2, ios::end);  // Move PUT pointer 2 before end
f.tellg();              // Current GET position
f.tellp();              // Current PUT position

// Binary read/write
f.write((char*)&obj, sizeof(obj));
f.read ((char*)&obj, sizeof(obj));
```

| Mode | Meaning |
|---|---|
| `ios::in` | Read |
| `ios::out` | Write (truncate) |
| `ios::app` | Append (write at end ALWAYS) |
| `ios::ate` | Go to end on open |
| `ios::binary` | Binary mode |
| `ios::trunc` | Truncate existing |

---

## 🔑 UNIT 11 & 12 — TEMPLATES

```cpp
// Function Template
template <typename T>
T findMax(T a, T b) { return (a>b)?a:b; }

// Class Template
template <typename T>
class Stack {
    T arr[100]; int top;
public:
    void push(T v) { arr[++top]=v; }
    T    pop()     { return arr[top--]; }
};
Stack<int> si;     Stack<string> ss;  // Instantiation
```

| Template vs Macro | |
|---|---|
| Type safety | Template ✓, Macro ✗ |
| Scope | Template ✓, Macro ✗ |
| Recursion | Template ✓, Macro ✗ |
| Substitution bugs | Template safe ✓, Macro dangerous ✗ |

---

## 🔑 UNIT 13 & 14 — EXCEPTION HANDLING

```cpp
try {
    if(b==0) throw "Div by zero!";   // throw any type
    return a/b;
}
catch(const char* msg) { /* handle string */ }
catch(int e)           { /* handle int    */ }
catch(...)             { /* catch ALL — must be LAST */ }

// Re-throw
catch(exception& e) {
    log(e);
    throw;     // Re-throw same exception (no argument!)
}
```

| Rule | Detail |
|---|---|
| `catch(...)` position | Always LAST |
| Exception in constructor | Destructor NOT called |
| Throw from destructor | NEVER — causes terminate() |
| Re-throw syntax | `throw;` (no argument) |
| Uncaught exception | Calls `terminate()` → `abort()` |
| Custom terminate | `set_terminate(myFunc)` |
| Stack unwinding | All local objects destroyed LIFO on exception |

---

## 🎯 TOP 10 MOST TRICKY VIVA ANSWERS

| Q | A |
|---|---|
| Is C++ pure OOP? | NO — multi-paradigm |
| Can constructor be virtual? | NO — VTable not ready yet |
| Can destructor be virtual? | YES — MUST for base classes |
| Can constructor be private? | YES — Singleton pattern |
| Is inline guaranteed? | NO — only a hint |
| Can we overload by return type? | NO |
| Is friendship mutual? | NO |
| Is friendship inherited? | NO |
| What is default class access? | private |
| Destructor order? | LIFO — last in, first out |

---

**🏆 Remember: Confidence + Real-life Analogy + Code = Perfect Viva!**
