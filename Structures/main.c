#include <stdio.h>
#include <stdlib.h>


/*
STRUCTURE

    A Structure is a user defined data type that can type that can be used to group elements
    of different types into a single type.

    Declaring structure variable

        struct {
            char *engine;
            char *fuel_type;
            int fuel_tank_cap;
            int seating_cap;
            float city_mileage;
        } car1,car2;

    Structure Type (Using Structure Tags)

        Structure tag is used to identify a particular kind of structure.

            struct car {  // <--- structure tag
                char engine[50];
                char fuel_type[];
                int fuel_tank_cap[];
                int seating_cap;
                float city_mileage;
            }(Option 2);  <--- Option 2: c1, this one is also valid, but the actual use of structure tag is what we have already discussed.
            int main(){
                struct car c1;
            }
    Structure Types (Using typedef)

        Syntax: typedef exiting_dara_type new_data_type;

        typedef gives freedom to the user by allowing them to create their own types.

        typedef int INTEGER;
        int mian(){
            INTEGER var = 100;
        }

            struct car {            // <--- Old type
                char engine[50];
                char fuel_type[];
                int fuel_tank_cap[];
                int seating_cap;
                float city_mileage;
            }car;                   // <--- New type, car becomes in a new data type.
                car c1;
            }
    Initializing & Accessing the Structure Members

        - We can access members of the structure using dot(.) operator.

    Designated Initialization in Structures

        - Designed initialization allows structures members to be initialized in any order.

    Declaring an Array of Structure
        - Instead of declaring multiple variables, we can also declare array of structure
          in which each element of the array will represent a structure variable.

    Pointer to Structure Variable

        ptr is pointing to some variable of type struct abc.
        ptr->x is equivalent to (*ptr).x --> (*&b).x --> b.x

    Structure Padding in C

        How memory is allocated to structure members?
            - When an object of some structure type is declared then some contiguous
              block of memory will be allocated to structure members.

              For example:

              struct abs{
                char a;
                char b;
                int c;

              } var; <--- object of this structure type

        What is the size of struct abs?
            Calculating the size of the struct
                - There is a concept called structure padding.
            Structure padding
                - Processor doesn't read 1 byte at a time from memory.
                - It reads 1 word at a time.
                Note: 1 byte is equal to 8 bits
                - If we have a 32 bit processor then it means it can access 4 bytes at
                  a time which means word size is 4 bytes.
                - If we have a 64 bit processor then it means it can access 8 bytes at
                  a time which means word size is 8 bytes.

                struct abs{
                    char a; // 1 byte
                    char b; // 1 byte
                    int c;  // 4 bytes

                  } var;


                    [ ][ ][ ][ ]|[ ][ ][ ][ ]
                     a  b  |_________|
                                c
                    In 1 CPU cycle, char a, char b and 2 byes of int c can be accessed. There
                    is no problem with char a and char b but...
                    Whenever we want the value stored in variable c, 2 cycles are required to access
                    the contents of variable c. In first cycle, 1sy 2 bytes can be accessed and in 2nd
                    cycle, las 2 bytes.

                    - It is an unnecessary wastage of CPU cycles.

                    We can save the number of cycles by using the concept called padding.

                    [ ][ ][ empty ]|[ ][ ][ ][ ]
                     a  b            |________|
                                          c
                    Total = 1 byte (a) + 1 byte (b) + 2 bytes (empty) + 4 bytes (c) = 8 bytes

    Structure Packing

        We can avoid the wastage of memory by simply writing #pragma pack(1)
            - #pragma is a special purpose
              directive used to turn on or
              off certain features.

    SOLVED PROBLEM 2

       - 'a'+2 = 99+2(ASCII Code) = 'c'
       - Whole structure:
            - Assuming word size is 4 bytes

             [ '1' ][ '0' ][ 'c' ][    ]
               1000  1001   1002
        - *q=&p; pointer which will point to an object of type Ournode.

                q[1000] , q contains the address of the whole structure not
                          the address of the first member of the structure.
                          Hence, we can type cast it to point to a particular
                          character instead of pointing to the whole structure.

         (char*)q => q was the pointer to the whole structure. Now it is
                     pointer to a character.

                                  [ '1' ]
                      q[1000] -->   1000

        (char*)q+1 =              [ '0' ]
                      q[1001] -->   1001

        *(char*)q+1 = q[1001] --> [ '0' ]
                                    1001

        SOLVED PROBLEM 3

            struct node{
                int i;
                float j;
            };
            struct node *s[10];  // <-- It's depends of the precedence of the operator, [] is higher against *, so is an Array.

            define s to be:
                a) An Array, each element of which is a
                pointer to a structure of type node.



    Program to Find Area of Rectangle Using Structures

        QUESTION: The following structures are designed to store information about
        objects on a graphics screen.

        struct point { int x, y;};
        strcut rectangle { struct poin upper_left, lower right; };

        A point structure stores the x and y coordinates of a point on the screen. A
        rectangle structure stores the coordinates of the upper left and lower right
        corners of the rectangle.

        Write a function that accepts rectangle structure r as an argument and computes
        the area of r.

        SOLVED PROBLEM STRUCTURES & UNIONS
        Q1: Suppose that s is the following structure:
            - if char values occupy 1 byte, int values occupy 4 bytes, and double values occupy 8
              bytes, how much space will a C compiler allocate for s? (Assume that the compiler
              leaves no "holes" (#pragma pack(1)) between members).

        struct {
            double a;           // 8 bytes   <--
            union {
                char b[4];      // 4 bytes
                double c;       // 8 bytes
                int d;          // 4 bytes
            } e;        <---    // 8 bytes  <--
            char f[4];          // 4 bytes  <--
        } s; <----- 8+8+4       // 20 bytes


        Q2: Suppose that u is the following union:
        union {
            double a;           // 8 bytes
            struct {
                char b[4];      // 4 bytes
                double c;       // 8 bytes
                int d;          // 4 bytes
            } e;    <--- 4+8+4  // 16 bytes  <--
            char f[4];          // 4 bytes;
        } u;        <-----      // 16 bytes
*/


