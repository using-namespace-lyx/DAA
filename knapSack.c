#include<stdio.h>
#include<stdlib.h>

int n,W,V[10][10],v[10],w[10],x[10];

int max(int a,int b)
{
    return a>b?a:b;
}

void knapsack()
{
    int i,j;
    
    for(i=0;i<=W;i++)
    printf("%d\t",i);
    for(i=0;i<=n;i++)
    {
        printf("\n%d:",i);
        for(j=0;j<=W;j++)
        {
            if(i==0 || j==0)
            V[i][j]=0;

            else
            V[i][j]=(j-w[i]<0? V[i-1][j]:max(V[i-1][j],V[i-1][j-w[i]]+v[i]));
            printf("%d\t",V[i][j]);
        }
    }
    printf("\n");
}

void print()
{
    int i=n,j=W;
    while(i!=0 || j!=0)
    {
        if(V[i][j]!=V[i-1][j])
        {
            x[i]=1;
            j=j-w[i];
        }
        i--;
    }

    for(i=1;i<=n;i++)
    {
        if(x[i])
        printf("\nObject %d included",i);

        else
        printf("\nObject %d excluded",i);

    }

    printf("\n\n Max Profit:%d",V[n][W]);
}

int main()
{
    printf("\nEnter n:");
    scanf("%d",&n);
    printf("\nEnter W:");
    scanf("%d",&W);
    printf("\nEnter weights\n");
    int i;
    for(i=1;i<=n;i++)
    scanf("%d",&w[i]);

    printf("\nEnter profits\n");
    for(i=1;i<=n;i++)
    scanf("%d",&v[i]);
    knapsack();
    print();
    

}
