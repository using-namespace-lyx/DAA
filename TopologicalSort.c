#include<stdio.h>
#include<stdlib.h>

int k=0,topo[10];

void dfs(int a[10][10],int visited[10],int n,int source)
{
    int i;
    visited[source]=1;
    for(i=1;i<=n;i++)
    {
        if(!visited[i] && a[source][i])
        dfs(a,visited,n,i);
    }
    topo[++k]=source;
}

int main()
{
    int n,a[10][10],i,j;
    printf("\nEnter n:");
    scanf("%d",&n);
    int visited[10]={0};
    printf("\nAdjacenecy matrix\n");
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    scanf("%d",&a[i][j]);

    for(i=1;i<=n;i++)
    if(!visited[i])
    dfs(a,visited,n,i);
    printf("\nTop\n");

    for(i=k;i>=1;i--)
    printf("%d\t",topo[i]);
}