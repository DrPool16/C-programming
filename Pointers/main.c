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
    return 0;

}
