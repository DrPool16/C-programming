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

    Bitwise OR, AND & OR
    * As name suggests -it does bitwise manipulation

                    & ,  | ,  ~  ,    <<     ,     >>    ,  ^
    Bitwise --->   AND, OR , NOT , LEFT SHIFT, RIGHT SHIT, XOR

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
        3 = 0000 0011 --> 0000 011_ --> 0000 0110 = 6
    * Left shifting is equivalent to multiplication by 2^rightOperand
        var << 4
        Output: 6  <- [3 x 2^1]
        Output: 48 <- [3 x 2^4]
    Right Shift operator
    * When bits are shifted right then leading positions are filled with zeros.
        var = 3, var >> 1
        3 = 0000 0011 --> _000 0001 --> 0000 0001 = 1
    * Left shifting is equivalent to division by 2^rightOperand
        var >> 4
        Output: 2 <- [3 / 2^4]
    Bitwise XOR operator
    * Bitwise XOR(^) is binary operator. It takes two numbers and perform bitwise XOR.
    * Result of XOR is 1 when two bits are different otherwise the result is 0.

ASSIGNMENT OPERATOR

* Values to a variable can be assigned using assignment operator.
* Requires two values L-value and R-value.
* This operator copies R-value to L-value.
             |var|            |=|              |5|    ;
            L-value,  Assignment operator,   R-value  ;

    +=      First addition than assignment.
    -+      First subtraction than assignment.
    *=      Fist multiplication than assignment.
    /=      First division than assignment.
    %=      First modulus than assignment.
    <<=     First bitwise left shift than assignment.
    >>=     First bitwise right shift than assignment.
    &=      First bitwise AND than assignment.
    |=      First bitwise OR than assignment.
    ^=      First bitwise XOR than assignment.

CONDITIONAL OPERATOR

* Look and feel:    ? :
* if(mark>33){result='x'}else{result='y'};  <--->  result = (mark>33) ? 'x' : 'y';

COMMA (,) OPERATOR

* Comma operator can be used as an "separator".  ---> int a = 3, b = 4, c = 6;
* Comma operator can be used as an "operator".   ---> int a = (3,4,8); printf("%d",a);  a = 8;
* Comma operator returns the rightmost operand in the expression and
  it simply evaluates the rest of the operands and finally reject them.

            int var5 = (printf("%s\n", "HELLO!"), 5);
            printf("%d\n",var5);    HELLO! 5   --HELLO!--> It will simply not rejected. First evaluated and them rejected. --5--> This value will be returned to var aftes evaluating the first operand.
            printf("%d\n",var5);    5

* Comma operator is having LEAST PRECEDENCE among all the operators available in C language.

    ex1:
            int a;                              int a;
            a = 3,4,8;          ====            (a = 3),4,8;
            printf("%d",a);                     printf("%d",a);
                                a = 3;
    ex2:
            int a;
            a = (3,4,8);          ====          int a = (3,4,8);
            printf("%d",a);                     printf("%d",a);
                                a = 8;

    Bracket has the highest precedence than any other operator


PRECEDENCE AND ASSOCIATIVITY OF OPERATORS

* Associativity can be either: 1.Left to right OR 2. Right to left.

Talking about categories, Unary: ! ~ ++ -- + - * & (type) sizeof; Conditional: ? : ; Assignment = += -= *= /= %= &= ^= |= <<= >>= ; the Associativity is Right to left

* Associativity can only help if there are two or more operators of same precedence and not when there is just one operator.
* Operator with same precedence have the same associativity as well.
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


    /*ASSIGNMENT OPERATORS*/
    char a3 = 7; //a3= 0111 = 7 in binary , Note: 5 in binary is 0101
    a3 ^= 5;     //(a3^= 5) = 0010 = 2 in binary, Note: 3 in binary is 0011
    printf("%d\n", printf("%d", a3+=3)); // a3+=3 --> 0101 = 5 in binary, so, the result is 5 and printf("%d",1) -> 51,
                                         // the main printf() returns the length of 2nd print function's output.


    /*CONDITIONAL OPERATOR*/
    int var3 = 75;
    int var4 = 56;
    int num;
    num = sizeof(var3) ? (var4 > 23?((var3 == 75)? 'A' : 0) : 0) :0;
    printf("%d\n",num);

    /*COMMA OPERATOR*/
    int a4 = (3,4,8);
    printf("%d\n", a4);  // a4 = 8

    int var5 = (printf("%s\n", "HELLO!"), 5);
    printf("%d\n",var5); // HELLO! 5
    printf("%d\n",var5);   // 5

    int var6;
    int num1;
    num1 = (var6 = 15, var6+35);
    printf("%d\n", num1); // 50

    /*PRECEDENCE AND ASSOCIATIVITY OF OPERATORS*/
    int a5 = 10, b5 = 20, c5 = 30, d5 = 40;
    if(a5 <= b5 == d5 > 5)
    {
        printf("TRUE");
    }else
    {
        printf("FLASE");
    }


    return 0;
}
