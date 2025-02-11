#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int main()
{
    int var1 = INT_MIN;
    int var2 = INT_MAX;
    unsigned int var3 = 0;
    unsigned int var4 = UINT_MAX;
    short int var6 = SHRT_MIN;
    short int var5 = SHRT_MAX;
    short unsigned int var7 = 0;
    short unsigned int var8 = USHRT_MAX;


    printf("RANGE OF SIGNED INTEGER IS FROM:  %d TO %d\n", var1,var2);
    printf("RANGE OF UNSIGNED INTEGER IS FROM: %u TO %u\n", var3,var4);
    printf("RANGE OF SHORT SIGNED INTEGER IS FROM:  %d TO %d\n", var5,var6);
    printf("RANGE OF SHORT UNSIGNED INTEGER IS FROM:  %u TO %u\n", var7,var8);

    /*

    %ld ---> long integer
    %lu ---> unsigned long integer
    %lld ---> long long integer
    %llu ---> unsigned long long intiger

    */

    return 0;
}
