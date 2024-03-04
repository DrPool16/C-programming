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

    Writing Strings using printf and puts Functions

        Writing String using Printf

            char *ptr = "Hello World";
            printf("%s", ptr);

            Output: Hello World

            "%.ns" is used to print just a part of the string where n is the number of
            characters to be displayed on the screen.

            char *ptr = "Hello World";
            printf("%.5s",ptr);

            Output: Hello

            "%m.ns" is used to print just a part of the string where n is the number of
            character to be displayed and m denotes the size of the field within which the
            string will be displayed.

            char *ptr = "Hello World!";
            printf("%.5s", ptr);
            printf("%6.5s", ptr,);

            Output: Hello
                     Hello

                     [][H][e][l][l][o]
                    Flied of length m=6

        writing String using Puts

            puts() function is a function declared in <stdio.h> library and is used to write
            strings to the output screen.

            Also, puts() function automatically writes a newline character after writing
            the string to the output screen.

            char *s = "Hello";
            puts(s);
            puts(s);

    Reading Strings using scanf and gets Functions

         Reading Strings using Scanf

            Using scanf(), we can read a string into a string variable (character array)

            char a[10];
            printf("Enter the string:\n");
            scanf("%s",a);      <----- Like any array name, a is treated as a pointer to the first element of the array. Therefore, there is no need to put &
            printf("%s",a);


            Input: You are most welcome
            Output: You
            Why only "You" is stored;

            scanf() does not store the white space characters in the string variable.
            It only reads characters other than white spaces and store them in the
            specified character array until it encounters a white-space character.

            Input: You are most welcome
                       --> When white-space is seen by scanf, it stops and
                       hence, only "You" is stored in the specified
                       character array.

        Reading String using Gets

            In order to read an entire line of input, gets() function can be used.

            char a[10];
            printf("Enter the string:\n");
            gets(a);
            printf("%s",a);

            Input: You are most welcome

                Your program may CRASH!

            Both, gets() and scanf functions have no way to detect when the character
            array is full.
            Both of them never checks the maximum limit of input characters. Hence,
            they can may cause undefined behavior and probably lead to buffer overflow
            error which eventually causes the program to crash.

            Although, scanf() has the way to set the limit for the number of characters to
            be stored in the character array.
            By using %ns, where n indicates the number of characters allowed to store
            in the character array.

            char a[10];
            printf("Enter the string:\n");
            printf("%9s",a);
            printf("%s",a);

            Input: Youaremostwelcome
            Ouput: Youaremos

            But, unfortunately, get() is still UNSAFE.

            It will try to write the characters beyond the memory allocated to the
            character array which is unsafe because it will simply overwrite the memory
            beyond the memory allocated to the character array.

                    Hence, it is advisable to not use the gets() function.


    Designing The Input Function using getchar()

        As scanf and gets functions are risky to use. Hence, it is advisalbel to design our
        own input function.

        We want our input function to have following functionalities:
        1. It must continue to read the string even after seeing white spaces
           characters.
        2. It must stop reading the string after seeing the newline character.
        3. It must discard extra characters
        4. And, it must return the number of characters it stores in the character array.

        getchar() function is used to read one character at a time from the user input.
        It returns an integer equivalent to the ASCII code of the character.

    putchar() Function in C

    Prototype: int putchar(in ch)

    putchar accepts an integer argument (which represent a character it wants to display)
    and returns an integer representing the character written on the screen.

    Always remember that character is internally represented in binary form only.
    It does not make any difference if you write int ch instead of char ch.




*/

int input(char str[], int n){
    int ch, i=0;
    while((ch = getchar())!= '\n')         // This is the reason why we have int ch in place of char ch // ((ch=72) != 10)
        if(i < n)
            str[i++] = ch;                  // Input: Hello, How are you
    str[i] = '\0';
    return i;

}

int main()
{


    printf("%s","You have to dream before.\
           --Abdul Kalam\n");             //L--> In C, this is called "Splicing"
                                        //Considered 4 spaces before--
    printf("%s","You have to dream before."
           "--Abdul Kalam\n");            //Does not consider the indentation before--

    char *s = "Hello";
    puts(s);
    puts(s);

    char str[100];
    int n = input(str,5);
    printf("%d %s\n",n,str);      // 5 Hello

    int ch1 ;
    for(ch1 = 'A'; ch1 <= 'Z';ch1++)
        putchar(ch1);

    return 0;
}
