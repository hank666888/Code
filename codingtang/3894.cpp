#include <iostream>
using namespace std;

int n, a[10010], f[10010], ans;

int main() {
	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	for (int i=1; i<=n; i++) {
		f[i] = max(f[i-1]+a[i], a[i]);
		ans = max(ans, f[i]);
	}
	cout << ans << endl;
	return 0;
}