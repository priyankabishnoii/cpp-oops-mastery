# ⚡ 30 MOST IMPORTANT VIVA QUESTIONS & ANSWERS
## C++ Object-Oriented Programming — Complete Syllabus
### Verbal Answers with Examples | Ready for University Viva

---

## Q1. What is a Class and Object? Give a real-life example.

**Answer:**

A **class** is a blueprint or template that defines what
data and functions an object will have — but it doesn't occupy
memory by itself.

An **object** is a real instance of that class. It occupies
actual memory at runtime.

For example — **"Car"** is a class. It defines color, speed,
engine. But **"My Red Honda"** is the actual object.

```cpp
class Car {           // Blueprint — no memory yet
public:
    string color;
    void drive() { cout << "Driving"; }
};
Car myCar;            // Object — memory allocated NOW
myCar.color = "Red";
```

---

## Q2. What are Access Specifiers? What is the default in class vs struct?

**Answer:**

Access specifiers control **who can access** the members
of a class. There are three:

- **private**   → only inside the same class
- **protected** → class + derived classes
- **public**    → accessible from anywhere

Default in **class = private**.
Default in **struct = public**.

```cpp
class A  { int x;  };  // x is private by default
struct B { int x;  };  // x is public by default
```

---

## Q3. What is a Constructor? Can it have a return type?

**Answer:**

A constructor is a **special member function** with the
**same name as the class**, **no return type**, and is
**automatically called** when an object is created.

**No  it cannot have a return type, not even void.**

```cpp
class Student {
public:
    Student() {          // No return type — CORRECT
        cout << "Object created!";
    }
};
Student s;   // Constructor called automatically
```

Key properties:
- Same name as class
- No return type
- Auto-called on object creation
- Can be overloaded

---

## Q4. What is the difference between Copy Constructor and Assignment Operator?

**Answer:**

Both copy data — but differ in **when** they're used.

**Copy Constructor** → called when a **new object** is being
created from an existing one.

**Assignment Operator** → called when an **already existing**
object is assigned a value.

```cpp
Student s1("Rahul");
Student s2 = s1;    // Copy Constructor  (s2 is NEW)
Student s3;
s3 = s1;            // Assignment Operator (s3 already exists)
```

Copy constructor takes **reference** `(Student &s)` to avoid
infinite recursion.

---

## Q5. What is Shallow Copy vs Deep Copy?

**Answer:**

This is very important.

**Shallow copy** copies values as-is. If there's a pointer,
it copies the **address** — both objects point to the
**same memory**. Dangerous — if one deletes it, the other
has a dangling pointer.

**Deep copy** creates **new memory** and copies the actual
data — objects are completely independent.

```cpp
// Deep Copy Constructor:
MyClass(MyClass &obj) {
    ptr = new int(*obj.ptr);  // New memory, same value ✓
}
```

**Rule:** Always write your own copy constructor when your
class has **pointer members**.

---

## Q6. What is a Destructor? What is the order of destructor calls?

**Answer:**

A destructor has **tilde (~) before class name**, called
**automatically when object goes out of scope** or is deleted.
Used to release resources — especially dynamic memory.

```cpp
class Room {
public:
    Room()  { cout << "Checked IN";  }
    ~Room() { cout << "Checked OUT"; }
};
```

Order of destruction → **LIFO (Last In, First Out)**.
Last object created is the **first one destroyed**.

```
Created: A → B → C
Destroyed: C → B → A   (like a stack)
```

Also: only **ONE destructor** allowed — cannot be overloaded,
takes no parameters.

---

## Q7. What is Inline Function? Is it guaranteed?

**Answer:**

An inline function requests the compiler to **replace the
function call with the actual body** at compile time —
eliminating function call overhead.

```cpp
inline int square(int x) { return x * x; }
// Compiler pastes x*x directly at call site
```

**No it is NOT guaranteed.** The `inline` keyword is
only a **hint/request**. Compiler may ignore it for large
functions, recursive functions, or functions with loops.

Functions defined **inside a class are automatically inline**.

---

## Q8. What is a Friend Function? Is friendship inherited?

**Answer:**

A friend function is a **non-member function** granted
access to **private and protected members** of a class using
the `friend` keyword.

```cpp
class Box {
    private: float length;
    public:
        friend float getLength(Box b);  // Declaration
};
float getLength(Box b) {
    return b.length;   // Accesses private member ✓
}
```

