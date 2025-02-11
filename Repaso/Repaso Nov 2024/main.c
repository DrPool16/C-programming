#include <stdio.h>
#include <stdlib.h>

int main()
{
    int var[3][3];
    int cont = 0;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j< 3; j++){
            cont ++;
            var[i][j] = cont;
        }
    }
    for (int i = 0; i < 3; i++){
        for (int j = 0; j< 3; j++){
            printf("|%d|",var[i][j]);
        }
            printf("\n");
    }

    printf("%d",sizeof(int));

    return 0;

}
