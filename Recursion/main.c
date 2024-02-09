#include <stdio.h>
#include <stdlib.h>
/*

    *Recursion is a process in which a function calls itself directly or indirectly.

    Idea:
    1. Divide the problem into smaller sub-problems.
    2. Specify the base condition to stop the recursion. - Base condition is the one which does not require to call
                                                           the same function again ans it helps in stopping the recursion.


    Type of recursion:
    1. Direct recursion
    * A function is called direct recursive if tit calls the same function again.
       fun(){
        //code
        fun();
        //code
       }
    2. Indirect recursion
    * A function is called indirect recursive if it calls another function and then fun2 calls fun directly or indirectly.
        fun(){
        //code
        fun2();
        //code
       }
       fun2(){
        //code
        fun();
        //code
       }

       Write A Program = WAP

    3. Tail recursion
    * A recursive function is said to be tail recursive if the recursive call is the last thing done by the function.
      There is no need to keep record of the previous state.

    4. Non-tail recursion
    * A recursion function is said to be non-tail recursion if the recursive call is not the las thing done by the function.
      After returning back, there is some something left to evaluate.

    Advantage and Disadvantage of Recursion
    - Iterative?
    - Recursion?
    Advantage
    * Every recursive program can be modeled into an iterative program but recursive programs are more elegant
      and requires relatively less lines of code.
    Disadvantage
    * Recursive programs require more space than iterative programs.

*/
/*Factorial of a number*/
int fact(int n){
    if(n==1)
        return 1;
    else
        return n*fact(n-1);
}

void odd();
void even();
int m=1;
void fun(int);
void fun2(int);
int fun3(int);
void count(int);
int main()
{
    int n;
    printf("Enter the number: ");
    scanf("%d",&n);
    printf("Factorial of the number %d is %d\n", n, fact(n));

    odd(); //Indirect
    printf("\n");
    fun(3); //Tail -->  3 2 1
    printf("\n");
    fun2(3); //Non-Tail -->  1 2 3
    printf("\n");
    printf("%d\n", fun3(8)); // Non-Tail
    count(3);
}
/*Indirect Recursion*/
void odd(){
    if(m<=10){
        printf("%d", m+1);
        m++;
        even();
    }
    return;
}

void even(){
    if(m<=10){
        printf("%d",m-1);
        m++;
        odd();
    }
    return;
}

/*Tail Recursion*/
void fun(int n){
    if(n==0)
        return;
    else
        printf("%d", n);
    return fun(n-1);
}  // 3 2 1

/*Non-Tail Recursion*/
void fun2(int n){
    if(n==0)
        return;
    fun2(n-1);
    printf("%d", n);
}  // 1 2 3

int fun3(int n){
    if(n==1)
        return 0;
    else
        return 1+fun3(n/2);
}
void count(int n){
    static int d=1;
    printf("%d, n);
    printf("%d",d);
    d++;
    if(n>1) count(n-1);
    printf("%d",d);
}

