#include <stdio.h>
#include <stdlib.h>

/*

    *Stack is a container (or memory segment) which holds some data.
    *Data is retrieved in Last In First Out (LIFO) fashion.
    *Two operators: push and pop

    Activation Record
    1. Locals of the callee
    2. Return address to the caller
    3. Parameters of the callee

*/


int a, b; // Global variables a and b

// Function to print the values of a and b
void print() {
    printf("%d %d", a, b);
}

// Function fun1
int fun1() {
    int a, c; // Local variables a and c
    a = 0;    // Initialize local variable a
    b = 1;    // Initialize global variable b
    c = 2;    // Initialize local variable c
    return c; // Return the value of c
}

// Function fun2
void fun2() {
    int b;    // Local variable b
    a = 3;    // Assign value to global variable a
    b = 4;    // Assign value to local variable b
    print();  // Call print function to print values of a and b
}

// Main function
int main() {
    a = fun1(); // Call fun1 and assign its return value to global variable a
    fun2();     // Call fun2
}
