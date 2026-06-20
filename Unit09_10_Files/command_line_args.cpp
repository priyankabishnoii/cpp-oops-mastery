// ============================================================
// UNIT 10: COMMAND LINE ARGUMENTS
// ============================================================
// argc = argument count (includes program name)
// argv = array of argument strings
// argv[0] = always the program name/path
// Actual arguments start from argv[1]
// ============================================================

#include<iostream>
#include<cstdlib>    // for atoi(), atof()
using namespace std;

int main(int argc, char* argv[]) {

    cout << "Total arguments (argc): " << argc << endl;
    cout << "Arguments:" << endl;

    for(int i = 0; i < argc; i++) {
        cout << "  argv[" << i << "] = " << argv[i] << endl;
    }

    // Practical usage — calculator from command line
    if(argc == 4) {
        double a = atof(argv[1]);
        char   op = argv[2][0];
        double b = atof(argv[3]);

        cout << "\nCalculating: " << a << " " << op << " " << b << " = ";
        switch(op) {
            case '+': cout << a + b; break;
            case '-': cout << a - b; break;
            case '*': cout << a * b; break;
            case '/':
                if(b != 0) cout << a / b;
                else       cout << "Error: Division by zero";
                break;
            default:  cout << "Unknown operator";
        }
        cout << endl;
    }
    else if(argc < 4) {
        cout << "\nUsage: " << argv[0]
             << " <number1> <operator> <number2>" << endl;
        cout << "Example: " << argv[0] << " 10 + 5" << endl;
    }

    return 0;
}

// ============================================================
// HOW TO COMPILE AND RUN:
//
// $ g++ command_line_args.cpp -o calc
//
// $ ./calc
//   Total arguments: 1
//   argv[0] = ./calc
//   Usage: ./calc <number1> <operator> <number2>
//
// $ ./calc 10 + 5
//   Total arguments: 4
//   argv[0] = ./calc
//   argv[1] = 10
//   argv[2] = +
//   argv[3] = 5
//   Calculating: 10 + 5 = 15
//
// $ ./calc 15 / 3
//   Calculating: 15 / 3 = 5
// ============================================================

// ============================================================
// VIVA POINTS:
// Q: What is argc?
//    A: Argument count — total number of command line arguments
//       INCLUDING the program name. Minimum value = 1
//
// Q: What is argv[0]?
//    A: Always the name/path of the program itself
//
// Q: What type is argv?
//    A: char* argv[] = array of C-style strings
//
// Q: How to convert argv string to int/float?
//    A: atoi(argv[i]) for int, atof(argv[i]) for float
// ============================================================
