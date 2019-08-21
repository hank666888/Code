#include <iostream>
using namespace std;

int pa[210],n;

bool flag[210];

int find(int x){
    if(x==pa[x]) 
        return x;
    return find(pa[x]);
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        pa[i]=i;
    for(int i=1;i<=n;i++){
        int a,x;
        a=find(i);
        while(cin>>x,x!=0){
            flag[x]=true;
            int b=find(x);
            if(a!=b&&pa[b]==b){
                pa[b]=a;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        if(pa[i]==i||!flag[i])
            ans++;
    if(ans==0)
        ans++;
    cout<<ans<<endl;
    return 0;
}