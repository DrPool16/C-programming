#include <stdio.h>
#include <stdlib.h>

#define greater(x,y) if(x > y) \
                        printf("%d is greater than %d\n",x,y);\
                     else \
                        printf("%d is lesser than %d\n",x,y);

#define add(x,y) x+y
int main()
{
    greater(6,5);
    printf("result of expression a*b+c is: %d",5*add(4,3)); // result is 5*4+3 = 23, first expansion then evaluation

    return 0;
}
