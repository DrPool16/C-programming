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

    Counting Array Elements using sizeof() Operator

        * lenght_arr = sizeof(name_of_arr)/sizeof(name_of_arr[0]);

    Multidimensional Arrays

    * Multidimensional arrays can be defined as an array of arrays.
    * data_type name_of_array[size1][size2]...[sizeN];

    lenght = size of a[10][20] = 10 x 20 = 200
                               = 200 x 4 = 800 bytes

    Two-Dimensional
    *int arr [4]    [5];
            #rows #columns

        Method 1:
            int a[2][3] = {1,2,3,4,5,6}; // #row 1: 1,2,3; #row 2: 4,5,6;

        Method 2:
            int a[2][3] = {{1,2,3},{4,5,6}}; // #row 1: 1,2,3; #row 2: 4,5,6;

    Three-Dimensional
        int arr     [2]          [3]         [3];
              First 2D array  First row  Third column
        Method 1:
            int a[2][2][3] = {1,2,3,4,5,6,7,8,9,10,11,12}; // First 2D:{#row 1: 1,2,3; #row 2: 4,5,6;} , Second 2D:{#row 1: 7,8,9; #row 2: 10,11,12;};

        Method 2:
            int a[2][2][3] = {{ {1,2,3},{4,5,6} }, { {.,.,.},{.,.,.} }; // First 2D:{#row 1: 1,2,3; #row 2: 4,5,6;} , Second 2D:{#row 1: 7,8,9; #row 2: 10,11,12;};

    Constant Arrays in C
        Either one dimensional or multi-dimensional arrays can be made constant by starting the declaration with the keyword const.
            const int a[3] = {1,2,3};
            a[1] = 45; <--- !ERROR!

    Variable Length Arrays in C
        1. Variable length arrays cannot have static storage duration.
        2. Variable Length array does not have the initializer.

*/
#define LEN(x) sizeof(x)/sizeof(x[0])
#define NSP1 5
#define NSP2 3

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
        printf("Yes\n");
    else
        printf("No\n");

    /*2D dimensional arrays*/
    int a[2][3] = {{1,2,3},{4,5,6}}; // #row 1: 1,2,3; #row 2: 4,5,6;

    for(int i=0;i<2;i++){
        for(int j=0;j<3;j++){
            printf("%d ",a[i][j]);
        }
    }
    printf("\n");
    /*3D dimensional arrays*/
    int b[2][2][3] = { {{1,2,3},{4,5,6}},
                       {{7,8,9},{10,11,12}} };

    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<3;k++){
                printf("%d ",b[i][j][k]);
            }
        }
    }
    printf("\n");

    /*Sum of rows and sum of columns */

    int sum[2][5];
    int row_sum = 0, col_sum = 0;
    int vect[NSP1][NSP1] = { {8,3,9,0,10},
                             {3,5,17,1,1},
                             {2,8,6,23,1},
                             {15,7,3,2,9},
                             {6,14,2,6,0} };

    for(int k=0;k<2;k++){
        for(int i=0;i<NSP1;i++){
                row_sum = 0;
                col_sum = 0;
            for(int j=0;j<NSP1;j++){
                if(k == 0){
                    row_sum += vect[i][j];
                    sum[k][i] = row_sum;
                }else{
                    col_sum += vect[j][i];
                    sum[k][i] = col_sum;
                }
            }
        }
    }

    for(int i=0;i<2;i++){
        if (i == 0)
            printf("Row total: ");
        else
            printf("Column total: ");

        for(int j=0;j<5;j++){
            printf("%d ",sum[i][j]);
        }
        printf("\n");
    }

    /*Matrix Multiplication*/

    int suma = 0, c = 1, row1,row2, column1,column2;
    //int mtr2[NSP2][NSP2];

    printf("Enter the rows and columns of the matrix a: ");
    scanf("%d %d", &row1, &column1);
    int mtr1[2][row1][column1];

    for(int i=0;i<row1;i++){
        for(int j=0;j<column1;j++){
            printf("a[0][%d][%d]:",i,j);
            scanf("%d",&mtr1[0][i][j]);
        }
    }
    while(c == 1){

        printf("Enter the rows and columns of the matrix b: ");
        scanf("%d %d", &row2, &column2);

        if(column1 == row2){
            for(int i=0;i<row2;i++){
                for(int j=0;j<column2;j++){
                    printf("b[2][%d][%d]:",i,j);
                    scanf("%d",&mtr1[1][i][j]);
                }
            }
            c = 0;
        }else{
            printf("The number of columns of the matrix a is not equal to the number of rows of the matrix b \n");
        }
    }
    int mtr2[row1][column2];  // Size of the resultant matrix depends on #rows of 1st matrix and #columns of 2nd matrix.
    /*
    int mtr1[NSP2-1][NSP2][NSP2] = {{ {1,2,3},
                                      {1,2,1},
                                      {3,1,2} },
                                    { {1,2,3},
                                      {1,2,1},
                                      {3,1,2} }};
    */
    for(int i=0;i<row1;i++){
        for(int j=0;j<column1;j++){
            suma = 0;
            for(int k=0;k<row2;k++){
                suma += ((mtr1[0][i][k])*(mtr1[1][k][j]));
                mtr2[i][j] = suma;
            }
        }
    }
    printf("\n");

    // Print matrix resulting
    for(int i=0;i<row1;i++){
        for(int j=0;j<column2;j++){
            printf("%d ",mtr2[i][j]);
        }
        printf("\n");
    }




}
