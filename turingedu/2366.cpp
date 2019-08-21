#include<iostream>
using namespace std;

int n,x1[110],x2[110],y1[110],y2[110],a,b,ans;

int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>x1[i]>>y1[i]>>x2[i]>>y2[i];
    cin>>a>>b;
    for(int x=-100;x<100;x++)
        for(int y=-100;y<100;y++){
            int cnt=0;
            for(int k=1;k<=n;k++){
                if(x1[k]>=x&&y1[k]>=y&&x2[k]<=x+a&&y2[k]<=y+b)
                    cnt++;
            }
            ans=max(ans,cnt);
            cnt=0;
            for(int k=1;k<=n;k++){
                if(x1[k]>=x&&y1[k]>=y&&x2[k]<=x+b&&y2[k]<=y+a)
                    cnt++;
            }
            ans=max(ans,cnt);
        }
    cout<<ans<<endl;
    return 0;
}
