#include <stdio.h>
#include <stdlib.h>


/*
IMPORTNAT POINTS

    * Pointer is a special variable that is capable of storing some address.
    * It points to a memory location where the first byte is stored.

    ---> * <--- STAR SYMBOL

    data_type *pointer_name

    int *ptr <----- Points to integer value
    char *ptr <----- Points to character value
    float *ptr <----- Points to float value

    * Simply declaring a pointer is not enough.
    * It is important to initialize pointer before use.
    * One way to initialize a pointer is to assign address of some variable.

        int x = 5;   x[5]1000
        int *ptr;    ptr[ ]2000
        ptr = &x;    ptr[1000]2000
              &--> address of operator

        is equivalent to

        int x=5, *ptr=&x;
                 * --> It says go to the address of object and take what is stored in the object.

    Value of Operator in Pointers
        * Value of operator/indirection operator/dereference operator is an operator that is used to access the value
          stored at the location pointed by the pointer.

        * Never apply the indirection operator to the uninitialized pointer.  int *ptr; printf("%d",*ptr); Output: Undefined Behavior
        * Assigning value to an uninitialized pointer is dangerous. int *ptr; *ptr=1; Output: Segmentation Fault(SIGSEGV). Try to read or write an illegal memory location.

    Pointer Assignment
        * Note: q = p is not same as *q = *p
                int i = 10, j = 20;     // i[10]1000        j[20]2000
                int *p, *q;             // p[  ]1001        q[  ]1002
                p = &i;                 // p[1000]1001
                q = &j;                 // q[2000]1002
               *q = *p;                 // q[2000]1002 --> j[10]2000 // We are trying to access the contain of the location which is the pointer by the pointer p.
                                                                        The value stored i


    Returning pointer
        * Word Of Caution
            - Never ever try to return the address of an automatic variable.

    Important Questions
    Q3: How to print the address of a variable?
    Sol: use %p as format specifier in printf function, in hexadecimal format

    What happens if we add some integer to the pointer?
        * p[ ]
            ---> a[ 1000 ][ 1004 ][ 1008 ][ 1012 ][ 1016 ][ 1020 ]
                     0       1       2       3       4       5

          What program i need to write to variable p point to first element  in the array
                                        p =&a[0];
          p = p +3; Means moving the pointer 3 positions in forward direction.

          Initially, if p points to a[i], then
          p = p + j; === &a[i + j];
          p = p + 3; === &a[0 + 3] = &a[3];

          We will assume that an integer will take four bytes of memory location:

          First integer will get stored from location 1000 to 1003
          p = &a[0]; === p = 1000;
          p = p + 1; === p = 1004 ---> p 1000 + 1 x 4(Bytes);

          Don't bother about the addresses unless explicitly asked.

    Pointer Arithmetic - Subtraction

          Initially, if p points to a[i], then
          &a[3];
          p = p - j; === &a[i - j];
          p = p - 3; === &a[3 - 3] = &a[0];

          Subtraction one pointer from another
            - The result is distance between pointers.

          p = &a[2]; q = &a[6]; p = 1008; q = 1024
          q - p = 4;
          p - q = -4;
          q - p = 1024 - 1008 = 16; This is not the correct result
          p = 1008; q = p + 4 === q = 1008 + 4x4; --> q - p = 4 === ((1024-1008)/4(Number of bytes in integer)) = 4

          Undefined Behaviors
            - Performing arithmetic on pointers which are not pointing to array element leads to undefined behavior.
            - If two pointers are pointing to different arrays then performing subtraction between them leads to undefined behavior.

    Increment & Decrement
        Post
        int *p = &a[0];
        *(p++);
        Pre
        *(++p);

    Comparing Pointers
        * Use relational operators(<,>,<=,>=) and equality operators (==, !=) to compare pointers.
        * Only possible when both pointers point to same array.
        * Output depends upon the relative positions of both the pointers.

    Using Array Name as a Pointer
        * Name of an array can be used as a pointer to the first element of an array.

        int a[5];
        *a =10;             // *a = 10; === *(1000) = 10;
        printf("%d",a[0]);  // 10
        *(a+1) = 20;        // *(a+1) = 20; === *(1000 + 1x4(bytes)); === *(1004) = 20;
        printf("%d",a[1]);  // 20

        *(a + i) = a[i];
        Be carefully
           a++; ERROR // We are trying to assign address 1004 to array name 'a';
                         Recall that name of the array indicates the base address of the array i.e 1000.
                         We cannot change this.

        There is no problem in the code below
            a+1;      // Here, we are not trying to assign some new address to 'a'.
                         We are simply accessing the address of the second element of the array.
                         But is not a good practice.
        Alternative
            int *p =a;
            *(++p);

        Conclusion is that we cannot assign a new address to the name of the array,
        but we can use a pointer which can be representative of the array, and then we can
        perform any arithmetic that we can perform.

    Using pointers with two dimensional arrays
        Difference between row major and column major order
        - Raw major order: Elements are stored row by row.
        - Column major order: Elements are stored column by column.
        Important Fact
        - C stores multidimensional arrays in row major order.

    Address Arithmetic of Multidimensional arrays
        1D:
            a [1][2][2][4]
            int a[4];
            - means array of 4 integers
            - pointer to first element of the array
            - a ==> 1000
            - a+1 ==> 1008
            - *a ==> returns pointer to the first element = a[0] = &a[0][0]
        2D:
            a[1][2] [3][4]
             row 1  row 2
            int a[2][2];
                Two 1D array || Each of which contains 2 elements
            - Pointer to the first 1D array.
            - 2D Array:
             --> a[   1  ][   2   ][   3  ][  4   ]
                  | 1000 ||  1004 || 1008 || 1012 |
                  [     1000      ][     1008     ]
            - a ==> 1000(pointer to 1st 1D array)
            - a + 1 ==> 1008(pointer to 2nd 1D array)
            - *a ==> *(pointer to 1st 1D array)
            - *a ==> pointer to the first element of first 1D array
            - *(a+1) ==> pointer to the first element of second 1D array => 1008
            - **(a+1) ==> **(pointer to the 2nd 1D array) => *(pointer to the 1st element of 2nd 1D array) => 3
            - *(a+1)+1 ==> pointer to the 1st element of 2nd 1D array + 1 => pointer to the second element of the second 1D array
            - *(*(a+1)+1) ==> *pointer to the 2nd element of 2nd 1D array => 4 => a[1][1]


            **a => *(*a) => *(*(a+0)) => *(&a[0][0]) => 1, star are cancel out => a[0][0] => 1
        3D:
            a[1][2] [3][4] [5][6] [7][8]
            |row 1  row 2| |row 1  row 2|
            |1st 2D array| |2nd 2D array|

            int a[2][2][2];
            - a pointer to the first 2D array
            - a[2]
                 --> two 2D arrays
            - a[2][2]
                    --> Each of which contains two 1D arrays
            - a[2][2][2]
                       --> Each of which contains two elements
            - 3D Array:
             --> a[   1  ][   2   ][   3  ][  4   ][   5  ][  6   ][   7  ][  8   ]
                  | 1000 ||  1004 || 1008 || 1012 || 1016 ||  1020 || 1024 || 1028 |
                  [     1000      ][     1008     ][     1016      ][     1024     ]
                  [              1000             ][              1016             ]

            - a = pointer to 1st 2D array = 1000
            - a+1 = pointer to 2nd 2D array = 1016
            - *(a+1) = pointer 1st 1D array of 2nd 2D array
            - *(*(a+1)) = pointer 1st element of 1st 1D array of 2nd 2D array, getting the address
            - **(*(a+1)) = 5 = a[1][0][0]
            If want to access 2nd element of the above array
            - a pointer to 1st 2D array = 1000
            - *a pointer to 1st 1D array of 1st 2D array = 1000
            - **a pointer to 1st 1D array of 1st 2D array = 1000
            - **a+1 pointer to 2nd element of 1st 1D array of 1st 2D array = 1004
            - *(**a+1) = 2nd element of 1st 1D array of 1st 2D array
            How to access the second las element of above array using pointer arithmetic?
            - a+1 = 1016
            - *(a+1)+1 = 1024
            - *(*(a+1)+1) = 1024
            - **(*(a+1)+1) = 1024

    Pointer pointing to an Entire Array

        int a[5] = {1,2,3,4,5};
        int *p = a;			<---- Pointer to the first element of array
        printf("%d",*p);    => 1

        if we replace *p to (*p)
        int (*p)[5] = &a;	<--- Pointer to the whole array of 5 elements
        printf("%p",p);     => 1000

        Example: 2D array
             --> b[   1  ][   2   ][   3  ][  4   ]
                  | 1000 ||  1004 || 1008 || 1012 |
                  [     1000      ][     1008     ]
        *b = pointer to 1st element of 1st 1D array
        &*b = b = pointer to 1st 1D array

        int (*p)[5] = &a;
        printf("%d",**p);  => 1

        - p => It is pointer to the whole dimension array => 1000
        - *p => Go inside, Moving inside, Get inside imaginary box => address of the 1st element of 1D array  => 1000
        - **p => 1



*/

