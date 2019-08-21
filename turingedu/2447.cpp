#include<iostream>
using namespace std;

long long a1,b1,c1,d1,a2,b2,c2,d2,a3,b3,c3,d3;

long long s1,s2,s3,s4;

long long max_l(long long a,long long b){
    return a>b?a:b;
}

long long min_l(long long a,long long b){
    return a<b?a:b;
}

long long Max(long long a,long long b,long long c){
    return max_l(max_l(a,b),c);
}

long long Min(long long a,long long b,long long c){
    return min_l(min_l(a,b),c);
}

int main(){
    cin>>a1>>b1>>c1>>d1>>a2>>b2>>c2>>d2>>a3>>b3>>c3>>d3;
    s1=max_l(0,min_l(c1,c2)-max_l(a1,a2))*max_l(0,min_l(d1,d2)-max_l(b1,b2));
    s2=max_l(0,min_l(c1,c3)-max_l(a1,a3))*max_l(0,min_l(d1,d3)-max_l(b1,b3));
    s3=max_l(0,min_l(c2,c3)-max_l(a2,a3))*max_l(0,min_l(d2,d3)-max_l(b2,b3));
    s4=max_l(0,Min(c1,c2,c3)-Max(a1,a2,a3))*max_l(0,Min(d1,d2,d3)-Max(b1,b2,b3));
    if((c1-a1)*(d1-b1)+(c2-a2)*(d2-b2)-s1-s2-s3+s4<0)
        cout<<0<<endl;
    else
        cout<<(c1-a1)*(d1-b1)+(c2-a2)*(d2-b2)-s1-s2-s3+s4<<endl;
    return  0;
}
