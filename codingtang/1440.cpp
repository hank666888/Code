#include<iostream>
#define N 20123
using namespace std;
int n,m,r,l,h,t,k;
int u[1001000];
int ans=0,total=0,sum=0; 
struct node{
    int x;
    int y;
}s[1001000]; 
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=total;j<m+total;j++){
            cin>>s[j].x>>s[j].y;
            if(s[j].x==1)
                sum++;
        }
        u[++t]=sum;
        sum=0;
        total+=m;
    }
    sum=0;
    total=0; 
    cin>>k;
    r=k;
    while(sum!=n){ 
        sum++;
        if(s[k].x==0){
            l=s[k].y%u[sum]+u[sum]; 
            for(int i=k+1;i<=m+k+101;i++){
                if(i==total+m)
                    i=i%(total+m)+total; 
                if(s[i].x==1)
                    l--;
                if(l==0){
                    h=i;
                    break;
                }
            }
            k=h+m;
            total+=m;
        }
        else{
            l=s[k].y%u[sum]+u[sum];
            for(int i=k;i<=k+m+101;i++){
                if(i>=total+m)
                    i=i%(total+m)+total;
                if(s[i].x==1)
                    l--;
                if(l==0){
                    h=i;
                    break;
                }
            }
            k=h+m;
            total+=m;
        }
        ans=(ans+s[r].y)%N;
        r=k;
    }
    ans=(ans+s[r].y)%N;
    cout<<ans%N;
    return 0;
}