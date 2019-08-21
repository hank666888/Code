#include<iostream>
#include<algorithm>
using namespace std;
int s[21];
int l;
int n;
bool cmp(int a,int b)
{
    return a>b;
}
bool dfs(int t,int a,int b,int c,int d)
{
    if(t>n)
    {
        if(a==b&&a==c&&a==d)
            return true;
        return false;
    }
    if(a>l||b>l||c>l||d>l)
        return false;
    if(dfs(t+1,a+s[t],b,c,d))
        return true;
    if(dfs(t+1,a,b+s[t],c,d))
        return true;
    if(dfs(t+1,a,b,c+s[t],d))
        return true;
    if(dfs(t+1,a,b,c,d+s[t]))
        return true;
    return false;
}
int main()
{
    int m;
    cin>>m;
    while(m--)
    {
        int sum=0,max_num=0;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>s[i];
            sum+=s[i];
            max_num=max(max_num,s[i]);
        }
        sort(s+1,s+1+n,cmp);
        l=sum/4;
        if(sum%4)
            cout<<"no"<<endl;
        else if(max_num>sum/4)
            cout<<"no"<<endl;
        else
        {
            if(dfs(1,0,0,0,0))
                cout<<"yes"<<endl;
            else
                cout<<"no"<<endl;
        }
    }
    return 0;
}
