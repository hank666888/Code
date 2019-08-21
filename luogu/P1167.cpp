#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int n,a[100010];

struct time{
    int year,month,day,hour,minute;
};

time t1,t2;

int main(){
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    scanf("%d-%d-%d-%d:%d",&t1.year,&t1.month,&t1.day,&t1.hour,&t1.minute);
    
    sort(a+1,a+1+n);
}
