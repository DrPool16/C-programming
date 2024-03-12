#include <stdio.h>
#include <stdlib.h>


/*
ENUMERATION
    An enumerated type is a user defined type which is used to assign names to
    integral constants because names are easier to handle in program.

        * If we do not assign values to
        enum names then, automatically
        compiler will assign values to them
        starting from 0.

        Hey! But we can also use #define to assign names to integral constants.
        Then, why do we even need enum?

        Two important reason:
            1. Enums can be declared in the local scope.
            2. Enums names are automatically initialized by the compiler.

            Reason #1"
            int main()
            {
                enum Bool {False, True} var; <-- This enum is not visible outside this main function.
                var = True;
                printf("%d\n",var); // 1
                return 0;
            }
            Reason #2
            int main()
            {
                enum Bool {False, True} var; <-- False is initialized to 0 and True to 1.
                var = True;
                printf("%d\n",var); // 1
                return 0;
            }
        Some important facts

        Fact #1: Two or more names can have same value
            enum point {x=0, y=0, z=0};
            Output:  0 0 0

        Fact #2: We can assign values in any order. All unassigned names will
                 get value as value of previous name+1.

            enum point{y=2, x=34,t, z=0};
            printf("%d %d %d %d",x,y,z,t);
            Output: 34 2 0 35

        Fact #3: Only integral values are allowed

        Fact #4: All enum constant must be unique in their scope.

            enum point{x=34, y=2, z=0};
            enum point{x=4, p=25, q=1};      <------- WORNG!
            printf("%d %d %d %d %d %d",x,y,z,p,q);   ERROR: Redefinition of enumerator 'x'
            Output: 34 2 0 35

*/


enum Bool {False, True}; // False and True are the names to integral constants

int main()
{
    enum Bool var;
    var = True;
    printf("%d\n",var); // 1
    return 0;
}
