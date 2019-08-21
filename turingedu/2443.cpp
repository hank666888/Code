#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

long long x1,x2,y2,a1,a2,b1,b2;

long long Max(long long a,long long b){
    return a>b?a:b;
}

long long Min(long long a,long long b){
    return a<b?a:b;
}

long long abs(long long a){
    return a<0?0-a:a;
}

int main(){
    long long y1;
    cin>>x1>>y1>>x2>>y2>>a1>>b1>>a2>>b2;
    cout<<abs(x1-x2)*abs(y1-y2)+abs(a1-a2)*abs(b1-b2)-Max(0,Min(x2,a2)-Max(x1,a1))<<endl;
    return 0;
}
