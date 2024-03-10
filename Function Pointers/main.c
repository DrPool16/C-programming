#include <stdio.h>
#include <stdlib.h>
/*
Function Pointers in C

    Function Pointer

        Function pointer are like normal pointers but they have the capability to point
        to a function.

                    EXAMPLE
            How to declare a pointer to an array?

        int main(){
            int *ptr[10]; // <---- WRONG!  // We can say: ptr is an array or ptr is an array of 10 pointers pointing to intigers.
            return 0;
        }

        Always remember the precedence of operators.
        Precedence of [] is higher than *

        int main(){
            int (*ptr)[10]; // We can say: ptr in a pointer which is pointing to 10 integers or ptr is a pointer which is pointing to an array of 10 integers.
            return 0;
        }

                How to declare a pointer to a function?

        int main(){
            int (*ptr)(int, int); // ptr is a pointer which is pointing to a function containing two integers arguments and it returns an integer.
            return 0;
        }

            Assigning the address of the s function to a function pointer

        int main(){
            int (*ptr)(int, int) = &add; //
            return 0;
        }
        int main(){
            int (*ptr)(int, int);
            ptr = &add;
            return 0;
        }

    Application of Function Pointer

        There are some situations in which user has to decide which
        function has to be called at a particular point in time.

        Let's sat we want to design a calculator which has the capability to perform
        addition, subtraction, multiplication and division.

        Here, the user will decide which operations he/she wants to perform.
        Suppose, we have decided to create separate functions for these operations.

        Now we want user to decide which function has to be called at runtime.


*/

/*Function Pointer*/
int add(int a, int b){
    return a+b;
}

/*Application Function Pointer*/
#define OPS 4
float sum(float a, float b) {return (a+b);}
float sub(float a, float b) {return (a-b);}
float mul(float a, float b) {return (a*b);}
float divd(float a, float b) {return (a/b);}


int main()
{
    /*Using the function pointer*/
    int result;
    int(*ptr)(int, int) = &add;
    result = (*ptr)(10,20);
    /* Or:
    int(*ptr)(int, int) = &add;
    result = ptr(10,20);
    */
    printf("%d\n",result);


    /*Application Function Pointer*/
    float (*ptrfunc[OPS])(float,float) = {sum, sub, mul, divd};
    int choice;
    float a, b;
    printf("Enter your choice: 0 for Sum, 1 for Sub, 2 for Multi, 3 for Div: \n");
    scanf("%d",&choice);
    printf("Enter two numbers:\n");
    scanf("%f %f", &a, &b);
    printf("%f", ptrfunc[choice](a,b));

    return 0;
}
