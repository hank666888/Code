#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n;
vector<int> a;

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
    	int x;
        cin>>x;
        a.insert(upper_bound(a.begin(),a.end(),x),x);
        if(i%2==1){
            cout<<a[(i-1)/2]<<endl;
        }
    }
    return 0;
}