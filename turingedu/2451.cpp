#include<iostream>
using namespace std;

int x1,y1,x2,y2,x3,y3;

int Min(int a,int b,int c){
    return min(min(a,b),c);
}

int Max(int a,int b,int c){
    return max(max(a,b),c);
}

int main(){
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    if(Max(x1,x2,x3)<Min(y1,y2,y3)){
        cout<<Min(y1,y2,y3)-Max(x1,x2,x3);
    }
    else
        cout<<0;
    return 0;
}
