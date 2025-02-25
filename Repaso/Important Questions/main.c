#include <stdio.h>
#include <stdlib.h>
int QuestionSet1()
{
    return printf("%d", printf("%s", "Hello World!"));   //Hello World!12
    /*
        - %s is used to print "string of characters".
        - Printf not only prints the content on the screen. It also
          returns the number of characters that it successfully prints
          on the screen.

    unsigned i = 1;
    int j = -4;
    return printf("%u", i+j); // integer value depends from machine to machine
    */
}
#define STRING "%s\n"
#define NESO "Welcome to Neso Academy"
int QuestionSet2()
{
    return printf(STRING,NESO); // Welcome to Neso Academy ---> Whatever is inside these double quotes is only printed
}
static int i;       // i = 0
static int i = 27 ; // i = 27
static int i;       // i = 27
int QuestionSet3()
{
    static int i; // i = 0   ,
    // i = 45;    // i = 45
    return printf("%d", i); // i = 0
}
int OperatorProblems1()
{
    int i = 5;
    int var = sizeof(i++);         // If the type of operand is a variable length array type, then the operand is evaluated; o
    return printf("%d %d", i, var);
}
int OperatorProblems2()
{
    int a = 1;
    int b = 0;
    int c = ++a || b--;
    int d = b-- && --a;

    printf("%d%d%d%d",d,c,a,b);

}
int OperatorProblems3()
{
    int i = 1024;
    for ( ; i ; i>>=1 )
        printf("Hello World!"); // 11 time is printed
}

int OperatorProblems4()         // One
{
    int i = 0;
    for (printf("One\n"); i<3 && printf("");i++)    //  So here, in context of for-loop it firstly evaluates printf("one\n") and then ignore it
    {
        printf("Hi!\n");
    }
}
int OperatorProblems5()
{
     unsigned int i = 500;
     while(i++ != 0);                          // When i reaches 4295967295, then because of i++, it comes back again to 0
                                               // As 0 not equal to 0 is false therefore we come outside of the while loop
                                               /* After we come out of the loop, i will contain 1 because of post increment operator.
                                                  Therefore, 1 will be printed on the screen */
     printf("%d", i); // i = 1
}

int OperatorProblems6()
{

}
int main()
{
    int q;
    printf("Which question do you want to print: ");
    scanf("%d",&q);

    switch(q){
        case 1:
            QuestionSet1();
            break;
        case 2:
            QuestionSet2();
            break;
        case 3:
            QuestionSet3();
            break;
        case 4:
            OperatorProblems1();
            break;
        case 5:
            OperatorProblems2();
            break;
        case 6:
            OperatorProblems3();
            break;
        case 7:
            OperatorProblems4();
            break;
        case 8:
            OperatorProblems5();
            break;
        case 9:
            OperatorProblems6();
            break;
    }
    return 0;
}


