#include<iostream>
using namespace std;

int m, n, a[50];

int main() {
	cin >> m >> n;
	for(int i=1; i<=m; i++)
		cin >> a[i];
	int ans = 0, i = 1, c = 1;
	while(c <= n){
		if (i <= m && a[i] <= c)
			c += a[i++];
		else {
			c += c;
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}