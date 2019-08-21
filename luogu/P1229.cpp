#include <iostream>
#include <string>
using namespace std;

string s1,s2;

long long ans;

int main(){
	cin>>s1>>s2;
	for(int i=0;i<s1.size()-1;i++){
		for(int j=0;j<s2.size();j++){
			if (s1[i]==s2[j]&&s1[i+1]==s2[j-1])
			{
				ans++;
			}
		}
	}
	cout<<(1<<ans);
	return 0;
}