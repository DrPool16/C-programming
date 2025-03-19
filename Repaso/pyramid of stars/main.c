#include <stdio.h>
#include <stdlib.h>

int main()
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
    return 0;
}
