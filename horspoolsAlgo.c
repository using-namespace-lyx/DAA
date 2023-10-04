#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int Table[256];

void shiftTable(char p[25])
{
    int m=strlen(p),i;
    for(i=0;i<256;i++)
    Table[i]=m;

    for(i=0;i<m-1;i++)
    Table[p[i]]=m-i-1;
}

int hospool(char t[100], char p[25])
{
    int m=strlen(p);
    int n=strlen(t);
    shiftTable(p);
    int i=m-1,k=0;
    while(i<=n-1)
    {
        while(k<=m-1 && t[i-k]==p[m-1-k])
        k++;

        if(k==m)
        return i-m+1;

        else
        i=i+Table[t[i]];
    }

    return -1;
}

int main()
{
    char p[25],t[100];
    printf("\nEnter Text and Pattern");
    scanf("%s",t);
    scanf("%s",p);
    int res=hospool(t,p);
    if(res!=-1)
    printf("\nPattern found at index %d",res);
    else
    printf("\nPattern not found");
}