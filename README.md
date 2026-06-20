# 📚 C++ Object-Oriented Programming Complete Study Guide

> **A complete reference for C++ OOP covering all 14 units from beginner to viva-expert level.**
> Includes theory, programs, outputs, viva Q&A

---

## 👨‍💻 Author
Created for University C++ OOP Practical & Viva Preparation

---

## 📁 Repository Structure

```
CPP_OOP_Complete/
│
├── README.md                          ← You are here
│
├── Unit01_OOP_Basics/
│   ├── 01_class_object.cpp
│   ├── 02_access_specifiers.cpp
│   ├── 03_member_functions.cpp
│   ├── 04_nesting_functions.cpp
│   └── 05_arrays_in_class.cpp
│
├── Unit02_Constructors_Destructors/
│   ├── 01_default_constructor.cpp
│   ├── 02_parameterized_constructor.cpp
│   ├── 03_copy_constructor.cpp
│   ├── 04_dynamic_constructor.cpp
│   ├── 05_multiple_constructors.cpp
│   ├── 06_default_arguments.cpp
│   ├── 07_dynamic_initialization.cpp
│   └── 08_destructor.cpp
│
├── Unit03_Functions_Polymorphism/
│   ├── 01_call_by_value_reference.cpp
│   ├── 02_objects_as_arguments.cpp
│   ├── 03_inline_functions.cpp
│   ├── 04_friend_functions.cpp
│   ├── 05_static_members.cpp
│   └── 06_function_overloading.cpp
│
├── Unit04_Inheritance/
│   ├── 01_single_inheritance.cpp
│   ├── 02_private_member_inheritable.cpp
│   ├── 03_multilevel_inheritance.cpp
│   ├── 04_hierarchical_inheritance.cpp
│   ├── 05_multiple_inheritance.cpp
│   └── 06_hybrid_inheritance.cpp
│
├── Unit05_Operator_Overloading/
│   ├── 01_unary_operator.cpp
│   ├── 02_binary_operator.cpp
│   └── 03_friend_operator.cpp
│
├── Unit06_Type_Conversion/
│   ├── 01_basic_to_class.cpp
│   ├── 02_class_to_basic.cpp
│   └── 03_class_to_class.cpp
│
├── Unit07_Runtime_Polymorphism/
│   ├── 01_pointer_to_object.cpp
│   ├── 02_this_pointer.cpp
│   ├── 03_pointer_to_derived.cpp
│   └── 04_abstract_class.cpp
│
├── Unit08_Virtual_Functions/
│   ├── 01_virtual_function.cpp
│   ├── 02_pure_virtual_function.cpp
│   └── 03_early_vs_late_binding.cpp
│
├── Unit09_Streams_Files/
│   ├── 01_file_write_read.cpp
│   └── 02_end_of_file.cpp
│
├── Unit10_More_Files/
│   ├── 01_file_modes.cpp
│   ├── 02_file_pointers.cpp
│   ├── 03_binary_file.cpp
│   └── 04_command_line_args.cpp
│
├── Unit11_Templates/
│   ├── 01_function_template.cpp
│   ├── 02_class_template.cpp
│   └── 03_template_overloading.cpp
│
├── Unit12_More_Templates/
│   ├── 01_recursive_template.cpp
│   ├── 02_template_inheritance.cpp
│   └── 03_template_vs_macro.cpp
│
├── Unit13_Exception_Handling/
│   ├── 01_basic_exception.cpp
│   ├── 02_multiple_catch.cpp
│   └── 03_custom_exception.cpp
│
├── Unit14_More_Exceptions/
│   ├── 01_rethrow.cpp
│   ├── 02_constructor_exception.cpp
│   └── 03_set_terminate.cpp
│
└── VIVA_GUIDE/
    ├── 30_Important_Viva_QA.md
    └── Quick_Reference.md
```

---

## 📋 Unit-wise Topics

| Unit | Topic | Key Concepts |
|------|-------|-------------|
| 1 | OOP Basics | Class, Object, Encapsulation, Abstraction |
| 2 | Constructors & Destructors | Default, Parameterized, Copy, Dynamic, Destructor |
| 3 | Functions & Compile-time Polymorphism | Inline, Friend, Static, Overloading |
| 4 | Inheritance | Single, Multilevel, Hierarchical, Multiple, Hybrid |
| 5 | Operator Overloading | Unary, Binary, Friend Function |
| 6 | Type Conversion | Basic↔Class, Class↔Class |
| 7 | Runtime Polymorphism | this pointer, Pointer to Object/Derived |
| 8 | Virtual Functions | Virtual, Pure Virtual, VTable, Early/Late Binding |
| 9 | Streams & Files | ifstream, ofstream, fstream, EOF |
| 10 | More on Files | File Modes, seekg/seekp, Binary, CMD Args |
| 11 | Templates | Function Template, Class Template |
| 12 | More Templates | Recursion, Inheritance, vs Macros |
| 13 | Exception Handling | try-catch-throw, Multiple catch |
| 14 | More Exceptions | Re-throw, Constructor Exception, terminate |

---

## ⚡ How to Compile & Run

```bash
# Compile any file
g++ filename.cpp -o output

# Run
./output

# With C++17 standard
g++ -std=c++17 filename.cpp -o output
```

---

## 🎯 Viva Quick Tips

- **Class default access** → `private`
- **Struct default access** → `public`
- **Copy constructor** → must take reference (avoid infinite recursion)
- **Destructor order** → LIFO (Last In, First Out)
- **Cannot overload** → `::` `.` `.*` `?:` `sizeof`
- **Virtual constructor** → ❌ NOT possible
- **Virtual destructor** → ✅ ALWAYS use in base class
- **Static function** → No `this` pointer
- **Abstract class** → has at least one pure virtual function (`= 0`)
- **Diamond problem** → solved by `virtual` base class

---

## ⭐ Star this repo if it helped you!