Important sir:
- Friend is **NOT a member** — no `::`, not called with object
- **NOT mutual** — A friend of B ≠ B friend of A
- **NOT inherited** — Friend of base ≠ Friend of derived

---

## Q9. What is Static Data Member and Static Function?

**Answer:**

A static data member is shared by **ALL objects** —
only **ONE copy** exists in memory regardless of object count.

```cpp
class Student {
public:
    static int count;       // ONE copy shared by ALL objects
    Student() { count++; }
};
int Student::count = 0;    // Must define OUTSIDE class
```

Static function can **only access static members** and has
**no `this` pointer**. Called without object:

```cpp
Student::showCount();    // No object needed!
```

Think of static as the **class's own data** — not any
particular object's.

---

## Q10. What is Function Overloading? Can we overload by return type only?

**Answer:**

Function overloading = **multiple functions with the same
name but different parameter lists** (number/type/order).
It is **compile-time polymorphism**.

```cpp
int    add(int a, int b)        { return a+b; }
float  add(float a, float b)    { return a+b; }
int    add(int a, int b, int c) { return a+b+c; }
```

**No cannot overload by return type alone.** Compiler
uses **function signature (name + parameter types)** to
resolve calls. Return type is NOT part of the signature.

```cpp
int   getValue() { return 1;   }
float getValue() { return 1.0; }  // ❌ COMPILE ERROR!
```

---

## Q11. What are the types of Inheritance? What is the Diamond Problem?

**Answer:**

The five types of inheritance in C++ are:

| Type | Description |
|---|---|
| Single | One base, one derived (A→B) |
| Multilevel | Chain (A→B→C) |
| Hierarchical | One base, many derived |
| Multiple | Many bases, one derived |
| Hybrid | Combination of above |

**Diamond problem** — in hybrid inheritance, a class inherits
from two classes that both inherit from same base. The derived
class gets **two copies of base** → ambiguity.

```
    Base
   /    \
 Mid1   Mid2
   \    /
   Child ← two copies of Base!
```

Solution → **virtual base class**:
```cpp
class Mid1 : virtual public Base { };
class Mid2 : virtual public Base { };
// Now Child gets only ONE shared copy of Base
```

---

## Q12. Are Constructors Inherited? What is the order of constructor calls?

**Answer:**

 **constructors are NOT inherited**. Each class must
define its own.

However, when a derived class object is created, the
**base class constructor is called FIRST**, then the derived.

```cpp
class A { public: A() { cout << "A Constructor"; } };
class B : public A { public: B() { cout << "B Constructor"; } };

B obj;
// Output: A Constructor → B Constructor
```

Destructors in **reverse order** — B first, then A.

Like building a house — lay foundation (base) first, then
walls (derived). Demolish walls first, then foundation.

---

## Q13. What is Operator Overloading? Which operators CANNOT be overloaded?

**Answer:**

Sir, operator overloading means giving **new meanings to
existing operators** for user-defined types while keeping
original meaning for built-in types. It is **compile-time
polymorphism**.

```cpp
Complex c3 = c1 + c2;   // + overloaded for Complex
```

Operators that **CANNOT be overloaded** — I remember them as:
- `::`  — Scope resolution
- `.`   — Member access
- `.*`  — Member pointer
- `?:`  — Ternary
- `sizeof`

Also: cannot create **new operators**, cannot change
**precedence/associativity**, at least one operand must be
**user-defined type**.

---

## Q14. What is the difference between Member Function and Friend Function for Operator Overloading?

**Answer:**

Sir, the key difference is in **how operands are passed**.

**Member function** — left operand is implicit (`this`),
so only **one parameter** needed for binary:
```cpp
Complex operator+(Complex c) {    // this + c
    return Complex(real+c.real, imag+c.imag);
}
```

**Friend function** — both operands explicit,
so **two parameters** needed:
```cpp
friend Complex operator+(Complex c1, Complex c2) {
    return Complex(c1.real+c2.real, c1.imag+c2.imag);
}
```

Friend is needed when **left operand is NOT the class object**
(e.g., `3 + Complex`) — member function can't handle that.

---

## Q15. What is Type Conversion in C++? Explain all three types.

**Answer:**

Sir, three types of type conversion in C++ OOP:

**1. Basic → Class** (Converting Constructor — single arg):
```cpp
class Meter {
    float val;
public:
    Meter(float v) { val = v; }  // Converts float → Meter
};
Meter m = 5.5;   // float auto-converted to Meter
```

