#include <stdio.h>
#include <stdlib.h>

/*
FUNCTION

    Function is basically a set of statements that takes inputs, perform
    some computation and produces output.


    *There are two important reasons of why we are using functions:
        1. Re-usability
        2. Abstraction

FUNCTION DECLARATION

    *Function declaration(also called function prototype) means
     declaring the properties of a function to the compiler.

    For ex:     int fun(int, char);

    Properties:
    1. Name function:           fun
    2. Return Type function:    int
    3.Number of parameters:     2
    4.Type of parameter 1:      int
    5.Type of parameter 2:      char

    * Is is not necessary to put the name of the parameters in function prototype.
    * Is important

FUNCTION DEFINITION
    * Consists of block of code which is capable of performing some specific task.
    * Parameter is a variable in the declaration and definition of the function. Also called: Formal parameter
    * Argument is the actual value of the parameter that gets passed to the function. Also called: Actual parameter



CALL BY VALUE & CALL BY REFERENCE

    * Actual parameters: The parameters passed to a function. add(m,n);
    * Formal parameters: The parameters received by a function. int add(int a, int b){}

    Call by Value
    *
STATIC FUNCTION
    * In C, functions are global by default.
    * This means if we want to access the function outside from
      the file where it is declared, we can access it easily.
    * Now if we want to restrict this access, the we make our
      function static by simply putting a keyword static in front of
      the function.

*/
int areOfRect(int length, int breadth){   // Function prototype

    int area;
    area = length *breadth;
    return area;

}
int add(int, int);    // Function prototype
int call_b_v(int,int); // Call by value
int call_b_r(int*,int*);  // Call by reference

/*Solved Question 3*/
int fun()
{
    static int num = 16;    // Static variable won't be destroyed
    return num--;
}

int main()
{
    int l=10, b=5;
    int area = areOfRect(l,b);
    printf("%d\n", area);

    l=100, b=5;
    area = areOfRect(l,b);
    printf("%d\n", area);

    int m=20, n=30, sum;
    sum = add(m,n); // Arguments
    printf("Sum is %d\n", sum);


    /*Call By Value*/
    int x_v=10, y_v=20;
    call_b_v(x_v,y_v);
    printf("x=%d, y=%d\n",x_v,y_v); // 10 20

    /*Call By Reference*/
    int x_r=10, y_r=20;
    call_b_r(&x_r,&y_r);
    printf("x=%d, y=%d\n",x_r,y_r); // 20 10


    /*Solved Question 3*/
    for ( fun() ; fun() ; fun() )
        printf("%d ",fun()); // 14 11 8 5 2

    return 0;

    /*for ( 16 ; 15 ; 13 )  --> (16;12;10) --> (16;9;7) --> (16;6;4) --> (16;3;1) --> (16;0;)
        printf("%d ", 14 ); -->    (11)    -->    (8)   -->    (5)   -->    (2)

    */
}


int add(int a, int b){    // Function definition - Parameters
    return(a+b);
}

/*CALL BY VALUE*/
int call_b_v(int x, int y){
    x = 20;
    y = 10;
}
/*CALL BY REFERENCE*/
int call_b_r(int *x, int *y){
    *x = 20;
    *y = 10;
}


