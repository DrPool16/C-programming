#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*

    *sqrt means square root
    *available in math.h library
    Syntax: double sqrt(double x)
    - sqrt(2) = 1.414

    *ceil function returns a smallest integer greater than or equal to x
    *available in math.h library
    Syntax: double ceil(double x)
    - ceil(1.414 = 2)


*/

int main()
{
    int chose;
    printf("Select what Special program do you want to solve:\n");
    scanf("%d",&chose);

    int rows;
    int pal;
    int arms;
    int stnum;
    int prime=0;
    int num1, num2;
    int bas, expo;
    switch(chose){
    case 1:
        /*Pyramid of Stars
                *
               ***
              *****
             *******
            *********
                           */
        printf("How many rows do you want in your pyramid?\n");
        scanf("%d", &rows);

        for(int i=1;i<=rows;i++){
            for(int j=rows-i;j>0;j--) printf(" ");
            for(int k=0;k<(i*2-1);k++) printf("*");
            printf("\n"," ");
        }
        break;
    case 2:
        /*Palindrome*/
        printf("Write a number:\n");
        scanf("%d", &pal);
        int aux_pal = pal;
        int remainder = 0;
        while(aux_pal >= 1)
        {
            remainder = remainder*10 + aux_pal%10 ;
            aux_pal = aux_pal/10;
        }
        if(pal == remainder){
            printf("The number %d is a palindrome\n",pal);
        }else{
            printf("The number %d is not a palindrome\n",pal);
        }
        break;
    case 3:
        /*Armstrong Number*/
        printf("Write a number:\n");
        scanf("%d", &arms);

        int aux_arms = arms;
        int order = 0;
        while(aux_arms != 0){
            aux_arms = aux_arms/10;
            order++;
        }
        int aux_arms2 = arms;
        int result = 0;
        int digit = 0;
        int sum = 0;
        for(int p=0; p<order;p++){
            digit = aux_arms2%10;
            for(int l=1;l<order;l++){
                if(l==1){
                    result=digit*digit;
                    }else{
                        result*= digit;
                        }
            }
            sum+=result;
            aux_arms2 = aux_arms2/10;
        }
        if(arms == sum){
            printf("The number %d is an Armstrong number\n",arms);
        }else{
            printf("The number %d is not an Armstrong number\n",arms);
        }
        break;

    case 4:
        /*Strong Number*/
        /*145 = 1! + 4! + 5! = 1 + 24 + 120 = 145
           3! = n*(n-1)*(n-2) */
        printf("Write a number - Strong number:\n");
        scanf("%d", &stnum);
        int aux_str, last_n = 0, total=1, sumatory=0;

        aux_str = stnum;
        while(aux_str != 0){
            last_n = aux_str%10;
            int cont = 0;
            while(cont < last_n){
                total *= (last_n-cont);
                cont++;
            }
            sumatory += total;
            aux_str /= 10;
            total = 1;

        }
        if(stnum == sumatory){
            printf("The number %d is a Strong number\n",stnum);
        }else{
            printf("The number %d is not a Strong number\n",stnum);
        }
        break;

    case 5:
        /*Prime number
        Prime numbers are numbers greater than 1 that only have two factors,
        1 and the number itself. This means that a prime number is only divisible
        by 1 and itself. If you divide a prime number by a number other than
        1 and itself, you will get a non-zero remainder. Ex:  13--> 1 and 13 only, but 6 has 1, 2, 3 and 6 divisors */
        printf("Write a number - Prime Number:\n");
        scanf("%d", &prime);

        int conta = 1,remain = 0, co = 0;
        while(conta <= prime){
            remain = prime%conta;
            if (remain == 0){
                co++;
            }
            conta++;
        }
        if(co == 2){
            printf("The number %d is a Prime number\n",prime);
        }else{
            printf("The number %d is not a Prime number\n",prime);
        }
        break;

    case 6:
        /*Addition without using '+' operator*/
        printf("Write two number - Add two numbers without using '+' operator:\n");
        scanf("%d %d", &num1, &num2);

        int suma = num1;
        for (int m=0; m<num2; m++) suma++;
        for (int n=num2; n<0;n++) suma--;
        printf("The sum of %d and %d is %d", num1, num2, suma);
        break;

    case 7:
        /*Addition without using The Plus operator*/
        printf("Write two number - Add two numbers without using The Plus operator:\n");
        scanf("%d %d", &num1, &num2);

        int carry, add;
        while(num2!=0){
            add = num1^num2; //XOR
            carry = (num1&num2)<<1; // AND shit right
            num1 = add;
            num2 = carry;
        }
        printf("The sum the two numbers is: %d", add);
        break;

    case 8:
        /*Fibonacci series
        F(n)
        F(0) = 0
        F(1) = 1
        F(2) = F(n-2)+F(n-1) = 0+1 = 1
        F(3) = F(n-2)+F(n-1) = 1+1 = 2
        ....

        */
        printf("Write n series you want to print - Fibonacci squence:\n");
        scanf("%d", &num1);

        int fbo=0,fbo_1=0,fbo_2=1;

        for(int z=1;z<=num1;z++){
            printf("%d ",fbo);
            fbo = fbo_2+fbo_1;
            fbo_2 = fbo_1;
            fbo_1 = fbo;
        }

        break;

    case 9:
        /*Floyd's Triangle
        1
        2 3
        4 5 6
        7 8 9 10
        */
        printf("Enter the number of rows: ");
        scanf("%d", &num1);
        int cont = 0;
        for(int i=0;i<=num1;i++){
            for(int j=0;j<i;j++){
                cont++;
                printf("%d ", cont);
            }
            printf("\n");
        }
        break;

    case 10:
        /*Binary to decimal conversion
        1001 = 9
        (2^3)x1 +(2^2)x0+(2^1)x0+(2^0)x1 = 9
        */
        printf("Enter binary number without spaces: ");
        scanf("%d", &num1);

        int aux = num1, reslt=0, base=0, rem;
        while(aux!=0){
            rem = aux%10;
            //reslt += pow(2,base)*rem; also work
            reslt += (rem<<base);
            aux /=10;
            base++;
        }
        printf("The decimal number of %d is %d", num1,reslt);
        break;

    case 11:
        /*Calculating Power of an Integer*/
        printf("Enter the base number: ");
        scanf("%d", &bas);

        printf("Enter the power raised: ");
        scanf("%d",&expo);

        int power=1;
        if(expo>=0){
            for(int i=0;i<expo;i++) power*=bas;
        }else{
            for(int j=0;j<((-1)*expo);j++) power/=bas;
        }
        printf("%d",power);
        break;

    case 12:
        /*Check Leap Year*/
        printf("Enter a year number to evaluate: ");
        scanf("%d", &num1);
        if((num1%400 == 0) || (num1%400 != 0 && num1%100 != 0 && num1%4 == 0)){
            printf("The %d is a leap year\n",num1);
        }else{
            printf("The %d is not a leap year\n",num1);
        }
        break;


    case 13:
        /*Check if the number is perfect number
        Perfect number is positive integer that is equal to the sum of all its proper
        positive divisors excluding the number itself
        */
        printf("Enter a number: ");
        scanf("%d", &num1);

        int sumn=0;

        for(int i=1;i<num1;i++){
            if(num1%i==0){
                sumn+=i;
            }
        }
        if(sumn == num1){
            printf("The number %d is a Perfect number\n",num1);
        }else{
            printf("The number %d is not a Perfect number\n",num1);
        }

        break;

    }// Switch

    return 0;
}
/*



*/


