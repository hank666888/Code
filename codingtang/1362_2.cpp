#include<iostream>
#include<queue>
#include<vector>
using namespace std;
const int MAXN=100000+10;
queue<int> q;
int n,t[MAXN+10],k[MAXN+10],num[MAXN+10];
vector<int> x[MAXN+10];
int ans;

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>t[i]>>k[i];
        for(int j=1;j<=k[i];j++){
            int tmp;
            cin>>tmp;
            x[i].push_back(tmp);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k[i];j++){
            if(!num[x[i][j-1]])
                ans++;
            num[x[i][j-1]]++;
        }
        q.push(i);
        while(!q.empty()){
            int j=q.front();
            if(t[i]-t[j]>=86400){
                for(int l=1;l<=k[j];l++){
                    num[x[j][l-1]]--;
                    if(num[x[j][l-1]]==0)
                        ans--;
                }
                q.pop();
            }
            else
                break;
        }
        cout<<ans<<endl;
    }
    return 0;
}
