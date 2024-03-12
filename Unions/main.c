#include <stdio.h>
#include <stdlib.h>

/*

UNIONS
    Union is a user defined data type buy unlike structures, union members share same memory location.

    Introduction to Unions
        struct abc {
            int a;
            char b;
        };
        a's = 6295624
        b's = 6295628

        union abc {
            int a;
            char b;
        };
        a's = 6295624
        b's = 6295624

        Fact: In union, members will share same memory location. If we make changes in one
              member then it will be reflected to other member as well.

        Deciding the size of Union
            Size of the unions is taken according to the size of the largest member of the union.

            In my machine:
                * Size of int: 4 bytes.
                * Size of char: 1 bytes.
                * Size of double: 8 bytes.
                * Size of float: 4 bytes.

        Accessing members using pointers
            We can access members of union trough pointer by using the arrow (->)

    SOLVED PROBLEM 1

    Consider the following C declaration
        *Assume that objects of the type short,
        float and long occupy 2 bytes, 4 bytes
        and 8 bytes, respectively. The memory
        requirement for variable t, ignoring
        alignment considerations, is:

         struct{
            short s[5];  5 x 2 Bytes = 10 Bytes
            union {
                float y; // 4 Bytes
                long z;  // 8 Bytes
            } u;         // Memory allocated to the union is equal to the memory needed for the largest member of it. 8 Bytes
         } t; t = 10 Bytes + 8 Bytes = 18 Bytes

         c) 18 Bytes

    Application of Unions (Part 1)

        A store sells two kinds of items:
            1. Books
            2. Shirts

        Store owners want to keep records of the above mentioned items along with the relevant information.

        Books: Title, Author, Number of Pages, Price
        Shirts: Color, Size, Design, Price

        We can save a lot of space if we star using Unions

    Application of Unions (Part 2)

        Creating your own mixed type data structure
            How good is that if we have an array containing mixed type data?
            And why not structures?
                Assuming,
                    sizeof(int) = 4 bytes
                    sizeof(char) = 1 bytes
                    sizeof(double) = 8 bytes


        typedef union {    <--- Size = 8 bytes. If were struct instead of union, size will be 13 bytes, cuz, 4+1+8 = 13 bytes for struct.
            int a;
            char b;
            double c;
        }data;

        int main (){
            data arr[10]; <--- Union: Size = 10 x 8 bytes = 80 bytes || Struct: 10 x 13 bytes = 130 bytes.
            arr[0].a = 10;
            arr[1].b = 'a';
            arr[2].c = 10.178;
            // and so on        // Successful is creating an array containing mixed type data.
            return 0;
        }


*/

/*Introduction to Unions*/
union abc{
    int a;
    char b;
    double c;
    float d;
}var;

/*Application of Unions (Part 1)*/
#pragma pack(1)

struct store{
    double price;
    union {
        struct {
            char *title;
            char *author;
            int num_pages;
        } book;

        struct {
            int color;
            int size;
            char *desing;
        } shirt;

    } item;
};


int main()
{
    /*Introduction to Unions*/
    var.a = 65;
    printf("a = %d ", var.a); // 65
    printf("b = %c\n",var.b); // A

    printf("%ld\n",sizeof(union abc)); //  8 Bytes

    var.a = 90;
    union abc *p = &var;            // We have pointer p which is pointing to some object of type union abc
    printf("%d %c\n", p->a,p->b);   // 90 Z

    /*Application of Unions (Part 1)*/
    struct store s;
    s.item.book.title = "The Alchimist";
    s.item.book.author = "Paulo Coelho";
    s.item.book.num_pages = 197;
    printf("%s  ",s.item.book.title);
    printf("%ld \n",sizeof(s));
    s.item.shirt.color = "Light Brown";
    s.item.shirt.size = 34;
    printf("%s  ",s.item.shirt.color);
    printf("%ld \n",sizeof(s));




    return 0;
}
