/***********************************************************************************************************************************************************
   NAME - SURAJ JADLI
   COURSE - MCA
   SEMESTER - III
   ROLL NO - 20391054

   Problem Statement -  C program to implement the DFA to accept/reject string

   INPUTS
        -  Number of States
        -  Number of input alphabets
        -  Input alphabets
        -  Initial state

        -  Number of final state
        -  Final state array
        -  Transition table
        -  Input string

    OUTPUT
       String Accepted or not

       Note -
       -two type of input alphabets accepted only
            -alphabets
            -whole numbers
       -Enter the input alphabets in sequence like 0,1,2,... or a,b,c...  not like 1,0,2....
***********************************************************************************************************************************************************/


#include<stdio.h>

void main()
{

    int Q;
    printf("\nEnter Numbers of States => ");
    scanf("%d", &Q);

    int E;
    printf("\nEnter the numbers of Input Alphabet => ");
    scanf("%d", &E);

    printf("\nEnter alphabets Without Space\n(Ex - ab or 01 )\n");
    char Ea[E];
    for(int i=0; i<E; i++)
    {
       fflush(stdin);   // to clear any input in buffer like \n
        char ci;
        scanf("%c",&ci);
        Ea[i] = ci;
    }

    int q;
    printf("\nEnter the Initial State => q");
    scanf("%d",&q);

    int F;
    printf("\nEnter the numbers of final state => ");
    scanf("%d", &F);

    int Fa[10];
    printf("\n Enter the Final States \n");
    for(int i=0; i<F; i++)
    {
        printf("q");
        scanf("%d", &Fa[i]);
    }

        //  Transition function
    printf("\n Transition Table \n");
    int dfa[Q][E];
    for(int i=0; i<Q; i++)
    {
        for(int j=0; j<E; j++)
        {
            printf("(q%d, %c) = q", i,Ea[j]);
            scanf("%d",&dfa[i][j]);
        }
    }


 char ck;

   do {
    char inStr[10];
    printf("Enter the string to be checked \n");
    scanf("%s", inStr);

    int s = q, i = 0, f = 0;

    if(inStr[0] >= 'a' &&inStr[0] <= 'z')
        f=1;


    while(inStr[i] != '\0')
    {
        if(f == 1)
        {
            int ch = inStr[i]-'a';
            s =  dfa[s][ch];
        }
        else
        s =  dfa[s][inStr[i]-'0'];
        i++;
    }

    printf("Final result = q%d\n", s);

    int flag = 0;

    for(int k = 0; k<F; k++)
    {
      if(s == Fa[k])
        {
         flag = 1;
         break;
        }
    }

    if(flag)
        printf("String Accepted\n");
    else
        printf("String Rejected \n");


    printf("\n\n Do you want to check another string(y/n) => ");
      fflush(stdin);
      scanf("%c",&ck);
   }while(ck!='n');

}