**2. Class → Basic** (Conversion Function):
```cpp
operator float() { return val; }  // No return type, no params!
float f = m;    // Meter auto-converted to float
```

**3. Class → Class** (Converting constructor in destination
or conversion function in source class).

Key rule for conversion function — **no return type written,
no parameters, must be member function**.

---

## Q16. What is the `this` Pointer? Where is it NOT available?

**Answer:**

Sir, `this` is an **implicit pointer** available in every
**non-static member function**, pointing to the **object
that called the function**.

Main uses:

**1. Resolve name conflicts:**
```cpp
Student(string name) {
    this->name = name;  // this->name = data member
}
```

**2. Return current object (method chaining):**
```cpp
Student& setName(string n) {
    name = n;
    return *this;    // Current object returned
}
// Usage: s.setName("Rahul").setMarks(90);
```

`this` is **NOT available in static functions** — static
functions don't belong to any particular object.

---

## Q17. What is the difference between Virtual Function and Pure Virtual Function?

**Answer:**

Sir, both use `virtual` keyword, but:

**Virtual function** — has a body in base class, optional
to override:
```cpp
virtual void show() { cout << "Base show"; }
```

**Pure virtual function** — has `= 0`, no body, derived
class **MUST** override it:
```cpp
virtual void show() = 0;    // Pure virtual
```

A class with even **one pure virtual function** becomes an
**abstract class** — you **cannot create objects** of it.

Abstract class = contract — "any derived class MUST
implement these functions."

---

## Q18. What is Early Binding vs Late Binding?

**Answer:**

Sir, binding = connecting a function call to its definition.

**Early binding (compile-time)** — connection made at
compile time. Used for normal functions and overloading.
Faster but less flexible.

**Late binding (runtime)** — connection made at runtime
using virtual functions. Correct function decided based on
**actual object type**, not pointer type.

```cpp
Animal *ptr;
ptr = &dog;  ptr->sound();   // Late: calls Dog::sound
ptr = &cat;  ptr->sound();   // Late: calls Cat::sound
```

Late binding works through **VTable** — a compiler-generated
table of function pointers. Each object has a hidden
**vptr** pointing to its class's VTable.

---

## Q19. Can a Constructor be Virtual? Can Destructor be Virtual?

**Answer:**

Sir, **constructor CANNOT be virtual** — when constructor
runs, the object doesn't fully exist yet, so the **VTable
is not set up**. Virtual mechanism needs VTable to work.

**Destructor CAN and SHOULD be virtual** in base classes:

```cpp
class Base {
public:
    virtual ~Base() { cout << "Base destructor"; }
};
class Derived : public Base {
public:
    ~Derived() { cout << "Derived destructor"; }
};

Base *ptr = new Derived();
delete ptr;
// Without virtual: ONLY Base destructor → MEMORY LEAK
// With virtual: Derived destructor first, then Base → SAFE ✓
```

---

## Q20. What is a VTable and VPtr?

**Answer:**

Sir, VTable (Virtual Table) is a **compiler-generated table**
storing **pointers to virtual functions** of a class. Every
class with virtual functions gets its own VTable.

VPtr (Virtual Pointer) is a **hidden pointer** added by
compiler to **every object** of a class with virtual functions.
Points to that class's VTable.

```
Dog object in memory:
┌─────────────────┐
│  vptr ──────────┼──► Dog's VTable
│  name = "Tommy" │    ┌─────────────────────┐
│  age  = 3       │    │ sound → Dog::sound() │
└─────────────────┘    │ eat   → Dog::eat()   │
                       └─────────────────────┘
```

`ptr->sound()` → follows vptr → looks up VTable → calls
right function at RUNTIME. That's how runtime polymorphism
works internally.

---

## Q21. What are File Modes in C++?

**Answer:**

Sir, file modes specify **how a file is opened**:

| Mode | Meaning |
|---|---|
| `ios::in` | Open for reading |
| `ios::out` | Open for writing (truncates) |
| `ios::app` | Write at END — never truncates |
| `ios::ate` | Open and go to end, can write anywhere |
| `ios::binary` | Binary mode — raw bytes |
| `ios::trunc` | Delete existing content |

```cpp
fstream f("data.dat", ios::in | ios::out | ios::binary);
```

Difference between `app` and `ate` sir — in **app**, every
write ALWAYS goes to end. In **ate**, pointer goes to end
at open but you can move it elsewhere.

---

## Q22. What is seekg and seekp? What is tellg and tellp?

**Answer:**

