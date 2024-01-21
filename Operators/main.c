#include <stdio.h>
#include <stdlib.h>

/*
Type of operators in C
Arithmetic operators
Increment/Decrement operators
Relational operators
Logical operators
Bitwise operators
Assignment operators
*/

/*
ARITHMETIC OPERATORS

    +   ,      -     ,        *      ,     /   ,    %
addition, subtraction, multiplication, division, modulus

All are binary operators -> means two operands are required to perform operation

------------------------------------------------------------------------------------------

INCREMENT AND DECREMENT

*Both are unary operators.
    - because they are applied on single operand
    Pre-increment/decrement operator      Post-increment/decrement operator
              ++a/--a;                               a++/a--;


    Lexemes
    a+++b ---> |a| |++| |+| |b|\


RELATIONAL OPERATORS

   ==   ,      !=     ,          <=          ,           >=            ,    <     ,      >
equal to, not equal to, less than or equal to, greater than or equal to, less than, greater than


* All relational operators will return either True or False

LOGICAL OPERATORS

 &&  , || ,  !
 AND , OR , NOT

In this section applies an important concept known as SHORT CIRCUIT

* Short circuit in case of &&: Simply means if there is a condition anywhere in the expression that returns False,
  then the rest of the conditions after that will not be evaluated.
* Short circuit in case of ||: Simply means if there is a condition anywhere in the expression that returns True,
  then the rest of the conditions after that will not be evaluated.

BITWISE OPERATOR


*/

int main()
{
    /*ARITHMETIC OPERATORS*/
    int a,b;
    printf("Enter the first number\n");
    scanf("%d",&a);
    printf("Enter the second number\n");
    scanf("%d",&b);
    printf("a / b = %d\n",a/b);
    printf("a %% b = %d\n", a%b);

    /*INCREMENT AND DECREMENT*/

    int c = 4, d = 3;
    int e = 4, f = 3;
    //int p = 4, o = 3;
    printf("%d\n", c+++d); //      7
    printf("%d\n", e+ ++f);//      8
    //print ("%d\n", p+++++o);// error


    /*RELATINAL OPERATORS*/
    /*LOGICAL OPERATORS*/
    int g1 = 5, h1 = 3;
    int incr_1;
    incr_1 = (g1 > h1) && (h1++);
    printf("%d\n",incr_1);
    printf("%d\n", h1);

    int g2 = 5, h2 = 3;
    int incr_2;
    incr_2 = (g2 < h2) && (h2++);
    printf("%d\n",incr_2);
    printf("%d\n", h2);


    return 0;
}
