#include<stdio.h>
#include<stdlib.h>
#define INFINITY 999

void dijikstras(int n,int s,int cost[10][10],int distance[10])
{
    int visited[10],min,i,j,u;
    for(i=1;i<=n;i++)
    {
        visited[i]=0;
        distance[i]=cost[s][i];
    }
    
    visited[s]=1;
    for(i=1;i<=n;i++)
    {
        min=INFINITY;
        for(j=1;j<=n;j++)
        {
            if(!visited[j] && distance[j]<min)
            {
                min=distance[j];
                u=j;
            }
        }
        
        visited[u]=1;
        
        for(j=1;j<=n;j++)
        {
            if(distance[j]>distance[u]+cost[u][j])
            distance[j]=distance[u]+cost[u][j];
        }
    }
    
    printf("\nDistances\n");
    for(i=1;i<=n;i++)
    {
        if(i!=s)
        printf("%d----->%d    :%d\n",s,i,distance[i]);
    }
    
    
}

int main()
{
    int cost[10][10],distance[10],n,s,i,j;
    printf("\nEnter n:");
    scanf("%d",&n);
    printf("\nEnter cost matrix\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
            cost[i][j]=INFINITY;
            
        }
    }
    
    printf("\nEnter source:");
    scanf("%d",&s);
    
    dijikstras(n,s,cost,distance);
}