Sir, these are **file pointer manipulation functions**:

- `seekg` → moves the **GET (read)** pointer
- `seekp` → moves the **PUT (write)** pointer
- `tellg` → returns **current GET** position
- `tellp` → returns **current PUT** position

```cpp
f.seekg(5, ios::beg);    // Move 5 bytes from beginning
f.seekg(-2, ios::end);   // Move 2 bytes before end
f.seekg(3, ios::cur);    // Move 3 bytes from current
cout << f.tellg();       // Print current read position
```

Reference points:
- `ios::beg` — from beginning
- `ios::cur` — from current position
- `ios::end` — from end

---

## Q23. What is a Function Template? How is it different from Macros?

**Answer:**

Sir, a function template is a **generic function** where data
type is a parameter — same function works with any type:

```cpp
template <typename T>
T findMax(T a, T b) {
    return (a > b) ? a : b;
}
// Works for int, float, char, string — anything!
```

**Templates vs Macros:**

Macro problem:
```cpp
#define SQUARE(x)  x*x
SQUARE(2+3)  →  2+3*2+3 = 11  ❌  (expected 25!)
```

Template is correct:
```cpp
square(2+3)  →  square(5)  →  25  ✓
```

Templates have **type checking, scope, recursion support,
debuggability** — macros have none of these. Templates are
always safer and better.

---

## Q24. What is a Class Template? Give an example.

**Answer:**

Sir, a class template is a **blueprint for a class** where
the data type is a parameter — same class logic works for
any data type.

```cpp
template <typename T>
class Stack {
    T arr[100];
    int top;
public:
    Stack() { top = -1; }
    void push(T val) { arr[++top] = val; }
    T pop()          { return arr[top--]; }
};

Stack<int>    intStack;    // Stack of integers
Stack<string> strStack;    // Stack of strings
Stack<float>  floatStack;  // Stack of floats
```

Same Stack class — write code **once**, compiler
**generates specific version** for each type. This is
**generic programming**.

---

## Q25. What is Exception Handling? Explain try, catch, throw.

**Answer:**

Sir, exception handling handles **runtime errors gracefully**
— preventing program crash. Uses three keywords:

- **try**   — block of code that might throw
- **throw** — signals an error condition
- **catch** — catches and handles the error

```cpp
float divide(float a, float b) {
    if(b == 0)
        throw "Division by zero!";   // Throw
    return a / b;
}

try {
    float r = divide(10, 0);    // Try
}
catch(const char* msg) {        // Catch
    cout << "Error: " << msg;
}
cout << "Program continues..."; // Runs normally after catch ✓
```

Key point — after catch executes, program **continues
normally** from after the try-catch block.

---

## Q26. What is catch(...) ? What is Multiple Catch?

**Answer:**

Sir, `catch(...)` with three dots catches **any exception
type** — it's a safety net:

```cpp
catch(...) {
    cout << "Some unknown exception!";
}
```

Must always be the **LAST catch block** — checked top to
bottom, first match wins.

**Multiple catch** = several catch blocks for different
exception types:

```cpp
try { /* ... */ }
catch(int e)         { cout << "Int: "    << e; }
catch(double e)      { cout << "Double: " << e; }
catch(const char* e) { cout << "String: " << e; }
catch(...)           { cout << "Unknown"; }   // LAST!
```

---

## Q27. What is Re-throwing an Exception?

**Answer:**

Sir, re-throwing = catch an exception, do partial handling,
then **throw it again** using `throw;` without any argument:

```cpp
void innerFunc() {
    try {
        throw "Critical Error!";
    }
    catch(const char* e) {
        cout << "Inner: Logging error..." << endl;
        throw;      // RE-THROW — same exception!
    }
}

int main() {
    try {
        innerFunc();
    }
    catch(const char* e) {
        cout << "Outer: Final handling: " << e << endl;
    }
}
```

Real-life — junior employee (inner catch) logs complaint
but can't resolve → escalates (re-throws) to manager
(outer catch). Manager does final resolution.

---

## Q28. What happens when an exception is thrown in a Constructor?

**Answer:**

Sir, this is very important and tricky.

If exception thrown **inside constructor**, the object is
considered **not fully created**. Therefore:

- **Destructor is NOT called** for that object
- Memory allocated **before** the throw may **leak**

```cpp
class File {
    int *data;
public:
    File(int size) {
        data = new int[size];     // Memory allocated
        if(size > 1000)
            throw "Too large!";   // Constructor throws!
        // Destructor WON'T be called → data leaks!
    }
    ~File() { delete[] data; }
};
```

