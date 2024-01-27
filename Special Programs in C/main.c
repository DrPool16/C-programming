#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rows;
    printf("How many rows do you want in your pyramid?\n");
    scanf("%d", &rows);

    for(int i=1;i<=rows;i++){
        for(int j=rows-i;j>0;j--) printf(" ");
        for(int k=0;k<(i*2-1);k++) printf("*");
        printf("\n"," ");
    }
    return 0;
}
/*

    *
   ***
  *****
 *******
*********

*/


