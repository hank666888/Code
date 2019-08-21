#include <iostream>
using namespace std;

int pa[210],n;

int find(int x){
    return pa[x]==x?x:pa[x]=find(pa[x]);
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        pa[i]=i;
    for(int i=1;i<=n;i++){
        int a,x;
        a=find(i);
        while(cin>>x,x!=0){
            int b=find(x);
            if(a!=b&&pa[x]==x){
                pa[x]=a;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        if(pa[i]==i)
            ans++;
    if(ans==0)
        ans++;
    cout<<ans<<endl;
    return 0;
}