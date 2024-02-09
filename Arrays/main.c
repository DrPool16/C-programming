#include <stdio.h>
#include <stdlib.h>

/*
ARRAY

    * An Array is a data structure containing a number of data values (all of which are of same type).

    Data structure: Is a format for organizing and storing data.
                    Also, each data structure is designed yo organize data to suit a specific purpose.

    int arr[value];  --> value*sizeof(int)
    The length of an array can be specified by any positive integer constant expression.

    Best practice
        * Specifying the length of an array using macro is considered to be an excellent practice.
        #define N 10
        int arr[N];

    arrayname[index]

    Method 1: arr[5] = {1,2,5,67,32};
    Method 2: arr[] = {1,2,5,67,32};
    Method 3: arr[2]; arr[0] = 1; arr[1]=2;
    Method 4: arr[5];
              for(i=0;i<5;i++){
                scanf("%d",&arr[i]);
              }
    Why not int arr[10] = {};
    This is illegal, you must have to specify at least 1 element. It cannot be completely empty,
    and it is also illegal to add more elements than the length of an array.

    int arr[10] = {1,0,0,0,0,2,3,0,0,0};
    int arr[10] = {[0]=1, [5]=2, [6]=3}; this way of initialization is called designated initialization.
                                         No need to bother about the order at all. int arr[10] = {[5]=2, [6]=3, [0]=1};

    What if i won't mention the length?
    * Designators could be any non-negative integer.
    * Compiler will deduce the length of the array from the largest designator in the list.
      int arr[] = {[5]=90, [1]=3, [0]=1, [49]=7}; The maximum length of this array would be 50.

    Finally, no one can stop you from doing this:
    int arr[] = {1,7,5,[5]=90, 6, [8]=1};
                    ===
    int arr[] = {1,7,5,0,0,90,6,0,1};

    But, if there is a clash, then designated initializer will win.
    int arr[] = {1,2,3,[2]=90,[6]=1};
                    ===
    int arr[] = {1,2,90,0,0,0,1};
*/
#define LEN(x) sizeof(x)/sizeof(x[0])
int main()
{
    /*Print Array's numbers in reverse order*/
    int arr1[] = {35,56,54,32,67,89,90,32,21};
    int len,count=0;
    len = LEN(arr1);
    for(int i=len-1;i>=0;i--) printf("%d ",arr1[i]);
    /*Check if some numbers are repeated in the array*/
    for(int j=0;j<len-1;j++){
        for(int z=0;z<len-1;z++){
            if((arr1[j]==arr1[z]) && (j!=z)) count++;
        }
    }
    if(count>0)
        printf("\nYes\n");
    else
        printf("\nNo\n");
    /*Check whether any of the digits in a number appears more than once*/
    int N;
    printf("Enter the number:");
    scanf("%d",&N);

    int seen[10] = {0};
    int rem;
    /*The program is filling the vectors with 1 on the position the number that is evaluated,
      if that position is equal to 1 means that the number evaluated is repeated*/
    while(N>0){
        rem = N%10;
        if(seen[rem]==1)
            break;
        seen[rem] = 1;
        N /= 10;
    }
    if(N>0)
        printf("Yes");
    else
        printf("No");


}
