#include <stdio.h>
#include <stdlib.h>

void Logo(int N);
void BuildLine(int AmArray[],int k);

typedef struct print
{
    int amount;
    char symbol;
    struct print *next;
} PRINT;


void Logo(int N)
{
    int i,AmArray[7]= {0},k;
    for(i=0,k=5; i<N/2+1; i++)
    {
        AmArray[0]=N-i;
        AmArray[1]=N+2*i;
        AmArray[2]=N-2*i;
        AmArray[3]=N+2*i;
        AmArray[4]=N-i;

        printf("\n");
        BuildLine(AmArray,k);
        BuildLine(AmArray,k);
    }
    for(i=N/2,k=7; i>=0; i--)
    {
        AmArray[0]=i;
        AmArray[1]=N;
        AmArray[2]=N-2*i;
        AmArray[3]=N+2*i;
        AmArray[4]=N-2*i;
        AmArray[5]=N;
        AmArray[6]=i;

        printf("\n");
        BuildLine(AmArray,k);
        BuildLine(AmArray,k);
    }

}
void BuildLine(int AmArray[],int k)
{
    PRINT *top, *ptr, *tmp;
    int i,j;
    top=(PRINT*)malloc(1*sizeof(PRINT));
    ptr=top;
    for(i=0; i<7 && k--; i++) // added "k" because top part of the logo asks for less memory than the bottom ,
        // it works without k (AmArray[i]=0), but no point wasting processor time and memory.
    {
        ptr->amount=AmArray[i];
        ptr->symbol=(i%2)? '*' : '-';
        ptr->next=(PRINT*)malloc(1*sizeof(PRINT));
        ptr=ptr->next;
    }
    ptr->symbol='\0';
    ptr=top;

    while(ptr->symbol!='\0')
    {
        for(j=ptr->amount; j>0; j--)
        {
            printf("%c",ptr->symbol);
        }
        tmp=ptr;
        ptr=ptr->next;
        free(tmp);
    }
    free(ptr);
}

int main()
{
    int N;
    printf("Please enter odd positive integer for N, from 3 to 9999: ");
    scanf("%d",&N);
    while(N%2==0 || N>9999 || N<3 )
    {
        printf("Invalid Data, Please try again \n Enter N:");
        scanf("%d",&N);
    }

    Logo(N);
    return 0;
}
