#include<stdio.h>
#include<stdlib.h>
int b=1,x[10],w[10],d;

void sumOfSubsets(int s,int k,int r)
{
    int i;
    x[k]=1;
    if(s+w[k]==d)
    {
        printf("\nSubset %d\n",b++);
        for(i=1;i<=k;i++)
        if(x[i])
        printf("%d\t",w[i]);
        printf("\n");
    }
    else if(s+w[k]+w[k+1]<=d)
    sumOfSubsets(s+w[k],k+1,r-w[k]);
    
    if(s+w[k]<d && s+r-w[k]>=d)
    {
        x[k]=0;
        sumOfSubsets(s,k+1,r-w[k]);
    }
    
}

int main()
{
    int i,n,sum=0;
    printf("\nEnter n:");
    scanf("%d",&n);
    printf("\nEnter elements in increasing order\n");
    for(i=1;i<=n;i++)
    {
        scanf("%d",&w[i]);
        sum+=w[i];
    }
    printf("\nEnter d:");
    scanf("%d",&d);
    sumOfSubsets(0,1,sum);
    if(b==1 || d>sum || w[1]>d)
    printf("\nNo solution");
    
}