/*Declaring Structure Variable*/
struct {
    char *engine;
} car1,car2;

/*Structure Type (Using Structure tags)*/
struct employee{  // <-- Structure tag
    char *name;
    int age;
    int salary;
};
int manager(){
    struct employee manager;

    manager.age = 27;

    if(manager.age > 30)
        manager.salary = 65000;
    else
        manager.salary = 55000;
    return manager.salary;
}
/*Initializing & Accessing the Structure Members*/
                     /*&*/
     /*Declaring an Array of Structure*/
struct car{
    int fuel_tank_cap;
    int seating_cap;
    float city_mileage;
}c1,c2;

/*Designated Initialization in Structures*/
struct abc{
    int x;
    int y;
    int z;
};
/*Structure Padding*/
struct abs {
    char a;
    char b;
    int c;
};
struct abz {
    char a;
    int b;
    char c;
};
/*Structure Packing*/
#pragma pack(1)
struct abx {
    char a;
    int b;
    char c;
};

/*SOLVED PROBLEM 2*/
struct Ournode{
    char x,y,z;
};

/*Program to Find Area of Rectangle Using Structures*/
struct point {
    int x, y;
};
struct rectangle {
    struct point upper_left;
    struct point lower_right;
};

int area(struct rectangle r){
    int length, breadth;
    length = r.lower_right.x - r.upper_left.x;
    breadth = r.upper_left.y - r.lower_right.y;

    return length * breadth;
}
int main()
{
    /*Declaring Structure Variable*/
    car1.engine = "DDis 190 Engine";
    car2.engine = "1.2 L Kappa Dual VTVT";
    printf("%s\n", car1.engine);
    printf("%s\n", car2.engine);


    struct employee emp1;
    struct employee emp2;
    printf("Enter the salary for employee 1: ");
    scanf("%d",&emp1.salary);
    printf("Enter the salary for employee 2: ");
    scanf("%d",&emp2.salary);
    printf("The employee 1 salary is: %d\n", emp1.salary);
    printf("The employee 2 salary is: %d\n", emp2.salary);
    printf("Manager's salary is: %d\n", manager());

    /*Initializing & Accessing the Structure Members*/
    c1.fuel_tank_cap = 35;
    c2.fuel_tank_cap = 40;

    printf("%d %d\n", c1.fuel_tank_cap, c2.fuel_tank_cap);

    /*Designated Initialization in Structures*/
    struct abc a = {.y = 40, .z = 20, .x = 10};
    printf("%d %d %d\n", a.x, a.y, a.z); // 10 40 20

    /*Declaring an Array of Structure*/
    struct car c[2];
    int i;
    for(i=0;i<2;i++){
        printf("Enter the car %d fuel tank capacity: ",i+1);
        scanf("%d",&c[i].fuel_tank_cap);
        printf("Enter the car %d seating capacity: ",i+1);
        scanf("%d",&c[i].seating_cap);
        printf("Enter the car %d city mileage: ",i+1);
        scanf("%f",&c[i].city_mileage);
    }
    printf("\n");
    for(i=0;i<2;i++){
        printf("\n  The car %d\n",i+1);
        printf("Fuel tank capacity: %d\n",c[i].fuel_tank_cap);
        printf("Seating capacity: %d \n",c[i].seating_cap);
        printf("City mileage: %f\n",c[i].city_mileage);
    }

    /*Pointer to Structure Variable*/
    struct abc b = {0,1};
    struct abc *ptr = &b; //
    printf("\n%d %d\n",ptr->x,ptr->y); // 0 1

    /*Structure Padding*/
    struct abs var;
    printf("%d\n", sizeof(var)); // Output: 8

    struct abz var1;
    /*              [ ][   empty   ]|[ ][ ][ ][ ]|[ ][  empty  ]
                     a                |________|   c
                                          b
                    Total = 1 byte (a) + 3 bytes (empty) + 4 bytes (b) + 1 byte (c) + 3 bytes (empty) = 12 bytes

                    3 words accessed = 12 bytes

    */
    printf("%d\n", sizeof(var1)); // Output: 12

    /*Structure Packing*/
    struct abx var2;
    printf("%d\n", sizeof(var2)); // Output: 6

    /*SOLVED PROBLEM 2*/
    struct Ournode p = {'1','0','a'+2};
    struct Ournode *q = &p;
    printf("%c %c\n",*((char*)q+1),*((char*)q+2)); // 0, c

    /*Program to Find Area of Rectangle Using Structures*/
    struct rectangle r;

    printf("Enter the upper left value of x1 and y1: ");
    scanf("%d %d",&r.upper_left.x, &r.upper_left.y);

    printf("Enter the lower right value of x2 and y2: ");
    scanf("%d %d",&r.lower_right.x, &r.lower_right.y);

    printf("Area of the rectangle: %d", area(r));


    return 0;
}
