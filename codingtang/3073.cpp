#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1010,maxq=1010;

int n,q;
string book[maxn],need[maxq];
bool cmp(string a,string b){
	if(a.size()!=b.size())
		return a.size()<b.size();
	return a<b;
}

int main(){
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>book[i];
	sort(book+1,book+1+n,cmp);
	while(q--){
		int s;
		cin>>s>>need[q];
		bool fflag=false;
		for(int i=1;i<=n;i++){
			if(s<=book[i].size()){
				bool flag=false;
				for(int j=need[q].size()-1,k=book[i].size()-1;j>=0;j--,k--){
					if(book[i][k]!=need[q][j]){
						flag=true;
						break;
					}
				}
				if(!flag){
					cout<<book[i]<<endl;
					fflag=true;
					break;
				}
			}
		}
		if(!fflag)
			cout<<-1<<endl;
	} 
	return 0;
}
