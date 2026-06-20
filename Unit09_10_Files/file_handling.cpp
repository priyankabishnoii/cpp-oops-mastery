// ============================================================
// UNIT 9 & 10: STREAMS AND FILE HANDLING
// ============================================================
// 1. C++ Streams & Stream Classes
// 2. Writing & Reading Files
// 3. End of File Detection
// 4. File Modes
// 5. File Pointers (seekg, seekp, tellg, tellp)
// 6. Sequential & Binary File I/O
// 7. Command Line Arguments
// ============================================================

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

// ============================================================
// STRUCTURE for binary file demo
// ============================================================
struct StudentRecord {
    char  name[30];
    int   roll;
    float marks;
};

// ============================================================
// FUNCTION DEMOS
// ============================================================

// --- 1. Write Text File ---
void writeTextFile() {
    ofstream fout("students.txt");    // ios::out by default
    if(!fout) {
        cout << "Error: Cannot create file!" << endl;
        return;
    }
    fout << "Rahul   101  89.5" << endl;
    fout << "Priya   102  95.0" << endl;
    fout << "Amit    103  78.5" << endl;
    fout << "Sneha   104  92.0" << endl;
    fout << "Vikram  105  85.5" << endl;
    fout.close();
    cout << "✓ Text file written: students.txt" << endl;
}

// --- 2. Read Text File ---
void readTextFile() {
    ifstream fin("students.txt");
    if(!fin) {
        cout << "Error: File not found!" << endl;
        return;
    }
    string name;
    int    roll;
    float  marks;

    cout << "\nName\t\tRoll\tMarks" << endl;
    cout << "--------------------------------" << endl;

    while(fin >> name >> roll >> marks) {    // EOF detection
        cout << name << "\t\t" << roll << "\t" << marks << endl;
    }
    fin.close();
}

// --- 3. Append to File ---
void appendToFile() {
    ofstream fout("students.txt", ios::app);  // Append mode
    fout << "Deepak  106  91.0" << endl;
    fout.close();
    cout << "\n✓ Appended new record to students.txt" << endl;
}

// --- 4. File Pointer Manipulation ---
void filePointerDemo() {
    // Write some data
    ofstream fw("pointer_demo.txt");
    fw << "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    fw.close();

    fstream f("pointer_demo.txt", ios::in | ios::out);

    cout << "\n--- File Pointer Demo ---" << endl;
    cout << "Initial tellg: " << f.tellg() << endl;  // 0

    // Move to position 5 from beginning
    f.seekg(5, ios::beg);
    char ch;
    f.get(ch);
    cout << "Char at pos 5: " << ch << endl;          // F
    cout << "After read tellg: " << f.tellg() << endl; // 6

    // Move to end
    f.seekg(0, ios::end);
    cout << "File size: " << f.tellg() << " bytes" << endl; // 26

    // Move 3 from end
    f.seekg(-3, ios::end);
    f.get(ch);
    cout << "Char 3 before end: " << ch << endl;      // X

    f.close();
}

// --- 5. Binary File Write & Read ---
void binaryFileDemo() {
    // Write binary
    ofstream fbout("students.dat", ios::binary);
    StudentRecord records[] = {
        {"Rahul",  101, 89.5},
        {"Priya",  102, 95.0},
        {"Amit",   103, 78.5},
        {"Sneha",  104, 92.0}
    };
    for(auto& r : records)
        fbout.write((char*)&r, sizeof(StudentRecord));
    fbout.close();
    cout << "\n✓ Binary file written: students.dat" << endl;

    // Read binary
    ifstream fbin("students.dat", ios::binary);
    StudentRecord s;
    cout << "\n--- Binary File Records ---" << endl;
    while(fbin.read((char*)&s, sizeof(StudentRecord))) {
        cout << "Name: "  << s.name  << " | "
             << "Roll: "  << s.roll  << " | "
             << "Marks: " << s.marks << endl;
    }
    fbin.close();
}

