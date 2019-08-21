#include <iostream>
using namespace std;

int n, a[5005], f[5005], b[5005], last, ans, ans2;

int main() {
	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	for (int i=n; i>=1; i--) {
		last = 0;
		f[i] = 1;
		b[i] = 1;
		for (int j=i+1; j<=n; j++) {
			if (a[i] > a[j]) {
				if (f[j]+1 > f[i]) {
					f[i] = f[j]+1;
					b[i] = b[j];
					last = j;
				}
				else if (f[j]+1 == f[i] && a[j] != a[last]) {
					b[i] += b[j];
					last = j;
				}
			}
		}
		if (f[i] > ans) ans = f[i];
	}
	last = 0;
	for (int i=1; i<=n; i++) {
		if (f[i] == ans && a[i] != a[last]) {
			ans2 += b[i];
			last = i;
		}
	}
	cout << ans << " " << ans2 << endl;
	return 0;
}