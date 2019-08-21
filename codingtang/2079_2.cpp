#include<iostream>
#include<set>
#include<queue>
using namespace std;

struct change{
    char s,e;
};

change a[20];
queue<string> q;
string n;
int k;

set<string> st;

int bfs(){
    q.push(n);
    st.insert(n);
    int ans=1;
    while(!q.empty()){
        string s=q.front();
        q.pop();
        for(int i=0;i<s.size();i++){
            for(int j=1;j<=k;j++){
                if(s[i]==a[j].s){
                    s[i]=a[j].e;
                    if(!st.count(s)){
                        q.push(s);
                        st.insert(s);
                        ans++;
                    }
                    s[i]=a[j].s;
                }
            }
        }
    }
    return ans;
}

int main(){
    cin>>n>>k;
    for(int i=1;i<=k;i++)
        cin>>a[i].s>>a[i].e;
    cout<<bfs()<<endl;
    return 0;
}
