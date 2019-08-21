#include <iostream>
using namespace std;

int n,a[100010][3];

int ans[10];

int max_ans,max_many;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i][1]>>a[i][2];
	for(int i=1;i<=5;i++){
		int len=0;
		for(int j=1;j<=n;j++){
			if(a[j][1]==i||a[j][2]==i)
				len++;
			if(a[j][1]!=i&&a[j][2]!=i||j==n){
                ans[i]=max(ans[i],len); 
                len=0;
            }
		}
	}
	for(int i=1;i<=5;i++)
		if(ans[i]>max_many){
			max_ans=i;
			max_many=ans[i];
		}
	cout<<max_many<<" "<<max_ans<<endl;
	return 0;
}