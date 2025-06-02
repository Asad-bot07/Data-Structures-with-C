#include<stdio.h>
#include<stdlib.h>
int check(int *arr,int n)
{
    int i,candi=arr[0],count=0;
    for(i=0;i<n;i++)
    {
        if(arr[i]==candi)
        count++;
        else if(count==0)
        candi=arr[i];
        else
        count--;
    }
    return candi;
}
void accept(int *arr,int n)
{
    int i;
    for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
}
int main()
{
    int *ptr,n;
    printf("Enter the number of elements you want to enter : ");
    scanf("%d",&n);
    ptr=(int*)calloc(n,sizeof(int));
    printf("Enter array elements :\n");
    accept(ptr,n);
    int ans;
    ans=check(ptr,n);
    printf("The majority element is : %d",ans);
}