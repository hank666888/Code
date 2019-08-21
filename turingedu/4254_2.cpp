#include <iostream>
#include <algorithm>
using namespace std;
int n;
struct node {
int a, b;
} intervals[550];
bool cmp(node a,node b){
	if(a.a!=b.a)
		return a.a<=b.a;
	else
		return a.b<=b.b;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin >> intervals[i].a >> intervals[i].b;
	int res = 0,last = 1;
	sort(intervals+1, intervals+n+1, cmp);
	for(int i=2;i<=n;i++){
		if(intervals[i].a < intervals[last].b){
			++res;
			if(intervals[i].b<=intervals[last].b) last = i;
		}
		else
			last = i;
	}
	cout << res;
	return 0;
}