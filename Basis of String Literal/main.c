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


    String (Solved Problem 1)

        Identify which if the following calls don't work properly and give the reason for the same.

            a) printf("%c",'\n');   the printf is expecting a character (%c) and it is also passing a character (enclosed within single quotes) (WORKS)
            b) printf("%c","\n");   expecting a character and passing a string (enclosed within double quotes) (WON'T WORK)
            c) putchar('\n');       putchar function expects a character and it is passing a character (WORK)
            d) putchar("\n");           ""              ""               ""                a string (WON'T WORK)
            e) puts('\n');          puts function expects a string and it is passing a character (WON'T WORK)
            f) puts("\n");              ""              ""               ""          a string (WORK)
            g) printf("%s",'\n');   expecting a string(%s) and it is also passing a character (WON'T WORK)
            h) printf("%s","\n");       ""              ""               ""       a string (WORK)

    C string Library ans String Copy Function - strcpy()

        There are some operations which we can perform on strings.

        For example: Copy strings, concatenate strings, select substrings and so on.

        <string.h> library contains all the required functions for performing string operations.

        So we just have to include this header file: #include <string.h> in our program
        and we are good to go.

        strcpy (string copy) function

        Prototype: char* strcpy(char* destination, const char* source)
                                                   --> It is not modified, That is why it is constant.
        strcpy is used to copy a string pointed by source (including NULL character) to the destination (character array)

        A WORD OF CAUTION:
            - In the call to strcpy(str1, str2), there is no way the strcpy will check whether
              the string pointer by str2 will fit in str1.

            - If the length of the string pointed by str2 is greater than the length of character array str1 then
              it will be an undefined behaviour.

              To avoid this we can call strncpy function.
              Prototype: strncpy(destination, source , sizeof(destination));

              - But if we try to copy the string using strcpy, it causes undefined behaviour.
                    char str1[6] = "Hello";
                    char str2[4];
                    strcpy(str2,str1);
                    printf("%s",str2);

                    Output: Undefined Behaviour.

        Also, please note that:

            strncpy will leave the string in str2(destination) without a terminating NULL
            character, if the size of str1(source) is equal to ot greater than the size of
            str2(destination).

                    char str1[6] = "Hello";
                    char str2[6];
                    strncpy(str2,str1, sizeof(str2));
                    str2[sizeof(str2)-1] = '\0';
                    printf("%s",str2);


    String Length Function - strlen()

        Prototype : size_t strlen(const char* str);
                      ---> size_ t is an unsigned integer type of at least 16 bits.

        strlen() function is used to determinate the length of the given string.
        To the strlen() function, we should pass the pointer to the first character of
        the string whose length we want to determinate.
        And as result, It returns the length of the string.

        Note: it does not count NULL character

    String Concatenate Functions - strcat() & strncat()

        Strcat() Function
            Prototype: char* strcat(char* str1, const char* str2);

            Strcat function appends the content of string str2 at the end of the string str1.
            It returns the pointer to the resulting string str 1.

            CAUTION
                - An undinef behaviour can be observed if size of str1 is not long enoug to
                accomodate the addtional characters of str2.

                Because you are trying to add more characters than the memory allocated.

        Strncat() Function
            strncat is the safer version of strcat.
            It appends the limited number of characters specified by the third argument passed to it.

            Note: strncat automatically adds NULL character at the end of the resultant string.

            Prototype: strncat(str1, str2, sizeof(str1) - strlen(str1)-1);
            sizeof(): size/length whole array
            strlen(): size/length whole string
            -1 : Creating room for NULL character

    String Comparison Function - strcmp()

        Prototype: int strcmp(const char* s1, const char* s2);

        * Compares two strings s1 and s2;
        * Retruns value
            Less than 0, if s1<s2
            Greater than 0, if s1>s2
            Equal to 0, if s1 == s2

        The Notice Board
                    Attention!!

            In ASCII character set
            * All upper case letters are less than all the lower case letters
              (Upper case letters have ASCII codes between 65 and 90 and
               Lower case letters have ASCII codes between 97 and 122).
            * Digits are less than letters(0-9 digits have ASCII codes between 48 and 57).
            * Spaces are less than all printing characters (Spaces character has the
              value 32 in ASCII set).

        strcmp considers s1<s2 if either one of the following conditions is satisfied:

            * When the first i character in s1 and s2 are same and (i+1)st character of
              s1 is less than that of s2.

            * All characters of s1 match s2, but s1 is shorter than s2.

    Array of Strings
        Two Dimensional Array
            char fruits[][12] = {"2 Oranges","2 Apples","3 Bananas","1 Pineapple"};

            [2][][O][r][a][n][g][e][s ][\0][\0][\0]     <--
            [2][][A][p][p][l][e][s][\0][\0][\0][\0]     <-- A lot of space is simply wasted
            [3][][B][a][n][a][n][a][s ][\0][\0][\0]     <--
            [1][][P][i][n][e][a][p][p ][l ][e ][\0]

    Array of pointers
        One Dimensional Array
            char *fruits[] = {"2 Oranges","2 Apples","3 Bananas","1 Pineapple"};

            fruits
              0[] --> [2][][O][r][a][n][g][e][s ][\0]
              1[] --> [2][][A][p][p][l][e][s][\0]
              2[] --> [3][][B][a][n][a][n][a][s ][\0]
              3[] --> [1][][P][i][n][e][a][p][p ][l ][e ][\0]




