#include <iostream>
using namespace std;

int n, s[10010], a[10010], ans = -1e9;

int main() {
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		a[i+n] = a[i];
	}
	for (int i=1; i<=2*n; i++)
		s[i] = s[i-1]+a[i];
	for (int i=0; i<=n-1; i++)
		for (int j=i+1; j<=i+n; j++)
			ans = max(ans, s[j]-s[i]);
	cout << ans << endl;
	return 0;
}