#include<iostream>
#include<algorithm>
using namespace std;

int n;
struct birthday{
    int y,m,d;
    int index;
    string name;
}oi[110];

bool cmp(birthday a,birthday b){
    if(a.y!=b.y)
        return a.y<b.y;
    if(a.m!=b.m)
        return a.m<b.m;
    if(a.d!=b.d)
        return a.d<b.d;
    return a.index>b.index;
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>oi[i].name>>oi[i].y>>oi[i].m>>oi[i].d;
        oi[i].index=i;
    }
    sort(oi+1,oi+1+n,cmp);
    for(int i=1;i<=n;i++)
        cout<<oi[i].name<<endl;
    return 0;
}
