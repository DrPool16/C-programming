#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*What is the output of the following C program fragment? Assume size of integer is 4 bytes*/
    int i = 5;
    int var = sizeof(i++);
    printf("%d %d\n", i, var);


    /*What is the output of the following C program fragment?*/
    int a = 1;                  //1
    int b = 1;                  //1
    int c = ++a || b++;         //1  in this case b will never get implemented, T(a=2) || anything = T(c=1)
    int d = b-- && --a;         //0  T(b=1) && T(a=1) = T(d=1), after that b is implemented so: (b=0)
    printf("%d %d %d %d\n",d,c,b,a); //1 1 0 1

    return 0;
}
/*
Q1: Sizeof operator returns size in?
- Bytes
Q2: Which of the following is the correct inline declaration of variables?
- int a,b,c;
Q3: What does printf function returns?
- Number of characters printed on the screen
Q4: ASCII decimal range of characters from A...Z is?
- 65 to 90
Q5:Size of integer?
- Depends from machine to machine
Q6: Consider the following variable declarations and definitions in C.
    i) int 39 = 1;
    ii) int var_39 = 1;
    iii) int_ = 3;

    Which of the following is correct?
    - Both ii) and iii) are valid.
Q7: Consider the following lines.
    int var;
    extern int var;

    Which of the following is correct?
    - Both statements 1 declare and define a variable and statement 2 just declare a variable.

Q8: Predict the output
    #include<studio.h>
    int var = 5;
    int main()
    {
        int var = var;
    }
    - Garbage value
Q9: Predict the output
    #include<studio.h>
    int main(){
    {
        int var = 10;
    }
        {printf("%d", var);}
    }
    - Compiler error

Q10: Predict the output
    #include<studio.h>
    int main()
    {
       unsigned int var = var;
       printf("%d",~var);
    }
    -   -11
*/
