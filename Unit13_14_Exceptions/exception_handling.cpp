// ============================================================
// UNIT 13 & 14: EXCEPTION HANDLING — COMPLETE
// ============================================================
// 1. Basic Exception Handling (try-catch-throw)
// 2. Multiple Catch Statements
// 3. Catching Multiple Exception Types
// 4. Custom Exception Classes
// 5. Re-throwing Exceptions
// 6. Exceptions in Constructors & Destructors
// 7. Controlling Uncaught Exceptions (set_terminate)
// ============================================================

#include<iostream>
#include<exception>
#include<stdexcept>
#include<string>
using namespace std;

// ============================================================
// 1. BASIC EXCEPTION HANDLING
// ============================================================
float safeDivide(float a, float b) {
    if(b == 0)
        throw "Division by zero is not allowed!";  // throw string
    return a / b;
}

int safeArrayAccess(int arr[], int size, int index) {
    if(index < 0 || index >= size)
        throw index;                                // throw int
    return arr[index];
}

void basicDemo() {
    cout << "\n--- 1. Basic try-catch-throw ---" << endl;

    // Test 1: Normal execution
    try {
        float result = safeDivide(10, 2);
        cout << "10 / 2 = " << result << endl;
    }
    catch(const char* msg) {
        cout << "Error: " << msg << endl;
    }

    // Test 2: Exception thrown
    try {
        float result = safeDivide(10, 0);   // throws!
        cout << "Result = " << result;      // skipped
    }
    catch(const char* msg) {
        cout << "Caught: " << msg << endl;
    }

    cout << "Program continues after exception..." << endl;

    // Test 3: Array out of bounds
    int arr[] = {10, 20, 30, 40, 50};
    try {
        cout << "arr[2] = " << safeArrayAccess(arr, 5, 2) << endl;
        cout << "arr[9] = " << safeArrayAccess(arr, 5, 9); // throws!
    }
    catch(int badIndex) {
        cout << "Invalid index: " << badIndex
             << " (valid: 0-4)" << endl;
    }
}

// ============================================================
// 2. MULTIPLE CATCH STATEMENTS
// ============================================================
void throwDifferentTypes(int choice) {
    switch(choice) {
        case 1: throw 42;                      // int
        case 2: throw 3.14;                    // double
        case 3: throw 'E';                     // char
        case 4: throw "String error!";         // const char*
        case 5: throw string("std::string!");  // std::string
        case 6: throw runtime_error("Runtime error occurred!"); // std exception
        default: cout << "No exception thrown." << endl;
    }
}

void multipleCatchDemo() {
    cout << "\n--- 2. Multiple Catch Statements ---" << endl;

    for(int i = 1; i <= 7; i++) {
        cout << "Choice " << i << ": ";
        try {
            throwDifferentTypes(i);
        }
        catch(int e) {
            cout << "int exception      = " << e << endl;
        }
        catch(double e) {
            cout << "double exception   = " << e << endl;
        }
        catch(char e) {
            cout << "char exception     = " << e << endl;
        }
        catch(const char* e) {
            cout << "c-string exception = " << e << endl;
        }
        catch(string e) {
            cout << "string exception   = " << e << endl;
        }
        catch(runtime_error& e) {
            cout << "runtime_error      = " << e.what() << endl;
        }
        catch(...) {                           // Catch ALL — must be LAST
            cout << "Unknown exception caught!" << endl;
        }
    }
}

// ============================================================
// 3. CUSTOM EXCEPTION CLASSES
// ============================================================

// Base custom exception
class AppException : public exception {
protected:
    string message;
    int    errorCode;
public:
    AppException(string msg, int code = 0)
        : message(msg), errorCode(code) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
    int getCode() { return errorCode; }
};

// Specific custom exceptions
class DivisionByZeroException : public AppException {
public:
    DivisionByZeroException()
        : AppException("Division by zero!", 1001) {}
};

class NegativeValueException : public AppException {
    float value;
public:
    NegativeValueException(float v)
        : AppException("Negative value not allowed!", 1002), value(v) {}
    float getValue() { return value; }
};

class OutOfRangeException : public AppException {
    float min, max, actual;
public:
    OutOfRangeException(float v, float lo, float hi)
        : AppException("Value out of range!", 1003),
          min(lo), max(hi), actual(v) {}
    void showRange() {
        cout << "  Value=" << actual
             << " | Valid range: [" << min << ", " << max << "]" << endl;
    }
};

class InsufficientFundsException : public AppException {
    double required, available;
public:
    InsufficientFundsException(double req, double avail)
        : AppException("Insufficient funds!", 1004),
          required(req), available(avail) {}
    void showDetails() {
        cout << "  Required : " << required  << endl;
        cout << "  Available: " << available << endl;
        cout << "  Shortfall: " << required - available << endl;
    }
};

float processValue(float val) {
    if(val == 0)    throw DivisionByZeroException();
    if(val < 0)     throw NegativeValueException(val);
    if(val > 1000)  throw OutOfRangeException(val, 0, 1000);
    return 100.0 / val;
}

