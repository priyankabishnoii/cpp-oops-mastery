// ============================================================
// UNIT 11 & 12: TEMPLATES — COMPLETE
// ============================================================
// 1. Function Template
// 2. Class Template
// 3. Overloading Function Templates
// 4. Recursive Template Function
// 5. Class Template + Inheritance
// 6. Template vs Macro
// ============================================================

#include<iostream>
#include<string>
#include<cmath>
using namespace std;

// ============================================================
// 1. FUNCTION TEMPLATES
// ============================================================

// Generic swap
template <typename T>
void mySwap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

// Generic findMax with 3 values
template <typename T>
T findMax(T a, T b, T c) {
    return (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
}

// Generic sort (Bubble Sort)
template <typename T>
void bubbleSort(T arr[], int n) {
    for(int i = 0; i < n-1; i++)
        for(int j = 0; j < n-i-1; j++)
            if(arr[j] > arr[j+1]) {
                T temp  = arr[j];
                arr[j]  = arr[j+1];
                arr[j+1]= temp;
            }
}

// Generic print array
template <typename T>
void printArray(T arr[], int n, string label = "") {
    if(!label.empty()) cout << label << ": ";
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

// Generic linear search
template <typename T>
int linearSearch(T arr[], int n, T key) {
    for(int i = 0; i < n; i++)
        if(arr[i] == key) return i;
    return -1;
}

// ============================================================
// 2. CLASS TEMPLATES
// ============================================================

// --- Generic Stack ---
template <typename T>
class Stack {
    T   arr[100];
    int top;
public:
    Stack() : top(-1) {}

    void push(T val) {
        if(top < 99) arr[++top] = val;
        else cout << "Stack Overflow!" << endl;
    }
    T pop() {
        if(top >= 0) return arr[top--];
        cout << "Stack Underflow!" << endl;
        return T();
    }
    T peek()    { return arr[top]; }
    bool empty(){ return top == -1; }
    int  size() { return top + 1;  }

    void display() {
        cout << "Stack [top→]: ";
        for(int i = top; i >= 0; i--)
            cout << arr[i] << " ";
        cout << endl;
    }
};

// --- Generic Pair ---
template <typename T1, typename T2>
class Pair {
    T1 first;
    T2 second;
public:
    Pair(T1 f, T2 s) : first(f), second(s) {}

    T1 getFirst()  { return first;  }
    T2 getSecond() { return second; }

    void display() {
        cout << "(" << first << ", " << second << ")" << endl;
    }
};

// --- Generic Array Wrapper ---
template <typename T, int SIZE>    // Non-type template parameter
class FixedArray {
    T arr[SIZE];
    int count;
public:
    FixedArray() : count(0) {}

    bool add(T val) {
        if(count < SIZE) { arr[count++] = val; return true; }
        return false;
    }
    T get(int i) { return arr[i]; }
    int size()   { return count; }

    void display() {
        cout << "FixedArray[" << SIZE << "]: ";
        for(int i = 0; i < count; i++) cout << arr[i] << " ";
        cout << endl;
    }
};

// ============================================================
// 3. OVERLOADING FUNCTION TEMPLATES
// ============================================================

// Template 1: Same type, two params
template <typename T>
T add(T a, T b) {
    cout << "  [T, T] ";
    return a + b;
}

// Template 2: Two different types
template <typename T1, typename T2>
double add(T1 a, T2 b) {
    cout << "  [T1, T2] ";
    return (double)(a + b);
}

// Regular function overload (specific type)
string add(string a, string b) {
    cout << "  [string] ";
    return a + b;
}

// ============================================================
// 4. RECURSIVE TEMPLATE FUNCTION
// ============================================================
template <typename T>
T factorial(T n) {
    if(n <= 1) return 1;
    return n * factorial(n - 1);
}

template <typename T>
T power(T base, int exp) {
    if(exp == 0) return 1;
    if(exp < 0)  return 1.0 / power(base, -exp);
    return base * power(base, exp - 1);
}

template <typename T>
T fibonacci(int n) {
    if(n <= 0) return 0;
    if(n == 1) return 1;
    return fibonacci<T>(n-1) + fibonacci<T>(n-2);
}

// ============================================================
// 5. CLASS TEMPLATE + INHERITANCE
// ============================================================
template <typename T>
class Container {
protected:
    T data;
public:
    Container(T d) : data(d) {}
    virtual void display() {
        cout << "Container: " << data << endl;
    }
    T getData() { return data; }
};

// Non-template derived from template base
class IntContainer : public Container<int> {
public:
    IntContainer(int d) : Container<int>(d) {}
    void display() override {
        cout << "IntContainer: " << data
             << " | Squared: " << data*data << endl;
    }
};

// Template derived from template base
template <typename T>
class PrintContainer : public Container<T> {
public:
    PrintContainer(T d) : Container<T>(d) {}
    void display() override {
        cout << ">>> " << this->data << " <<<" << endl;
    }
};

// ============================================================
// 6. TEMPLATE vs MACRO DEMO
// ============================================================
#define MACRO_SQUARE(x)   ((x) * (x))        // Macro
#define MACRO_MAX(a,b)    ((a)>(b)?(a):(b))  // Macro

template <typename T>
T tmpl_square(T x) { return x * x; }         // Template

template <typename T>
T tmpl_max(T a, T b) { return (a > b) ? a : b; }

// ============================================================
// MAIN
// ============================================================
int main() {

    cout << "===== 1. FUNCTION TEMPLATES =====" << endl;
    int    ia = 5,  ib = 3;
    float  fa = 2.5, fb = 7.8;
    string sa = "Hello", sb = "World";

    mySwap(ia, ib);
    cout << "Swapped ints: " << ia << ", " << ib << endl;
    mySwap(fa, fb);
    cout << "Swapped floats: " << fa << ", " << fb << endl;
    mySwap(sa, sb);
    cout << "Swapped strings: " << sa << ", " << sb << endl;

    cout << "\nMax(3,7,5)   = " << findMax(3,7,5)     << endl;
    cout << "Max(1.2,3.4,2.1)=" << findMax(1.2,3.4,2.1)<< endl;

    int    arr1[] = {5,2,8,1,9,3};
    float  arr2[] = {3.5f,1.2f,7.8f,4.4f};

    printArray(arr1, 6, "Before sort");
    bubbleSort(arr1, 6);
    printArray(arr1, 6, "After sort ");

    printArray(arr2, 4, "Before sort");
    bubbleSort(arr2, 4);
    printArray(arr2, 4, "After sort ");

    int pos = linearSearch(arr1, 6, 8);
    cout << "Search 8 in arr1: index " << pos << endl;

    cout << "\n===== 2. CLASS TEMPLATES =====" << endl;

    Stack<int> iStack;
    iStack.push(10); iStack.push(20); iStack.push(30);
    iStack.display();
    cout << "Popped: " << iStack.pop() << endl;
    iStack.display();

    Stack<string> sStack;
    sStack.push("Hello"); sStack.push("World"); sStack.push("C++");
    sStack.display();

    Pair<string, int>   p1("Age", 25);
    Pair<float, float>  p2(3.14f, 2.71f);
    Pair<string, string> p3("Name", "Alice");
    p1.display(); p2.display(); p3.display();

    FixedArray<int, 5> fa2;
    fa2.add(1); fa2.add(2); fa2.add(3);
    fa2.display();

    cout << "\n===== 3. FUNCTION TEMPLATE OVERLOADING =====" << endl;
    cout << "add(3,4)       = " << add(3, 4)           << endl;
    cout << "add(3.5f,2.5f) = " << add(3.5f, 2.5f)    << endl;
    cout << "add(3,2.5)     = " << add(3, 2.5)         << endl;
    cout << "add(str,str)   = " << add(string("Hi "), string("There")) << endl;

    cout << "\n===== 4. RECURSIVE TEMPLATES =====" << endl;
    cout << "factorial(5)   = " << factorial(5)    << endl;
    cout << "factorial(10)  = " << factorial(10)   << endl;
    cout << "power(2,10)    = " << power(2, 10)    << endl;
    cout << "power(2.5,3)   = " << power(2.5, 3)   << endl;
    cout << "Fibonacci(10)  = " << fibonacci<int>(10) << endl;

    cout << "\n===== 5. TEMPLATE + INHERITANCE =====" << endl;
    IntContainer ic(7);
    ic.display();

    PrintContainer<string> pc("C++ Templates");
    pc.display();

    PrintContainer<double> pd(3.14159);
    pd.display();

    cout << "\n===== 6. TEMPLATE vs MACRO =====" << endl;
    int val = 3;

    cout << "MACRO_SQUARE(val+1)  = "
         << MACRO_SQUARE(val+1)   << " (expected 16, got 7 — BUG!)" << endl;
    //     expands to: (val+1 * val+1) = (3+1*3+1) = 7 ← WRONG

    cout << "tmpl_square(val+1)   = "
         << tmpl_square(val+1)    << " (expected 16, correct!)" << endl;
    //     evaluates val+1=4 first, then 4*4=16 ← CORRECT

    cout << "MACRO_MAX(3, 4)      = " << MACRO_MAX(3, 4)    << endl;
    cout << "tmpl_max(3, 4)       = " << tmpl_max(3, 4)     << endl;

    cout << "\nTemplate Advantages over Macros:" << endl;
    cout << "  ✓ Type-safe (compiler checks types)" << endl;
    cout << "  ✓ Respects scope" << endl;
    cout << "  ✓ No text-substitution bugs" << endl;
    cout << "  ✓ Supports recursion" << endl;
    cout << "  ✓ Debuggable" << endl;
    cout << "  ✗ Slightly more complex syntax" << endl;

    return 0;
}

// ============================================================
// VIVA POINTS:
// Q: What is 'typename' keyword?
//    A: Declares T as a type parameter in template
//       'class' can also be used instead of 'typename'
//
// Q: When is template code compiled?
//    A: At compile time when instantiated with specific type
//
// Q: What is template specialization?
//    A: Writing a specific version of template for a particular type
//       template<> int add(int a, int b) { ... }
//
// Q: Can templates be recursive?    A: YES
//
// Q: Template vs Macro key difference?
//    A: Type safety, scope, no substitution bugs
// ============================================================