Solution → free resources before throwing, or use
**smart pointers** (auto-cleanup on exception).

---

## Q29. What is set_terminate? What happens with an uncaught exception?

**Answer:**

Sir, if exception is thrown and **no catch block matches**
anywhere in the call stack, C++ calls `std::terminate()`
which by default calls `std::abort()` — program **crashes**.

We can customize this using `set_terminate()`:

```cpp
void myHandler() {
    cout << "Custom cleanup before crash!" << endl;
    exit(1);   // Must exit — NEVER return!
}

set_terminate(myHandler);   // Register custom handler
```

Key points sir:
- Custom handler must **NOT return** — must exit or abort
- Useful for **logging errors** before crash
- Also called when **destructor throws** during stack unwinding

---

## Q30. What is Polymorphism? What are its types? Give example of each.

**Answer:**

Sir, polymorphism means **one name, many forms** — same
function or operator behaves differently based on context.
One of the four pillars of OOP.

**Two types:**

**1. Compile-time (Early Binding)** — decided at compile time:
- **Function overloading** — same name, different params
- **Operator overloading** — same operator, new meaning

```cpp
int   area(int s)   { return s*s;      }   // Square
float area(float r) { return 3.14*r*r; }   // Circle
```

**2. Runtime (Late Binding)** — decided at runtime:
- **Virtual functions** — base pointer calls correct
  derived function at runtime

```cpp
Animal *ptr;
ptr = &dog;  ptr->sound();  // "Woof" — decided at runtime
ptr = &cat;  ptr->sound();  // "Meow" — decided at runtime
```

Sir, compile-time is **faster** but less flexible. Runtime
is slightly **slower** (VTable lookup) but very **flexible**
— add new derived classes without changing existing code.
That's the **Open-Closed Principle**.

---

## 📊 QUICK REVISION TABLE

| # | Topic | One-line Key Answer |
|---|---|---|
| 1 | Class vs Object | Blueprint vs Instance |
| 2 | Access Specifiers | class=private, struct=public default |
| 3 | Constructor | Same name, no return type, auto-called |
| 4 | Copy vs Assignment | New object vs existing object |
| 5 | Shallow vs Deep | Same address vs new memory |
| 6 | Destructor | ~, LIFO, only one allowed |
| 7 | Inline | Hint to compiler, not guaranteed |
| 8 | Friend | Non-member, not mutual, not inherited |
| 9 | Static | One copy, class-level, no this |
| 10 | Function Overloading | Diff params — NOT return type |
| 11 | Inheritance Types | 5 types, virtual = diamond solution |
| 12 | Constructor inherited? | NO — base called first though |
| 13 | Operator Overloading | Cannot overload :: . .* ?: sizeof |
| 14 | Member vs Friend | 1 param vs 2 params for binary op |
| 15 | Type Conversion | Converting ctor / conversion function |
| 16 | this pointer | Current object, NOT in static |
| 17 | Virtual vs Pure Virtual | Has body vs =0, abstract class |
| 18 | Early vs Late Binding | Compile time vs Runtime/VTable |
| 19 | Virtual Ctor/Dtor | Ctor NO, Dtor YES (prevent leak) |
| 20 | VTable/VPtr | Function ptr table / hidden obj ptr |
| 21 | File Modes | in/out/app/ate/binary/trunc |
| 22 | seekg/seekp | Move GET/PUT file pointer |
| 23 | Template vs Macro | Type-safe, scoped, no substitution bug |
| 24 | Class Template | Generic class — one code all types |
| 25 | try-catch-throw | Error handling, program continues |
| 26 | catch(...) | Catch-all, must be LAST |
| 27 | Re-throwing | throw; — partial handle, escalate |
| 28 | Exception in ctor | Destructor NOT called, memory leak risk |
| 29 | set_terminate | Custom crash handler, must not return |
| 30 | Polymorphism | Compile-time (overload) + Runtime (virtual) |

---

## 🎯 LAST MINUTE TIPS

```
✓ Always say "Sir" — shows respect
✓ Give real-life analogy with every answer
✓ Write a small code snippet if asked
✓ If you don't know — say "I'm not sure sir,
  but I know that..." and say what you DO know
✓ Speak clearly and confidently
✓ Don't rush — think for 2 seconds before answering
```

---

**All the best for your interview! You've got this! 💪🎓**
