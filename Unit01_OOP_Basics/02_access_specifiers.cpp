// ============================================================
// UNIT 1 - TOPIC 2: ACCESS SPECIFIERS
// ============================================================
// private   → only accessible inside the class
// protected → accessible inside class + derived classes
// public    → accessible from anywhere
//
// DEFAULT: class → private | struct → public
// ============================================================

#include<iostream>
using namespace std;

class BankAccount {
    private:
        double balance;        // Hidden from outside world
        string pin;            // Secret - only class can touch

    protected:
        int accountId;         // Accessible in derived class

    public:
        string ownerName;      // Anyone can access

        // Public functions to access private data (Getter/Setter)
        void setBalance(double b) {
            if(b >= 0)
                balance = b;
            else
                cout << "Invalid balance!" << endl;
        }

        double getBalance() {
            return balance;
        }

        void setPin(string p) {
            if(p.length() == 4)
                pin = p;
            else
                cout << "PIN must be 4 digits!" << endl;
        }

        void display() {
            cout << "Owner   : " << ownerName  << endl;
            cout << "Acc ID  : " << accountId  << endl;
            cout << "Balance : " << balance     << endl;
            // pin not printed — kept secret
        }
};

// Demonstrating struct vs class default access
struct PersonStruct {
    string name;   // public by default in struct
    int age;
};

class PersonClass {
    string name;   // private by default in class
    int age;
    public:
        void setData(string n, int a){ name=n; age=a; }
        void show(){ cout << name << " " << age << endl; }
};

int main() {
    BankAccount acc;

    // Public member — direct access OK
    acc.ownerName = "Rahul Sharma";

    // Private members — must use public functions
    acc.setBalance(50000.0);
    acc.setPin("1234");

    // acc.balance = 99999;  // ERROR: balance is private
    // acc.pin = "0000";     // ERROR: pin is private

    acc.display();
    cout << "Balance via getter: " << acc.getBalance() << endl;

    cout << "\n--- Struct vs Class Default Access ---" << endl;
    PersonStruct ps;
    ps.name = "Alice";   // OK — struct is public by default
    ps.age  = 25;
    cout << ps.name << " " << ps.age << endl;

    PersonClass pc;
    // pc.name = "Bob";  // ERROR — class is private by default
    pc.setData("Bob", 30);
    pc.show();

    return 0;
}

// ============================================================
// OUTPUT:
// Owner   : Rahul Sharma
// Acc ID  : 0
// Balance : 50000
// Balance via getter: 50000
//
// --- Struct vs Class Default Access ---
// Alice 25
// Bob 30
// ============================================================

// ============================================================
// VIVA POINTS:
// Q: What is default access in class?    A: private
// Q: What is default access in struct?   A: public
// Q: Can private members be accessed outside? A: NO — compile error
// Q: What is getter/setter pattern?
// A: Public functions that provide controlled access to private data
// ============================================================
