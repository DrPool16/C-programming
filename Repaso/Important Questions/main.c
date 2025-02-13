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
int QuestionSet4()
{
    return printf("Question 4");
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
            QuestionSet4();
            break;
    }
    return 0;
}


