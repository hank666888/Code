#include <iostream>
using namespace std;

int x1,y1,x2,y2;

int main(){
    cin>>x1>>y1>>x2>>y2;
    if(x2<y1&&x1<y2)
        cout<<min(y1-x2,y2-x1)<<endl;
    else
        cout<<0<<endl;
    return 0;
}
