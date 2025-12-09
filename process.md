# Command Line Calculator - Learning Progress

## Task List

### Module 1: Project Initialization ✅
**Status: COMPLETED**
- [x] Create main.c file
- [x] Basic program structure (main function)
- [x] printf function for output
- [x] Newline character "\n"
- [x] getchar() for pause
- [x] Compile command: `gcc main.c -o calculator.exe`
- [x] Run program successfully
- [x] Understanding return 0

**Key Concepts Learned:**
- C program structure
- Standard input/output library (#include <stdio.h>)
- Basic output with printf
- Program compilation and execution

---

### Module 2: Basic Addition Calculator
**Status: COMPLETED** ✅
- [x] Declare double variables
- [x] Use scanf() to read user input
- [x] Perform addition operation
- [x] Format output with %.2lf
- [x] Understand floating-point precision

**Key Concepts Learned:**
- double data type
- scanf() function
- Format specifiers (%lf)
- Arithmetic operations

---

### Module 3: Complete Four Operations
**Status: PENDING**
- [x] Implement subtraction
- [x] Implement multiplication
- [x] Implement division
- [x] Handle division by zero error
- [x] Use if-else statements

**Key Concepts to Learn:**
- Conditional statements (if-else)
- Error handling basics
- Comparison operators

---

### Module 4: Operation Menu
**Status: PENDING**
- [x] Display menu options
- [x] Read user choice
- [x] Implement switch-case statement
- [x] Handle invalid choices

**Key Concepts to Learn:**
- switch-case statement
- Menu-driven programs

---

### Module 5: Loop Functionality
**Status: PENDING**
- [x] Implement while loop
- [x] Add continue/exit option
- [x] Use break statement
- [x] Program flow control

**Key Concepts to Learn:**
- while loop
- break and continue
- Loop control

---

### Module 6: Input Validation ⚠️ CRITICAL
**Status: COMPLETED** ✅
- [x] Understand scanf buffer issues
- [x] Clear input buffer with while(getchar() != '\n')
- [x] Check scanf return value
- [x] Advanced: Use fgets() + sscanf()

**Key Concepts Learned:**
- Input buffer management
- scanf pitfalls and return value checking
- Robust input handling with fgets() + sscanf()

---

### Module 7: Pointer Basics 🎯
**Status: COMPLETED** ✅
- [x] Understand pointer concept
- [x] Implement swap() function
- [x] Use address-of operator (&)
- [x] Use dereference operator (*)
- [x] Pass by reference vs pass by value

**Key Concepts Learned:**
- Pointers (C language soul #1)
- Memory addresses
- Function parameter passing
- Difference between pass by value and pass by reference

---

### Module 8: Multi-file Compilation 🎯
**Status: COMPLETED** ✅
- [x] Create calc.h header file
- [x] Create calc.c implementation file
- [x] Use #ifndef header guards
- [x] Separate function declarations and definitions
- [x] Compile multiple files: `gcc main.c calc.c -o calculator`
- [x] Configure CMake for multi-file compilation

**Key Concepts Learned:**
- Header files (C language soul #2)
- Preprocessor directives (#ifndef, #define, #endif)
- Code modularization and project organization
- Function declaration vs definition
- Multi-file compilation with GCC and CMake

---

### Module 9: Scientific Calculator
**Status: COMPLETED** ✅
- [x] Include math.h library
- [x] Implement power function (pow)
- [x] Implement square root (sqrt)
- [x] Implement modulo (fmod)
- [x] Compile with -lm flag on Linux/macOS
- [x] Update menu to support new operations
- [x] Handle input validation for scientific operations

**Key Concepts Learned:**
- Math library functions (pow, sqrt, fmod)
- Library linking (CMake configuration)
- Conditional input handling (square root needs only one number)
- Error handling for scientific operations (negative square root, modulo by zero)

---

### Module 10: History with Struct 🎯
**Status: COMPLETED** ✅
- [x] Define struct Record
- [x] Use typedef for simplification
- [x] Create struct array
- [x] Store calculation history

**Key Concepts Learned:**
- Structures (C language soul #3)
- typedef keyword
- Struct arrays
- String operations with strcpy()

---

### Module 11: History Management
**Status: COMPLETED** ✅
- [x] Implement view history function
- [x] Implement clear history function
- [x] Traverse struct array
- [x] Access struct members
- [x] Conditional formatting for different operators

**Key Concepts Learned:**
- Struct array operations
- Member access (. operator)
- String comparison with strcmp()
- Conditional output formatting

---

### Module 12: Safe String Handling 🔒
**Status: PENDING**
- [ ] Replace sprintf with snprintf
- [ ] Understand buffer overflow
- [ ] Implement boundary checking

**Key Concepts to Learn:**
- Memory safety
- Buffer overflow prevention
- Secure coding practices

---

### Module 13: File Persistence
**Status: PENDING**
- [ ] Use fopen() to open files
- [ ] Use fprintf() to write data
- [ ] Use fscanf() to read data
- [ ] Use fclose() to close files
- [ ] Save history on exit
- [ ] Load history on startup

**Key Concepts to Learn:**
- File I/O operations
- Data persistence

---

### Module 14: Command Line Arguments (Optional Challenge) 🚀
**Status: PENDING**
- [ ] Modify main signature: int main(int argc, char *argv[])
- [ ] Parse command line arguments
- [ ] Convert strings to numbers (atof)
- [ ] Support: ./calculator 10 + 20

**Key Concepts to Learn:**
- argc and argv
- Command line parsing

---

### Module 15: Expression Parser (Boss Challenge) 👹
**Status: PENDING**
- [ ] Implement stack data structure
- [ ] Understand operator precedence
- [ ] Convert infix to postfix (RPN)
- [ ] Evaluate postfix expression
- [ ] Support: 3 * (4 + 5) - 6

**Key Concepts to Learn:**
- Stack implementation
- Reverse Polish Notation
- Data structures and algorithms