/*Finding the largest & smallest elements in an Array*/
void minMax(int arr[], int len, int *min, int *max){
    *min = *max = arr[0];

    for(int i=1;i<len;i++){
        if(arr[i]< *min)
            *min = arr[i];
        if(arr[i]> *max)
            *max = arr[i];
    }
}

/*Returning pointer, Find the mid of the array*/
int *findMid(int b[], int n){
    return &b[n/2];   // We are returning the address of the contain of the mid element.
}

/*Passing Array as an Argument to a Function*/
int add(int b[], int len){       // We can also write int *b;
    int sum = 0, i;
    for(i=0;i<len;i++) sum += b[i];
    return sum;
}
/*Pointers (Program 6)*/
int f(int *a, int n){
    if(n <= 0) return 0;
    else if(*a % 2 == 0) return *a + f(a+1, n-1);
    else return *a - f(a+1, n-1);
}
#define N 5

int main()
{
    int i = 10; // i[10]1000
    int *p, *q; // p[ ]1001 q[ ]1002
    p = &i;     // p[1000]1001
    q = p;      // q[1000]1002 = p[1000]1001 // We are trying to assign the contain of p to q.
    printf("%d %d\n",*p,*q); // 10 10


    int a[] = {23,4,21,98,987,45,32,10,123,986,50,3,4,5};
    int min, max;
    int len = sizeof(a)/sizeof(a[0]);
    minMax(a,len,&min,&max);
    printf("Minimum value in the array is: %d and Maximum value is: %d\n", min,max);


    /*Returning pointer, Find the mid of the array*/
    int b[] = {1,2,3,4,5};
    int n = sizeof(b)/sizeof(b[0]);
    int *mid = findMid(a,n);
    printf("%d\n", *mid);  // Returning the address is equivalent to returning the pointer.


    /*Q3: How to print the address of a variable?*/
    int l = 10;
    int *k = &l;
    printf("The address of variable l is %p\n",p);

    /*Increment & Decrement*/
    int c[] = {5,16,7,89,45,32,23,10};
    int *po = &c[0]; // *po = 1000;
    /*Post Incre..*/
    printf("%d ",*(po++)); // 5, *po = 1000; after execution: *po = 1004;
    printf("%d ",*po); // 16, *po = 1004;
    /*Pre Incre..*/
    printf("%d ",*(++po)); // 7, *po = 1004; before execution:*po = 1008; *(++p) === *(1008)

    /*Pre & Post Decrement*/
    printf("%d ",*(--p)); // 16
    printf("%d\n",*(p--)); // 16

    /*Comparing Pointers*/
    po = &c[3];
    int *qo =&c[5];
    printf("%d ",po <= qo); // 1
    printf("%d ",po >= qo); // 0
    qo =& c[3];
    printf("%d\n",po == qo); // 1

    int *p1 = &c[1], *q1 = &c[5];

    printf("%d",*(p1+3));     // *c[1 + 3] = 45;
    printf("%d",*(q1-3));     // *c[5 - 3] = 7;
    printf("%d", q1 - p1);    // &c[5] - &c[1] === 5 - 1 = 4;
    printf("%d", p1 < q1);    // 1 < 5 = 1;
    printf("%d\n",*p1 < *q1);   // 16 < 32 = 1;


    /*Sum of elements of Array*/
    int s[] = {11,22,36,5,2};
    int sum=0, *pt;
    pt = &s[0];
    for(pt=&s[0]; pt <= &s[4]; pt++){
        sum += *pt;
    }
    /*
    // Also works //
    int lent = sizeof(s)/sizeof(s[0]);
    for(int i=0; i<lent;i++){
        sum += *(pt++);
    }
    // Also works //
    for(pt=s; pt<=s+4;pt++){
        sum+= *pt;
    }
    */
    printf("The sum of elements of Array c: %d\n",sum);

    /*Reversing a Series of Numbers using Pointers*/
    int d[N], *pr;
    printf("Enter %d elements in the array: ", N);
    for(pr=d;pr<= d+(N-1);pr++) scanf("%d",pr);         // pr = 1000; pr <= 1000+(5-1)x4(bytes); pr++; scanf --> pr = &d[0]; In the first statement

    printf("Elements in reverse order: \n");
    for(pr=d+(N-1); pr >= d;pr--)  printf("%d ", *pr);

    /*Passing Array as an Argument to a Function*/
    int lenn = sizeof(a)/sizeof(a[0]);
    printf("\n%d\n",add(a,lenn)); // We are not passing the whole array. We are just passing the base address of the array.
                                // An array name is always treated as a pointer.

    /*Using pointers with two dimensional arrays*/
    //for(p=a&[0][0]; p <= &a[row-1][col-1]; p++) printf("%d",*p); Output: 1 2 3 4

    /*Address Arithmetic of Multidimensional arrays*/
    int ab[2][2][2] = {1,2,3,4,5,6,7,8};
    int *pb;
    pb = &ab[0][0][0];

    printf("%d",**(*(ab+1)+1));\

    /*PROGRAM 3
    Consider the following declaration of two dimensional array in C\
                        char[100][100]
    Assuming that the main memory is byte addressable and that the array is
    stored starting from the memory address 0, the address of a[40][50] is:

    b)4050

                        &a[40][50]
    Formula: &a[i][j] = BA + [(i-lb1)] x NC + (j-lb2)] x c

    Where BA = Base Address of whole 2D array
    NC = Number of columns
    c = size of data type of elements stored in array (in bytes)

    a[lb1....ub1][lb2....ub2]
    Where BA = 0
    NC = 100
    c = 1 byte
    a[0...99][0...90]

    &a[40][50] = 0 + [(40-0)] x 100 + (50-0)] x 1
             = 4000 + 50
             = 4050
    */
    /*
    PROGRAM 4
    What is the output of the following C code? Assume that the address of x is 2000
    (in decimal) and an integer requires four bytes of memory.

    a) 2036,2036,2036

    int main(){
        unsigned int x[4][3] ={{1,2,3},{4,5,6},
                               {7,8,9},{10,11,12}};
        printf("%u","%u","%u", x+3,*(x+3),*(x+2)+3);
    }

     --> x[   1  ][   2   ][   3  ][  4   ][   5  ][  6   ][   7  ][  8   ][   9  ][  10  ][  11  ][  12  ]
          | 2000 ||  2004 || 2008 || 2012 || 2016 || 2020 || 2024 || 2028 || 2032 || 2036 || 2040 || 2044 |
          [          2000         ][         2012         ][         2024         ][         2036         ]

    x = pointer to he first 1D array => 2000
    x + 3 = pointer to the 4th 1D array => 2000 + 3x3(elements)x4(byte) => 2036
    *(x+3) = pointer to the 1st element of 4th 1D array => 2036
    x + 2 = pointer to the 3rd 1D array => 2024
    *(x+2) = pointer to the 1st element of 3rd 1D array => 2024
    *(x+2)+3 = 2024 + 3x4(byte) => 2024 + 12 => 2036

    */
    /*Pointer Pointing to an Entire Array (Solved Problem)*/
    int va[][3] = {1,2,3,4,5,6};                 // === {{1,2,3},{4,5,6}}
    int (*ptr)[3] = va;                          // Passing the address of the 1st 1D array
    printf("%d %d", (*ptr)[1],(*ptr)[2]);        // ptr is pointer to first 1D array
                                                 //*ptr is pointer to first element of first 1D array
                                                 // (*ptr)[1] = *((*ptr)+1)
                                                 // (*ptr)+1 gives pointer to second element of first 1D array
                                                 // *((*ptr)+1) gives 2nd element = 2
                                                 // *((*ptr)+2) gives 3rd element = 3
    ++ptr;      // Pointer to 2nd 1D array
    printf("%d %d\n",(*ptr)[1], (*ptr)[2]);        // 5 6
    // Output: 2 3 5 6

    /*PROGRAM 6
    What is the value printed by the following C program:
    */
    int cp[] = {12,7,13,4,11,6};
    printf("%d", f(cp,6));           // === f(&cp[0],6)
    getchar();


    return 0;
}
