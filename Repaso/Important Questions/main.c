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

int PyramidOfStars()
{
    int r = 0;
    printf("Numbers of rows: \n");
    scanf("%d",&r);

    for(int i=0; i<r; i++){
        for (int k=0; k<(r-i-1); k++){
            printf(" ");
        }
        for (int j=0; j<(2*i+1); j++){
            printf("*");
        }
        printf("\n");
    }
}
char PalindromeNumber()
{
    char num[100];
    printf("Write a number: ");
    scanf("%s",num);

    char conv[100];
    for (int i=0; i<strlen(num);i++){
        conv[i] = num[strlen(num)-i-1];
    }
    conv[strlen(num)] = '\0';

    if (strcmp(conv,num) == 0){
        printf("Palindrome, Yes!");
    }else{
        printf("It is not %s %s", conv, num);
    }
}

int ArmstrongNumber()
{
    int nn, count=0, rem=0, q1=0, sum=0, mul=0;
    printf("Number to evaluated: ");
    scanf("%d",&nn);

    int q0 = nn;

    while(q0!=0){
        q0=q0/10;
        count++;
    }
    q1= nn;
    for(int i=0; i<count; i++){
        rem=q1%10;
        mul = 1;
        for (int j=0;j<count;j++){
            mul = rem*mul;
        }
        sum += mul;
        q1 = q1/10;
    }

    if (nn == sum){
        printf("Is an Armstrong number!");
    }else{
        printf("Is not Armstrong number");
    }
}
int PrimeNumber()
{
    int prim=0, multi=0, conta1=1, conta2=1, conta3=0;
    printf("Digit the number to analyze: ");
    scanf("%d",&prim);

    while(conta1<=prim){
          conta2 = 1;
        while(conta2<=prim){
            multi=conta1*conta2;
            if (multi == prim){
                conta3++;
            }
            conta2++;
          }
          conta1++;
    }
    if (conta3 == 2){
        printf("Is a Prime number");
    }else{
        printf("Is not a Prime number");
    }
}

int HalfAdderLogic()
{
    int a,b, sum=0, carry=0;
    printf("Enter the two numbers: \n");
    scanf("%d",&a);
    scanf("%d",&b);

    while(b != 0){
        sum = a^b;
        carry = (a&b)<<1;
        a = sum;
        b = carry;
    }
    printf("The sum of two numbers is: %d", sum);

}

int FibonacciSeries()
{
    int n=0, fbn=0, carry=0, sum=0;
    printf("Iterations of series: ");
    scanf("%d",&n);

    carry=1;
    for(int i=1;i<=n;i++){
        printf("%d ",fbn);
        sum = fbn + carry;
        fbn = carry;
        carry = sum;
    }
}

int FloydTriangle()
{
    int n=0, count=0, count2=1, i;
    printf("Iterations of series: ");
    scanf("%d",&n);

    while(count2 <= n){
        i = 0;
        while(i < count2){
            printf("%d ", ++count);
            i++;
        }
        count2++;
        printf("\n");
    }
}

int BinaryToDecimal()
{
    int binary=0, decimal=0, weight=1, num,rem;
    printf("Enter the binary number: ");
    scanf("%d",&binary);

    num = binary;
    while(binary != 0){
        rem = binary%10; //Remainder by 10 always will be the last number, MOD(%) operator is used to obtain the remainder
        decimal = decimal + rem*weight;
        binary = binary/10;
        weight = weight*2;
    }
    printf("Decimal equivalent of the binary number %d is: %d", num,decimal);
}

int PowerOfAnIntiger()
{
    int i=0,a,b,carry, num;
    double a2,carry2;
    printf("Enter the base number: ");
    scanf("%d",&a);
    printf("Enter the exponent number: ");
    scanf("%d",&b);

    num = a;
    if (b >= 0){
        carry = a;
        while(i <(b-1)){
            a = a*carry;
            i++;
        }
        printf("Power of %d and %d is: %d",num, b, a);
    }else{
        b = b*(-1);
        a2 = a;
        carry2 = 1.0/a;
        while(i <(b-1)){
            a2 = (1.0/a2)*(1.0/carry2);
            i++;
        }
        printf("Power of %d and %d is: %.5f",num, b, a2);
    }

}
int LeapYear()
{
    /*
    Leap year is a year having 366 days. The extra day is the 29th February, Leap year arrives after every four years.
    Note: Every year that is exactly divisible by 4 is a leap year, except the centurial year that is exactly divisible by 100. But
          these centurial years are leap years if they are exactly divisible by 400
    */
    int year;
    printf("Enter the year: ");
    scanf("%d", &year);

    if (year%4 == 0 && year%100 != 0){
        printf("It is a leap year");
    }else{
        if(year%400 == 0 && year%100 == 0){
            printf("It is a leap year");
        }else{
            printf("It is not leap year");
        }
    }
}
int PerfectNumber()
{
    int num, sum=0;
    printf("Enter the number: ");
    scanf("%d", &num);

    for (int i=1; i<=(num/2);i++){
        if(num%i==0){
            sum+=i;
        }
    }
    if (sum == num){
        printf("It is a perfect number");
    }else{
        printf("It is not a perfect number");
    }


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
            PyramidOfStars();
            break;
        case 10:
            PalindromeNumber();
            break;
        case 11:
            ArmstrongNumber();
            break;
        case 12:
            PrimeNumber();
            break;
        case 13:
            //Write a program to add two numbers without using '+' operator
            HalfAdderLogic();
            break;
        case 14:
            FibonacciSeries();
            break;
        case 15:
            FloydTriangle();
            break;
        case 16:
            BinaryToDecimal();
            break;
        case 17:
            PowerOfAnIntiger();
            break;
        case 18:
            LeapYear();
            break;
        case 19:
            PerfectNumber();
            break;


    }
    return 0;
}


