// ============================================================
// UNIT 5: OPERATOR OVERLOADING
// ============================================================
// 1. Unary Operator Overloading
// 2. Binary Operator Overloading
// 3. Binary Operator using Friend Function
// 4. Relational Operator Overloading
// ============================================================

#include<iostream>
using namespace std;

// ============================================================
// 1. UNARY OPERATOR OVERLOADING
// ============================================================
class Vector3D {
    int x, y, z;
public:
    Vector3D(int a=0, int b=0, int c=0): x(a), y(b), z(c) {}

    // Unary minus: -v
    Vector3D operator-() {
        return Vector3D(-x, -y, -z);
    }

    // Unary pre-increment: ++v
    Vector3D operator++() {
        return Vector3D(++x, ++y, ++z);
    }

    // Unary post-increment: v++
    Vector3D operator++(int) {      // dummy int = postfix
        Vector3D temp(x, y, z);
        x++; y++; z++;
        return temp;
    }

    // Logical NOT: !v (checks if zero vector)
    bool operator!() {
        return (x==0 && y==0 && z==0);
    }

    void display() {
        cout << "(" << x << ", " << y << ", " << z << ")";
    }
};

// ============================================================
// 2. BINARY OPERATOR OVERLOADING (Member Function)
// ============================================================
class Complex {
    float real, imag;
public:
    Complex(float r=0, float i=0): real(r), imag(i) {}

    Complex operator+(Complex c) {        // Addition
        return Complex(real+c.real, imag+c.imag);
    }
    Complex operator-(Complex c) {        // Subtraction
        return Complex(real-c.real, imag-c.imag);
    }
    Complex operator*(Complex c) {        // Multiplication
        return Complex(
            real*c.real - imag*c.imag,
            real*c.imag + imag*c.real
        );
    }
    bool operator==(Complex c) {          // Equal comparison
        return (real==c.real && imag==c.imag);
    }
    bool operator!=(Complex c) {          // Not equal
        return !(*this == c);
    }

    void display() {
        cout << real;
        if(imag >= 0) cout << " + " <<  imag << "i";
        else          cout << " - " << -imag << "i";
    }
};

// ============================================================
// 3. BINARY OPERATOR — FRIEND FUNCTION
// Both operands passed explicitly
// ============================================================
class Matrix2x2 {
    float a[2][2];
public:
    Matrix2x2(float a00=0,float a01=0,float a10=0,float a11=0) {
        a[0][0]=a00; a[0][1]=a01;
        a[1][0]=a10; a[1][1]=a11;
    }

    // Friend function — both matrices as parameters
    friend Matrix2x2 operator+(Matrix2x2 m1, Matrix2x2 m2);
    friend Matrix2x2 operator*(Matrix2x2 m1, Matrix2x2 m2);
    friend ostream& operator<<(ostream& os, Matrix2x2 m);
};

Matrix2x2 operator+(Matrix2x2 m1, Matrix2x2 m2) {
    return Matrix2x2(
        m1.a[0][0]+m2.a[0][0], m1.a[0][1]+m2.a[0][1],
        m1.a[1][0]+m2.a[1][0], m1.a[1][1]+m2.a[1][1]
    );
}

Matrix2x2 operator*(Matrix2x2 m1, Matrix2x2 m2) {
    return Matrix2x2(
        m1.a[0][0]*m2.a[0][0]+m1.a[0][1]*m2.a[1][0],
        m1.a[0][0]*m2.a[0][1]+m1.a[0][1]*m2.a[1][1],
        m1.a[1][0]*m2.a[0][0]+m1.a[1][1]*m2.a[1][0],
        m1.a[1][0]*m2.a[0][1]+m1.a[1][1]*m2.a[1][1]
    );
}

ostream& operator<<(ostream& os, Matrix2x2 m) {
    os << "| " << m.a[0][0] << " " << m.a[0][1] << " |" << endl;
    os << "| " << m.a[1][0] << " " << m.a[1][1] << " |";
    return os;
}

// ============================================================
// MAIN
// ============================================================
int main() {
    cout << "===== UNARY OPERATOR OVERLOADING =====" << endl;
    Vector3D v1(3, -4, 5);
    cout << "v1        = "; v1.display(); cout << endl;

    Vector3D v2 = -v1;
    cout << "-v1       = "; v2.display(); cout << endl;

    ++v1;
    cout << "++v1      = "; v1.display(); cout << endl;

    v1++;
    cout << "v1++      = "; v1.display(); cout << endl;

    Vector3D zero(0,0,0);
    cout << "!zero     = " << !zero << " (1=true)" << endl;
    cout << "!v1       = " << !v1   << " (0=false)" << endl;

    cout << "\n===== BINARY OPERATOR OVERLOADING =====" << endl;
    Complex c1(3.0, 4.0), c2(1.5, -2.0);
    cout << "c1 = "; c1.display(); cout << endl;
    cout << "c2 = "; c2.display(); cout << endl;

    Complex c3 = c1 + c2;
    cout << "c1+c2 = "; c3.display(); cout << endl;

    Complex c4 = c1 - c2;
    cout << "c1-c2 = "; c4.display(); cout << endl;

    Complex c5 = c1 * c2;
    cout << "c1*c2 = "; c5.display(); cout << endl;

    cout << "c1==c2: " << (c1==c2) << " | c1!=c2: " << (c1!=c2) << endl;

    cout << "\n===== FRIEND FUNCTION OPERATOR OVERLOADING =====" << endl;
    Matrix2x2 m1(1,2,3,4), m2(5,6,7,8);
    cout << "Matrix M1:\n" << m1 << endl;
    cout << "\nMatrix M2:\n" << m2 << endl;
    cout << "\nM1 + M2:\n"   << (m1+m2) << endl;
    cout << "\nM1 * M2:\n"   << (m1*m2) << endl;

    return 0;
}

// ============================================================
// OUTPUT:
// ===== UNARY OPERATOR OVERLOADING =====
// v1        = (3, -4, 5)
// -v1       = (-3, 4, -5)
// ++v1      = (4, -3, 6)
// v1++      = (4, -3, 6)    ← post-increment returns OLD value
//
// ===== BINARY OPERATOR OVERLOADING =====
// c1 = 3 + 4i
// c2 = 1.5 - 2i
// c1+c2 = 4.5 + 2i
// c1-c2 = 1.5 + 6i
// ============================================================

// ============================================================
// VIVA POINTS:
// Q: Which operators CANNOT be overloaded?
//    A: :: (scope) . (dot) .* (member ptr) ?: (ternary) sizeof
//
// Q: Member vs Friend for operator overloading?
//    A: Member: left operand = this (1 param for binary)
//       Friend: both explicit (2 params for binary)
//
// Q: Can we create new operators?
//    A: NO — can only redefine existing ones
//
// Q: Can we change operator precedence?
//    A: NO — precedence & associativity remain same
// ============================================================
