#include <stdio.h>
#include <stdlib.h>


/* & is also called as address-of operator

    &var
    Address of var


*/

int main()
{
    int a,b;
    printf("Enter the first number\n");
    scanf("%d",&a);
    printf("Enter the second number\n");
    scanf("%d",&b);
    printf("%d + %d = %d",a,b,a+b);
    return 0;
}
