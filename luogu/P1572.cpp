#include<iostream>
#include<string>
using namespace std;


struct Fun
{
    int fm,fz;
    char c;
}fun[110];

Fun ans;

int n;

string str;

int gcd(int a,int b){
    if(b==0)
        return a;
    return gcd(b,a%b); 
}

int lcm(int a,int b){
    return a*b/gcd(a,b);
}

int main(){
    cin>>str;
    for(int i=0;i<str.size();i++){
        if(str[i]=='/'){
            n++;
            fun[n].fm=str[i+1]-'0';
            fun[n].fz=str[i-1]-'0';
            if(i==1)
                fun[n].c='+';
            else
                fun[n].c=str[i-2];
        }
    }
    int flcm=fun[1].fm;
    for(int i=2;i<=n;i++)
        flcm=lcm(flcm,fun[i].fm);
    for(int i=1;i<=n;i++){
        fun[i].fz*=flcm/fun[i].fm;
        fun[i].fm=flcm;
    }
    for(int i=1;i<=n;i++)
        if(fun[i].c=='-')
            fun[i].fz=-fun[i].fz;
    ans.fm=flcm;
    for(int i=1;i<=n;i++)
        ans.fz+=fun[i].fz;
    int gcd_num=gcd(ans.fm,ans.fz);
    if(ans.fm%ans.fz==0)
        cout<<ans.fm/ans.fz;
    else
        cout<<ans.fz/gcd_num<<"/"<<ans.fm/gcd_num<<endl;
    return 0;
}