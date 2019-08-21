#include<iostream>
#include<string>
using namespace std;

int sum_g[1000010],sum_r[1000010];

string str;

int ans;

int main(){
    cin>>str;
    for(int i=0;i<str.size();i++){
    	if(str[i]=='G'){
    		sum_r[i+1]=sum_r[i];
    		sum_g[i+1]=sum_g[i]+1;
    	}
    	else{
    		sum_r[i+1]=sum_r[i]+1;
    		sum_g[i+1]=sum_g[i];
    	}
    }
    for(int i=0;i<str.size();i++){
    	if(ans>str.size()-i)
    		break;
    	for(int j=str.size();j>=1;j--){
    		if(sum_g[j]-sum_g[i]==sum_r[j]-sum_r[i]){
    			ans=max(ans,j-i);
    			break;
    		}
    	}
    }
    cout<<ans<<endl;
    return 0;
}