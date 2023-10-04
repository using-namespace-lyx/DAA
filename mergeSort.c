#include<stdio.h>
#include<stdlib.h>
int count;

void merge(int a[],int l,int r,int m)
{
    int i=l,k=l,j=m+1,b[1000];
    while(i<=m && j<=r)
    {
        if(a[i]<a[j])
        {
            b[k++]=a[i++];
            count++;
        }

        else
        {
            b[k++]=a[j++];
            count++;
        }

    }

    while(i<=m)
    b[k++]=a[i++];

    while(j<=r)
    b[k++]=a[j++];

    for(i=l;i<=r;i++)
    a[i]=b[i];
}

void mergesort(int a[],int l,int r)
{
    if(l<r)
    {
        int mid=(l+r)/2;
        mergesort(a,l,mid);
        mergesort(a,mid+1,r);
        merge(a,l,r,mid);
    }
}

int main()
{
    int i,j,n,a[1000],x[1000],y[1000],z[1000],c1,c2,c3;
    printf("\nEnter n:");
    scanf("%d",&n);
    printf("\nEnter elements of array\n");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    mergesort(a,0,n-1);
    printf("\nSorted array\n");
    for(i=0;i<n;i++)
    printf("%d\t",a[i]);
    printf("\nCount:%d",count);

    printf("\n\nn\tASC\tDSC\tRND\n");

    for(i=16;i<1000;i*=2)
    {
        for(j=0;j<i;j++)
        {
            x[j]=j;
            y[j]=i-j-1;
            z[j]=rand()%i;
        }

        count=0;
        mergesort(x,0,i-1);
        c1=count;

        count=0;
        mergesort(y,0,i-1);
        c2=count;

        count=0;
        mergesort(z,0,i-1);
        c3=count;

        printf("\n%d\t%d\t%d\t%d",i,c1,c2,c3);


    }

}
