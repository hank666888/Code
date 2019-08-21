#include<string>
#include<iostream>
#include<map>
using namespace std;
map<char,char> l,r;
string s1,s2;
int length(char t)
{
    int ans=0;
    if(l[t]) 
        ans+=length(l[t]);
    if(r[t]) 
        ans+=length(r[t]);
    if(ans==0) 
        return 1;
    return ans;
}
char work(int l1,int r1,int l2,int r2){
    int m=s2.find(s1[l1]);
    if(m>l2) 
        l[s1[l1]]=work(l1+1,l1+m-l2,l2,m-1);
    if(m<r2) 
        r[s1[l1]]=work(l1+m-l2+1,r1,m+1,r2);
    return s1[l1];
}
int main(){
    cin>>s1>>s2;
    work(0,s1.length()-1,0,s2.length()-1);
    for(int i=0;i<=s1.length()-1;i++)
    {
        for(int j=1;j<=length(s1[i]);j++)
            cout<<s1[i];
        cout<<endl;
    }   
    return 0;
}