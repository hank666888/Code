#include<iostream>
#include<stack>
using namespace std;

int train[1010];
stack<int> s;

int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>train[i];
	int j=1;
	for(int i=1;i<=n;i++){
		s.push(i);
		if(train[j]==s.top()){
			while(train[j]==s.top()&&j<n&&!s.empty()){
				s.pop(); 
				j++;
				if(s.empty())
					break;
			}
			if(s.empty()){
				cout<<"YES"<<endl;
				return 0; 
			}
		}
	}
	while(!s.empty()){
		if(s.top()!=train[j]){
			cout<<"NO\n";
			return 0;
		}
		s.pop();
		j++;
	}
	cout<<"YES\n";
	return 0;
}
