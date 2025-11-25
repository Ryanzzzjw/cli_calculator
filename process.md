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
- [ ] Implement subtraction
- [ ] Implement multiplication
- [ ] Implement division
- [ ] Handle division by zero error
- [ ] Use if-else statements

**Key Concepts to Learn:**
- Conditional statements (if-else)
- Error handling basics
- Comparison operators

---

### Module 4: Operation Menu
**Status: PENDING**
- [ ] Display menu options
- [ ] Read user choice
- [ ] Implement switch-case statement
- [ ] Handle invalid choices

**Key Concepts to Learn:**
- switch-case statement
- Menu-driven programs

---

### Module 5: Loop Functionality
**Status: PENDING**
- [ ] Implement while loop
- [ ] Add continue/exit option
- [ ] Use break statement
- [ ] Program flow control

**Key Concepts to Learn:**
- while loop
- break and continue
- Loop control

---

### Module 6: Input Validation ⚠️ CRITICAL
**Status: PENDING**
- [ ] Understand scanf buffer issues
- [ ] Clear input buffer with while(getchar() != '\n')
- [ ] Check scanf return value
- [ ] Advanced: Use fgets() + sscanf()

**Key Concepts to Learn:**
- Input buffer management
- scanf pitfalls
- Robust input handling

---

### Module 7: Pointer Basics 🎯
**Status: PENDING**
- [ ] Understand pointer concept
- [ ] Implement swap() function
- [ ] Use address-of operator (&)
- [ ] Use dereference operator (*)
- [ ] Pass by reference vs pass by value

**Key Concepts to Learn:**
- Pointers (C language soul #1)
- Memory addresses
- Function parameter passing

---

### Module 8: Multi-file Compilation 🎯
**Status: PENDING**
- [ ] Create calc.h header file
- [ ] Create calc.c implementation file
- [ ] Use #ifndef header guards
- [ ] Separate function declarations and definitions
- [ ] Compile multiple files: `gcc main.c calc.c -o calculator`

**Key Concepts to Learn:**
- Header files (C language soul #2)
- Preprocessor directives
- Code modularization

---

### Module 9: Scientific Calculator
**Status: PENDING**
- [ ] Include math.h library
- [ ] Implement power function (pow)
- [ ] Implement square root (sqrt)
- [ ] Implement modulo (fmod)
- [ ] Compile with -lm flag on Linux/macOS

**Key Concepts to Learn:**
- Math library functions
- Library linking

---

### Module 10: History with Struct 🎯
**Status: PENDING**
- [ ] Define struct Record
- [ ] Use typedef for simplification
- [ ] Create struct array
- [ ] Store calculation history

**Key Concepts to Learn:**
- Structures (C language soul #3)
- typedef keyword
- Struct arrays

---

### Module 11: History Management
**Status: PENDING**
- [ ] Implement view history function
- [ ] Implement clear history function
- [ ] Traverse struct array
- [ ] Access struct members

**Key Concepts to Learn:**
- Struct array operations
- Member access (. operator)

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
