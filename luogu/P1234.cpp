#include<iostream>
using namespace std;
int n,m;
char map[1005][1005];
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) 
            cin>>map[i][j]; 
    int ans=0;
    for(int i=1;i<=n;i++)
        for(int j=1; j<=m; j++)
        if(map[i][j]=='h') {
            if(map[i-1][j]=='e'&&map[i-2][j]=='h'&&map[i-3][j]=='e') 
                ans++; 
            if(map[i+1][j]=='e'&&map[i+2][j]=='h'&&map[i+3][j]=='e') 
                ans++; 
            if(map[i][j-1]=='e'&&map[i][j-2]=='h'&&map[i][j-3]=='e') 
                ans++; 
            if(map[i][j+1]=='e'&&map[i][j+2]=='h'&&map[i][j+3]=='e') 
                ans++; 
        }
    cout<<ans<<endl; 
    return 0;
} 