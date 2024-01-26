#include <stdio.h>
#include <stdlib.h>

/*
IF - ELSE, NESTED IF and ELSE IF

*Is it necessary to put the else part?
- The answer to this question is NO and YES!, if we do not put else part there is not output.

SWITCH
* Switch is a great replacement to long else if constructs.
* You are not allowed to add duplicate cases.
* Only those the expressions are allowed in switch  which result in an integral constant value.
* Float is not allowed as a constant value in case label. Only integer constants/constant expressions are allowed in case label.
* Variables expressions are not allowed in case label. Although macros are allowed.
* Default can be placed anywhere inside switch. It will still get evaluated if no match is found.

FOR and WHILE LOOP

WHILE LOOP vs DO-WHILE
* When should i prefer do-while over while?
    - Write a program which allows user to enter an integer until he/she enters a value zero.

LOOP CONTROL STATEMENTS - BREAK AND CONTINUE
    Break: Used to terminated from the loop.
    Continue: Similar to break but instead of terminating from the loop, it forces to execute the iteration of the loop.
*/
#define y 2
#define z 23

int main()
{
    int x = 2;
    switch(x)
    {
        default: printf("Default case\n");
            break;
        case y:  printf("Number is 2\n");
            break;
        case z:  printf("Number is 23\n");
            break;
    }


    /*DO-WHILE*/
    int i = 0;
    do
    {
        printf("%d\n",i);
        i--;
    }while (i > 0);


    int n;
    do
    {
        printf("Enter an integer\n");
        scanf("%d", &n);
    }while(n != 0);
    printf("You are out of the loop\n");


    /*CONTINUE*/
    int j, m=2;
    for(j=1; j <= 20; j++){
        if (j == m){
            m = m+2;
            continue;
        }
        printf("%d ", j);
    }

    return 0;
}
