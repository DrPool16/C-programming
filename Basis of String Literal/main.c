#include <stdio.h>
#include <stdlib.h>


/*
DEFINITION
    String Literal (or String ) is a sequence of characters enclosed within double quotes.
        %s is a placeholder

        printf("%s", "hello everyone");
        printf("%s", 'hello everyone');

        printf("%s","You have to dream before.
               --Abdul Kalam");
               ERROR

    Storing the String Literals
        printf("Earth");

        "Earth" is a string literal
        First argument to printf and scanf function is always a string literal.
        But, what we are actually passing to the printf/scanf?


       String literals are stored as an array of characters .

       [E][a][r][t][h][\0]<--- Indicates the end of the string
                        ---> Null Character

        Total 6 bytes of read-only memory is allocated to the above string literal.
        '\0' character must not be confused with '0' character.
        Both have different ASCII codes. '\0' has the code 0 while '0' hast the code 48.

        In C, compiler treats a string literal as a pointer to th first character.


        [ E  ][a][r][t][h][\0]
         1000

        So to the printf or scanf, we are passimg a pointer to the first character of a string literal.
        Both printf and scanf functions expects a character pointer (char *) as an argument.

                    printf("Earth");

        Passing "Earth" is equivalent to passing the pointer to letter 'E'.

    Performing Operations on String Literals
        Assigning string literal to a pointer

            char *ptr = "Hello World!";
        ptr contains the address of the first character of the string literal.
            char *ptr = "Hello";
        As writing "Hello" is equivalent to writing the pointer to the first character.
        Therefore, we can subscript it to get some character of the string literal.

            "Hello"[1] is equivalent to pointer to 'H'[1]

            [  H  ][  e ][ l  ][  l ][  o ][ \0 ]
              1000  1001  1002  1003  1004  1005

        pointer to 'H'[1] = *(pointer to 'H' + 1)
        pointer to 'H'[1] = *(1000 + 1) = *(1001) = 'e'
        Similarly,
        "Hello"[0] => 'H'
        "Hello"[1] => 'e'
        "Hello"[2] => 'l'
        "Hello"[4] => 'l'
        "Hello"[5] => 'o'

        Point to be noted
        - String literal cannot be modified. It causes undefined behavior.
            char *ptr = "Hello";
            *ptr = 'M'; <---- Not Allowed.
        String literals are also known as string constants.
        They haver been allocated a read only memory. So we cannot alter them.

        But character pointer itself has been allocated read-write memory. So the
        same pointer can point to some other string literal.

    String Literal vs Character Constant
        String Literal and Character Constant are not same.
        "H" =/== 'H'
        "H" Represented by a pointer to a character 'H'
        'H' Represented by an integer (ASCII Code: 72)

        printf("\n"); Okey, expects a pointer to a character
            =/==
        printf('\n'); Passing integer

        printf expect a pointer to a character not the integer.

    Declaring and Initializing a String variable

        A string variable is a one dimensional array of characters that is capable of holding a string at a time.

        For example: char s[6];

        Note: always make the array one character longer than the string. If length
        of the string is 5 characters long than don't forget to make extra room for Null
        character.

        Failing to do the same may cause unpredictable results when program is executed
        as some C libraries assume the strings are Null terminated.

        Example:        char s[6] = "Hello"; String length is 5, it is not string literal

                        s[H][e][l][l][o][\0]
        Although, it seems like "Hello" in the above example is a string literal but it is not.
        When a string is assigned to a character array, then this character array is treated like other types of arrays.

        They both are equal:
            char s[6] = "Hello";
            char s[6] = {'H','e','l','l','o','\0'};

        Recall: We cannot modify a string literal.

        ERROR:
            char *ptr = "Hello";
            *ptr = 'M';

        NO PROBLEM:
            char s[6] = "Hello";
            s[0] = 'M';

        Short length initializer
            char s[6] = "Hello";
                s[H][e][l][l][o][\0][\0]
        Long length initializer
            char s[4] = "Hello";
                s[H][e][l][l] <-- rest of the part is truncated.
            printf("%s",s);
            Warning: initializer-string for array of chars is too long
            Output: Hell?
        Equal length initializer
            char s[5] = "Hello";
                s[H][e][l][l][o] <-- No \0 at the end, No run for the Null character.
        Omitting the length
            char s[] = "Hello";
            Automatically, the compiler sets aside 6 characters for s which is
            enough to store the string "Hello" with null character.



*/
int main()
{


    printf("%s","You have to dream before.\
           --Abdul Kalam");             //L--> In C, this is called "Splicing"
                                        //Considered 4 spaces before--
    printf("%s","You have to dream before."
           "--Abdul Kalam");            //Does not consider the indentation before--
    return 0;
}
