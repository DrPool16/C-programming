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

    return 0;
}
