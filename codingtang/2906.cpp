#include<iostream>
#include<string>
#include<cstring>
using namespace std;

string s,s2,str;

bool is_letter(char c){
	if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))
		return true;
	return false;
}

bool no[1010]; 
int n;

int main(){
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(is_letter(s[i]))
			s2+=s[i];
	for(int i=0;i<n-1;i++)
		if(!no[i])
			for(int j=i+1;j<n;j++)
				if(s2[j]==s2[i])
					no[i]=true;
	for(int i=0;i<n;i++)
		if(!no[i])
			str+=s2[i];
	for(int i=0;i<str.size();i++)
		if(str[i]>='A'&&str[i]<='Z')
			str[i]+=32;	 
	for(int i=0;i<str.size();i++){
		if(str[i]>='b'&&str[i]<='z')
			str[i]--;
		else
			str[i]='z';
	}
	cout<<str<<endl;
	return 0; 
} 
