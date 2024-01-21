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

BITWISE OR, AND & OR

As name suggests -it does bitwise manipulation


                & ,  | ,  ~  ,    <<     ,     >>    ,  ^
BITWISE --->   AND, OR , NOT , LEFT SHIFT, RIGHT SHIT, XOR
    Bitwise AND(&) operator
    * It takes two bits at a time and perform AND operator.
    * AND (&) is binary operator. It takes two numbers and perform bitwise AND.
    * Result of AND is 1 when both bits are 1.

    Bitwise OR(|) operator
    * It takes two bits at a time and perform OR operator.
    * OR (|) is binary operator. It takes two numbers and perform bitwise OR.
    * Result of OR is 0 when both bits are 0.

    Bitwise NOT (~) operator
    * NOT is an unary operator.
    * Its job is to complement each bit one by one.
    * Result of NOT is 0 when bit is 1 and it is 1 when bit is 0.

    Left Shift operator
    * When bits are shifted left then trailing positions are filled with zeros.
        var = 3, var << 1
        3 = 0000 0011 --> 0000 011 --> 0000 0110 = 6
    * Left shifting is equivalent to multiplication by 2^rightOperand
        var << 4
        Output: 48 <- [3 x 2^4]
    Right Shift operator
    * When bits are shifted right then leading positions are filled with zeros.
        var = 3, var >> 1
        3 = 0000 0011 --> 000 0001 --> 0000 0001 = 1
    * Left shifting is equivalent to division by 2^rightOperand
        var >> 4
        Output: 2 <- [3 / 2^4]
    Bitwise XOR operator
    * Bitwise XOR(^) is binary operator. It takes two numbers and perform bitwise XOR.
    * Result of XOR is 1 when two bits are different otherwise the result is 0.

*
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


    /*BITWISE OPERATOR VS LOGICAL OPERATOR*/

    char x = 1, y = 2;  //x = 1(0000 0001), y = 2(0000 0010)
    if(x&y)             //1&2 = 0(0000 0000)
        printf("result of x&y is 1\n");
    if(x&&y)             //1&&2 = TRUE && TRUE = TRUE = 1
        printf("Result of x&&y is 1\n");

    /*LEFT SHIFT*/
    char var1 = 3;   //Note: 3 in binary = 0000 0011
    printf("%d\n", var1<<1);
    /*RIGHT SHIFT*/
    char var2 = 3;
    printf("%d\n", var2>>1);


    /*XOR OPERATOR*/
    int a2 = 4, b2 = 3; // a2= 0100    b2= 0011
    a2 = a2 ^ b2;       // 0111
    b2 = a2 ^ b2;       // 0100
    a2 = a2 ^ b2;       // 0011
    printf("After XOR, a = %d and b = %d\n",a2,b2);
    return 0;
}
