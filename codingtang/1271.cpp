#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
    long long start,end;
    long long x1,y1,x2,y2;
    double dis=0;
    cin>>start>>end;
    while(scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2)!=EOF)
        dis+=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
    double ans=dis*2/1000/20;
    long long h=(long long)(ans);
    long long m=(long long)((ans-h)*60+0.5);
    printf("%lld:%02lld\n",h,m);
    return 0;
}
