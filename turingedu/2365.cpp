#include<iostream>
using namespace std;

int a[110],b[110],c[110],d[110],n,ans;

int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>b[i]>>c[i]>>d[i];
    for(int x=-100;x<100;x++)
        for(int y=-100;y<100;y++)
            for(int i=1;i<=n;i++){
                if(x>=a[i]&&y>=b[i]&&x+1<=c[i]&&y+1<=d[i]){
                    ans++;
                    break;
                }
            }
    cout<<ans<<endl;
    return 0;
}