// --- 6. Random Access — Update a Record ---
void randomAccessDemo() {
    // Read record 2 (index 1)
    fstream frw("students.dat",
                ios::in | ios::out | ios::binary);

    int recordNum = 1;  // 0-based: record index 1 = Priya
    frw.seekg(recordNum * sizeof(StudentRecord), ios::beg);

    StudentRecord s;
    frw.read((char*)&s, sizeof(StudentRecord));
    cout << "\n--- Before Update ---" << endl;
    cout << "Record " << recordNum << ": " << s.name
         << " Marks=" << s.marks << endl;

    // Update marks
    s.marks = 99.9;
    frw.seekp(recordNum * sizeof(StudentRecord), ios::beg);
    frw.write((char*)&s, sizeof(StudentRecord));
    frw.close();

    // Verify update
    fstream fverify("students.dat", ios::in | ios::binary);
    fverify.seekg(recordNum * sizeof(StudentRecord), ios::beg);
    fverify.read((char*)&s, sizeof(StudentRecord));
    cout << "--- After Update ---" << endl;
    cout << "Record " << recordNum << ": " << s.name
         << " Marks=" << s.marks << endl;
    fverify.close();
}

// --- 7. getline Demo ---
void getlineDemo() {
    ofstream fw("lines.txt");
    fw << "First line of the file"  << endl;
    fw << "Second line here"        << endl;
    fw << "Third and final line"    << endl;
    fw.close();

    ifstream fr("lines.txt");
    string line;
    int    lineNum = 1;
    cout << "\n--- Reading Line by Line ---" << endl;
    while(getline(fr, line)) {
        cout << lineNum++ << ": " << line << endl;
    }
    fr.close();
}

// ============================================================
// MAIN
// ============================================================
int main() {

    cout << "========== TEXT FILE OPERATIONS ==========" << endl;
    writeTextFile();
    readTextFile();
    appendToFile();
    cout << "\n--- After Append ---" << endl;
    readTextFile();

    cout << "\n========== FILE POINTER MANIPULATION ==========" << endl;
    filePointerDemo();

    cout << "\n========== BINARY FILE OPERATIONS ==========" << endl;
    binaryFileDemo();

    cout << "\n========== RANDOM ACCESS ==========" << endl;
    randomAccessDemo();

    cout << "\n========== GETLINE DEMO ==========" << endl;
    getlineDemo();

    cout << "\n========== FILE MODES SUMMARY ==========" << endl;
    cout << "ios::in     → Read only"                  << endl;
    cout << "ios::out    → Write (truncate)"           << endl;
    cout << "ios::app    → Write at end (append)"      << endl;
    cout << "ios::ate    → Open & go to end"           << endl;
    cout << "ios::binary → Binary mode"                << endl;
    cout << "ios::trunc  → Truncate existing content"  << endl;

    return 0;
}

// ============================================================
// OUTPUT:
// ========== TEXT FILE OPERATIONS ==========
// ✓ Text file written: students.txt
// Name            Roll    Marks
// --------------------------------
// Rahul           101     89.5
// Priya           102     95
// Amit            103     78.5
// Sneha           104     92
// Vikram          105     85.5
//
// ✓ Appended new record to students.txt
//
// --- After Append ---
// (All 6 records shown)
//
// ========== FILE POINTER MANIPULATION ==========
// Initial tellg: 0
// Char at pos 5: F
// After read tellg: 6
// File size: 26 bytes
// Char 3 before end: X
// ============================================================

// ============================================================
// VIVA POINTS:
// Q: Difference between ios::app and ios::ate?
//    A: app = every write goes to end (enforced)
//       ate = pointer goes to end at open, but can move it
//
// Q: seekg vs seekp?
//    A: seekg = move GET (read) pointer
//       seekp = move PUT (write) pointer
//
// Q: How to detect EOF?
//    A: while(fin >> var) or while(getline(fin,line))
//       or while(!fin.eof())
//
// Q: What is binary mode?
//    A: Data written as raw bytes — no \n conversion
//       Needed for struct/int/float etc.
//
// Q: write() and read() parameters?
//    A: write((char*)&variable, sizeof(variable))
//       read((char*)&variable, sizeof(variable))
// ============================================================
