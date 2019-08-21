#include<cstdio>
#include<string>
#include<iostream> 
using namespace std; 
int main() {
    int n, maxs=0, x; 
    scanf("%d",&n);
    char s[101]; 
    for(int i=1; i<=n; i++) cin>>s[i]; 
    for(int i=1; i<n; i++) { 
        int t=1; 
        for(int j=i+1; j<n; j++)
            if((s[i]-'0')==(s[j]-'0')&&(s[i+1]-'0')==(s[j+1]-'0')) 
                t++; 
        if(t>maxs) { 
            maxs=t;
            x=i; 
        }
    }
    cout<<s[x]<<s[x+1];
    return 0;
}