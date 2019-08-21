#include<iostream>
using namespace std;
int n,sum=0,count=0,a[1001];
void search(int x)
{
    if(sum==n)
    {
        count++;
        return ;
    }
    else
    {
        for(int i=a[x-1]+1;i<=n;i++)
        {
            if(i+sum<=n)
            {
                a[x]=i;
                sum+=a[x];
                search(x+1);
                sum-=a[x];
            }
        }
    }
} 
int main()
{
    cin>>n;
    search(1);
    cout<<count-1;
    return 0;
} 