*/

#include <string.h>

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
        putchar(ch1);                 //ABCDEFG....XYZ


    /*C string Library ans String Copy Function - strcpy()*/
    char str1[10] = "Hello";
    char str2[10];

    printf("\n%s\n", strcpy(str2, str1));       // Hello
    printf("%s\n", str2);                       // Hello

    // We can also chain together a series of strcpy calls

    char str3[10];
    strcpy(str3,strcpy(str2, str1));
    printf("%s %s\n", str2,str3);                 // Hello Hello

    //strncpy
    char str4[6] = "Hello";
    char str5[4];
    strncpy(str5,str4, sizeof(str5));
    str5[4] = '\0';                 // As source length >= destination length, the NULL character has to be added explicitly.
    printf("%s\n",str5);              // Hell

    // But if we try to copy the string using strcpy, it causes undefined behaviour.


    char str6[6] = "Hello";
    char str7[6];
    strncpy(str7,str6, sizeof(str7));
    str7[sizeof(str7)-1] = '\0';
    printf("%s\n",str7);

    /*String Length Function - strlen()*/

    char *str8 = "Hello World";         // 11
    //char str8[] = "Hello World";      // 11
    //char str8[100] = "Hello World";   // 11
    printf("%d\n",strlen(str8));          // It calculates the length of the string and not the length of the whole array

    /*String Concatenate Functions - strcat() & strncat()*/

    char str9[100], str10[100];
    strcpy(str9, "Welcome to ");
    strcpy(str10, "Our Academy");
    strcat(str9, str10);
    printf("%s\n", str9);               // Welcome to Our Academy

    char str11[5], str12[100];
    strcpy(str11,"He");
    strcpy(str12,"llo!");
    strncat(str11,str12, sizeof(str11)-strlen(str11)-1); // sizeof(str11) = 5; strlen(str11) = 2; 5-2-1 = 2;
    printf("%s\n", str11);        // Output: Hell


    /*String Comparison Function - strcmp()*/
    // Example 1:
    char *s1 = "abcd";
    char *s2 = "abce";
    if(strcmp(s1,s2) < 0)                           // abc == abc, first 3 character are matching, but d < e
        printf("s1 is less than s2\n"); // <------ Output
    else
        printf("s1 is greater that or equal to s2");
    // Example 2:
    char *s3 = "abce";
    char *s4 = "bbce";
    if(strcmp(s3,s4) < 0)                           // a < b
        printf("s3 is less than s4\n"); // <------ Output
    else
        printf("s3 is greater that or equal to s4");
    // Example 3:
    char *s5 = "bbce";
    char *s6 = "abce";
    if(strcmp(s5,s6) < 0)                           //s5:b > s6:a,
        printf("s5 is less than s6");
    else
        printf("s5 is greater that or equal to s6\n"); // <------ Output

    // Example 4:
    char *s7 = "abcd";
    char *s8 = "abcd";
    if(strcmp(s7,s8) < 0)                           //s7:a == s8:a,
        printf("s7 is less than s8");
    else
        printf("s7 is greater that or equal to s8\n"); // <------ Output

    // Example 5:
    char *s9 = "abc";
    char *s10 = "abcd";
    if(strcmp(s9,s10) < 0)                           //abc == abc, first 3 character are matching, but 0 < d
        printf("s9 is less than s10\n"); // <------ Output
    else
        printf("s9 is greater that or equal to s10\n");


    return 0;
}
