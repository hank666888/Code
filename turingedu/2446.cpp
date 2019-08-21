#include<iostream>
using namespace std;

long long x1,x2,y2,a1,b1,a2,b2,p1,q1,p2,q2,s,ans;

int main()
{
    long long y1;
    cin>>x1>>y1>>x2>>y2;
    cin>>a1>>b1>>a2>>b2;
    cin>>q1>>p1>>q2>>p2;
    for(int x=-1000;x<1000;x++)
        for(int y=-1000;y<1000;y++){
            if(((x>=x1&&y>=y1&&x+1<=x2&&y+1<=y2)||(x>=a1&&y>=b1&&x+1<=a2&&y+1<=b2))&&(!(x>=q1&&y>=p1&&x+1<=q2&&y+1<=p2))){
                ans++;
            }
        }
    cout<<ans<<endl;
    return 0;
}
