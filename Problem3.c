/***********************************************************************************************************************************************************
   NAME - SURAJ JADLI
   COURSE - MCA
   SEMESTER - III
   ROLL NO - 20391054

   Problem Statement
   Design and implement an automaton in ‘C’ programming language to identify and count
   substrings that are present in a given input string, as an identifier or number

   Input from keyboard:  FA parameters, and Input String

  Output on the screen:
  5-tuple representation of the designed automaton, and mapping of
  substrings into identifier or number.

  For example, if input string is “Sum is 123 d@123” then the mapping of substrings should be
  like

    Substring   Identified as

    Sum          identifier
    is           identifier
    123          number
    d@123        others
***********************************************************************************************************************************************************/
#include<stdio.h>
#include<ctype.h>

#define MAX 100


int isNumber(char sub[])
{
    int i = 0;

    while(sub[i] != '\0')
    {
        if(!isdigit(sub[i]))    //can use if(sub[i] >= 'a' && sub[i] <= 'z')
            return 0;
            i++;
    }

    return 1;

}

int isWord(char sub[])
{
    int i = 0;

    while(sub[i] != '\0')
    {
        if(!isalpha(sub[i]))       //  // sub[i] >= '0' && sub[i] <= '9'
            return 0;
            i++;
    }
    return 1;
}

void check(char sub[])
{
    if(isNumber(sub))
        printf("Number");
    else if(isWord(sub))
        printf("Identifier");
    else
        printf("Others");
}


int main()
{
    char str[MAX];

    printf("Enter the String \n");
     gets(str);


    char sub[20];

    int i = 0;
    int j = 0;

    printf("\nSUBSTRING \tIdentified as\n");

    while(str[i] != '\0')
    {
        if(str[i] == ' ')
            {
                sub[j] = '\0';

                printf("%s \t\t", sub);
                check(sub);
                printf("\n");
                j=0;
            }

        else
           {
               sub[j++] = str[i];
           }

            i++;
    }


    printf("%s\t\t", sub);
    check(sub);

    return 0;
}
