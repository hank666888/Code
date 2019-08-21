#include<iostream>
using namespace std;

struct circle{
    int x,y,r;
};
circle c[100010];

int n,x1,y1,x2,y2,ans;

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>c[i].x>>c[i].y>>c[i].r;
    }
    cin>>x1>>y1>>x2>>y2;
    for(int i=1;i<=n;i++){
        if(c[i].x+c[i].r>x1&&c[i].y+c[i].r>y1&&c[i].x-c[i].r<x1&&c[i].y-c[i].r<y1&&c[i].x+c[i].r>x2&&c[i].y+c[i].r>y2&&c[i].x-c[i].r<x2&&c[i].y-c[i].r<y2)
            continue;
        if((c[i].x+c[i].r>x1&&c[i].y+c[i].r>y1&&c[i].x-c[i].r<x1&&c[i].y-c[i].r<y1)||(c[i].x+c[i].r>x2&&c[i].y+c[i].r>y2&&c[i].x-c[i].r<x2&&c[i].y-c[i].r<y2))
            ans++;
    }
    cout<<ans<<endl;
    return 0;
}