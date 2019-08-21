#include <iostream>
using namespace std;
int par[1000000];
int find(int x)
{
    if(x==par[x]) return x;
    return find(par[x]);
}
int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    par[i]=i;
    for(int i=1; i<=n; i++)
    {
        int x;
        cin>>x;
        while(x!=0)
        {
            int a=find(i);
            int b=find(x);
            if(a!=b&&par[x]==x)
            {
                par[x]=i;
            }
            cin>>x;
        }
    }
    int ans=0;
    for(int i=1; i<=n; i++)
    if(par[i]==i) ans++;
    cout<<ans;
}