void customExceptionDemo() {
    cout << "\n--- 3. Custom Exception Classes ---" << endl;

    float testValues[] = {5.0, 0.0, -3.5, 1500.0, 25.0};

    for(float v : testValues) {
        cout << "processValue(" << v << "): ";
        try {
            float result = processValue(v);
            cout << "Result = " << result << endl;
        }
        catch(DivisionByZeroException& e) {
            cout << "Error[" << e.getCode() << "]: " << e.what() << endl;
        }
        catch(NegativeValueException& e) {
            cout << "Error[" << e.getCode() << "]: " << e.what()
                 << " (got " << e.getValue() << ")" << endl;
        }
        catch(OutOfRangeException& e) {
            cout << "Error[" << e.getCode() << "]: " << e.what() << endl;
            e.showRange();
        }
        catch(AppException& e) {        // Catch base — catches any app error
            cout << "AppError: " << e.what() << endl;
        }
    }

    // Bank Account exception demo
    cout << "\n--- Bank Transaction Demo ---" << endl;
    double balance = 5000.0;
    double withdrawals[] = {2000.0, 1500.0, 2000.0, 3000.0};

    for(double amount : withdrawals) {
        try {
            cout << "Withdrawing " << amount << ": ";
            if(amount > balance)
                throw InsufficientFundsException(amount, balance);
            balance -= amount;
            cout << "Success! Balance = " << balance << endl;
        }
        catch(InsufficientFundsException& e) {
            cout << e.what() << endl;
            e.showDetails();
        }
    }
}

// ============================================================
// 4. RE-THROWING EXCEPTIONS
// ============================================================
void lowLevelFunction() {
    cout << "  [Low Level] Processing..." << endl;
    throw runtime_error("Database connection failed!");
}

void midLevelFunction() {
    try {
        lowLevelFunction();
    }
    catch(runtime_error& e) {
        cout << "  [Mid Level] Caught: " << e.what() << endl;
        cout << "  [Mid Level] Logging to file..." << endl;
        cout << "  [Mid Level] Re-throwing to higher level..." << endl;
        throw;   // RE-THROW — same exception, no argument
    }
}

void highLevelFunction() {
    try {
        midLevelFunction();
    }
    catch(runtime_error& e) {
        cout << "  [High Level] Final handling: " << e.what() << endl;
        cout << "  [High Level] Sending alert to admin..." << endl;
        cout << "  [High Level] Graceful shutdown initiated." << endl;
    }
}

void rethrowDemo() {
    cout << "\n--- 4. Re-throwing Exceptions ---" << endl;
    highLevelFunction();
    cout << "Program continues after full exception chain." << endl;
}

// ============================================================
// 5. EXCEPTIONS IN CONSTRUCTORS
// ============================================================
class SafeArray {
    int  *data;
    int   size;
    bool  initialized;

public:
    SafeArray(int s) {
        cout << "  [Constructor] Trying to create array of size " << s << endl;

        if(s <= 0) {
            initialized = false;
            throw invalid_argument("Size must be positive!");
        }
        if(s > 10000) {
            initialized = false;
            throw overflow_error("Size too large! Max allowed: 10000");
        }

        data        = new int[s];    // Memory allocated
        size        = s;
        initialized = true;

        for(int i = 0; i < size; i++) data[i] = i * 10;
        cout << "  [Constructor] Array of size " << s
             << " created successfully." << endl;
    }

    void display() {
        for(int i = 0; i < min(size, 5); i++)
            cout << data[i] << " ";
        if(size > 5) cout << "...";
        cout << endl;
    }

    ~SafeArray() {
        if(initialized) {
            delete[] data;
            cout << "  [Destructor] Memory freed for array of size "
                 << size << endl;
        }
        else {
            cout << "  [Destructor] NOT called — object not fully created" << endl;
        }
    }
};

void constructorExceptionDemo() {
    cout << "\n--- 5. Exceptions in Constructors ---" << endl;

    // Test 1: Valid size
    cout << "Creating arr1(5):" << endl;
    try {
        SafeArray arr1(5);
        arr1.display();
    }
    catch(exception& e) {
        cout << "  Error: " << e.what() << endl;
    }

    // Test 2: Invalid (negative)
    cout << "\nCreating arr2(-3):" << endl;
    try {
        SafeArray arr2(-3);    // Constructor throws!
        arr2.display();        // Never reached
    }
    catch(invalid_argument& e) {
        cout << "  Caught: " << e.what() << endl;
        cout << "  Note: Destructor NOT called for arr2" << endl;
    }

    // Test 3: Too large
    cout << "\nCreating arr3(99999):" << endl;
    try {
        SafeArray arr3(99999);
    }
    catch(overflow_error& e) {
        cout << "  Caught: " << e.what() << endl;
    }
}

// ============================================================
// 6. EXCEPTIONS IN DESTRUCTORS
// ============================================================
class ResourceHolder {
    string name;
public:
    ResourceHolder(string n) : name(n) {
        cout << "  [" << name << "] Resource acquired." << endl;
    }
    ~ResourceHolder() {
        cout << "  [" << name << "] Resource released." << endl;
        // NEVER throw from destructor!
        // If an exception propagates while destructor is running
        // during stack unwinding → terminate() is called!
    }
};

