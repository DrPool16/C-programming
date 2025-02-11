#include <stdio.h>
#include <stdlib.h>

extern int a;
//sextern int count;

int main()
{
    int value;
    value = increment();
    value = increment();
    value = increment();
    //count = count + 3;     // NOT A GOOD PRACTICE
    //value = count;         // crtl + shift + c to comment a section

    printf("%d\n", a);
    printf("%d\n", value);
    return 0;
}
