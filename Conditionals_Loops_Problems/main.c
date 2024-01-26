#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*How many times will "Hello, world" be printed in the below program?

        1024 = 100 0000 0000    --> i>>=1
        512 =  010 0000 0000    --> i>>=1
        256 =  001 0000 0000    --> i>>=1
        .
        .
        1 =    000 0000 0001    --> i>>=1
        0 =    000 0000 0000    <-- Come out the loop

        - 11 times it is printed.

      *What is the output of the following C program fragment?
       Assuming size of unsigned int is 4 bytes.
                                        Range of unsigned int(4 bytes) 0 to 4294967295
            unsigned int j = 500;       When j reaches 4294967295, then because of j++, it comes back again to 0
            while(j++ != 0);            As 0 no equal to 0 is false therefore we come outside of the while loop
            printf("%d", j);            After we come out of the loop, j will conatin 1 because of post increment operator. Therefore, 1 will be printed on the screen.

    */


    int i = 1024;
    for(;i; i >>= 1)
        printf("Hello, world");


    return 0;
}