void destructorDemo() {
    cout << "\n--- 6. Stack Unwinding with Destructors ---" << endl;
    try {
        ResourceHolder r1("FileHandle");
        ResourceHolder r2("NetworkConn");
        ResourceHolder r3("DatabaseConn");
        cout << "  All resources acquired. Now throwing..." << endl;
        throw runtime_error("Simulated system failure!");
        // Stack unwinds: r3 destroyed, r2 destroyed, r1 destroyed
    }
    catch(runtime_error& e) {
        cout << "  Caught: " << e.what() << endl;
        cout << "  All resources safely released via RAII." << endl;
    }
}

// ============================================================
// 7. CONTROLLING UNCAUGHT EXCEPTIONS
// ============================================================
void myTerminateHandler() {
    cout << "\n  *** Custom Terminate Handler Called ***" << endl;
    cout << "  Performing emergency cleanup..." << endl;
    cout << "  Saving logs..." << endl;
    cout << "  Exiting gracefully." << endl;
    exit(1);    // MUST exit — never return from terminate handler
}

void terminateDemo() {
    cout << "\n--- 7. set_terminate Demo ---" << endl;

    // Set custom handler
    terminate_handler oldHandler = set_terminate(myTerminateHandler);

    cout << "Custom terminate handler set." << endl;
    cout << "In real usage: an uncaught exception would trigger it." << endl;
    cout << "(Skipping actual uncaught throw to not crash demo)" << endl;

    // Restore old handler
    set_terminate(oldHandler);
}

// ============================================================
// 8. NESTED TRY-CATCH
// ============================================================
void nestedTryCatchDemo() {
    cout << "\n--- 8. Nested try-catch ---" << endl;

    try {                                    // Outer try
        cout << "Outer try block" << endl;
        try {                                // Inner try
            cout << "Inner try block" << endl;
            throw 42;                        // Throw int
        }
        catch(double e) {
            cout << "Inner catch(double) — NO MATCH" << endl;
        }
        // int not caught by inner → propagates to outer
        cout << "This line NOT reached" << endl;
    }
    catch(int e) {
        cout << "Outer catch(int) = " << e
             << " — Caught here!" << endl;
    }
}

// ============================================================
// MAIN
// ============================================================
int main() {
    cout << "╔══════════════════════════════════════════╗" << endl;
    cout << "║   COMPLETE EXCEPTION HANDLING DEMO       ║" << endl;
    cout << "╚══════════════════════════════════════════╝" << endl;

    basicDemo();
    multipleCatchDemo();
    customExceptionDemo();
    rethrowDemo();
    constructorExceptionDemo();
    destructorDemo();
    terminateDemo();
    nestedTryCatchDemo();

    cout << "\n╔══════════════════════════════════════════╗" << endl;
    cout << "║   ALL EXCEPTION DEMOS COMPLETE           ║" << endl;
    cout << "╚══════════════════════════════════════════╝" << endl;

    return 0;
}

// ============================================================
// OUTPUT (partial):
// --- 1. Basic try-catch-throw ---
// 10 / 2 = 5
// Caught: Division by zero is not allowed!
// Program continues after exception...
// arr[2] = 30
// Invalid index: 9 (valid: 0-4)
//
// --- 4. Re-throwing Exceptions ---
// [Low Level] Processing...
// [Mid Level] Caught: Database connection failed!
// [Mid Level] Logging to file...
// [Mid Level] Re-throwing to higher level...
// [High Level] Final handling: Database connection failed!
// [High Level] Sending alert to admin...
//
// --- 5. Exceptions in Constructors ---
// Creating arr1(5):
//   [Constructor] Array of size 5 created successfully.
//   0 10 20 30 40
//   [Destructor] Memory freed for array of size 5
//
// Creating arr2(-3):
//   [Constructor] Trying to create array of size -3
//   Caught: Size must be positive!
//   Note: Destructor NOT called for arr2
// ============================================================

// ============================================================
// VIVA POINTS:
// Q: What is try-catch-throw?
//    A: try = risky code block
//       throw = signal an error
//       catch = handle the error
//
// Q: What is catch(...)?
//    A: Catches ANY exception type. Must be LAST catch block.
//
// Q: What is re-throwing?
//    A: throw; (no arg) inside catch — sends same exception up
//
// Q: What happens when constructor throws?
//    A: Object NOT fully created, destructor NOT called
//       Memory allocated before throw may leak!
//
// Q: Should we throw from destructor?
//    A: NO! During stack unwinding, if destructor throws,
//       terminate() is called immediately
//
// Q: What is set_terminate?
//    A: Sets custom function called when exception is uncaught
//       Custom handler must NOT return — must exit/abort
//
// Q: What is stack unwinding?
//    A: When exception thrown, C++ destroys all local objects
//       in scope by calling their destructors (LIFO order)
//
// Q: What is RAII?
//    A: Resource Acquisition Is Initialization
//       Resources acquired in constructor, released in destructor
//       Ensures cleanup even when exceptions occur
// ============================================================
