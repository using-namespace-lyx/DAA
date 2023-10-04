#include<stdio.h>
#include<stdlib.h>
int c=1,x[10];

int place(int i,int j)
{
    int k;
    for(k=1;k<i;k++)
    {
        if(j==x[k] || abs(i-k)==abs(j-x[k]))
        return 0;
    }
    
    return 1;
}

void printboard(int n)
{
    int i,j;
    printf("\nSolution %d\n",c++);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(j==x[i])
            printf("Q\t");
            else
            printf("-\t");
        }
        
        printf("\n");
    }
}

void nQueens(int i,int n)
{
    int j;
    for(j=1;j<=n;j++)
    {
        if(place(i,j))
        {
            x[i]=j;
            if(i==n)
            printboard(n);
            else
            nQueens(i+1,n);
        }
    }
}

int main()
{
    int n;
    printf("\nEnter n:");
    scanf("%d",&n);
    
    printf("\n");
    nQueens(1,n);
    if(c==1)
    printf("\nNo Solution");
}