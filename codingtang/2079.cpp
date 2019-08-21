/**
1234
3
2 3
3 2
3 5


9
*/

#include<iostream>
#include<queue>
#include<map>
using namespace std;

string n;
int k;
char c[16][3];
queue<string> q;
map<string,bool> m;

bool find(string s){
    if(m[s])
        return true;
    return false;
}

int bfs(){
    q.push(n);
    int ans=0;
    ans++;
    m[n]=true;
    while(!q.empty()){
        string str=q.front();
        q.pop();
        for(int i=0;i<str.size();i++){
            for(int j=1;j<=k;j++)
                if(str[i]==c[j][1]&&(i!=0||(i==0&&c[j][2]!='0'))){
                    string s;
                    s=str;
                    s[i]=c[j][2];
                    if(!find(s)){
                        q.push(s);
                        m[s]=true;
                        ans++;
                    }
                }
        }
    }
    return ans;
}

int main(){
    cin>>n>>k;
    for(int i=1;i<=k;i++)
        cin>>c[i][1]>>c[i][2];
    cout<<bfs()<<endl;
    return 0;
}
