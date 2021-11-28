/***********************************************************************************************************************************************************
   NAME - SURAJ JADLI
   COURSE - MCA
   SEMESTER - III
   ROLL NO - 20391054

   Problem Statement - Write a C Program to scan and count the number of characters, words, and lines in a given text file.

   Input from keyboard: text file name

   Output on the screen:

   Number of characters:
   Number of words:
   Number of lines:
***********************************************************************************************************************************************************/

#include<stdio.h>

void main()
{
    ///file pointer
   FILE *fp;

   ///opening file in read mode
   fp = fopen("abc.txt", "r");

   /// to get each character from file
     char ch;

     /// counters for words, lines, characters
     int characters = 0, words = 0, lines = 0;

     /// if fp is not null(f!=null) go inside if condition
   if(fp) {
       while((ch = getc(fp)) != EOF)              ///reading each character from file until it reach End Of File(EOF)
       {
           if(ch != ' ' && ch != '\n')
                characters++;
            else if(ch == ' ' || ch == '\n')
                words++;
            if (ch == '\n')
                lines++;
       }

     if(characters > 0 )
     {
       printf("Characters = %d \n", characters);
       printf("Word = %d \n",words+1);
       printf("Lines = %d \n", lines+1);
    }
    else{
        printf("Empty file\n");
    }

   }
   else{
       printf("File Not Found \n");
   }

}
