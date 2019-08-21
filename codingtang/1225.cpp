#include <iostream>
using namespace std;

int n, a[10010], f[10010], ans;

int main() {
	while (cin >> n) {
		for (int i=1; i<=n; i++)
			cin >> a[i];
		for (int i=1; i<=n; i++)
			f[i] = 1;
		for (int i=2; i<=n; i++) {
			for (int j=1; j<i; j++)
				if (a[i] > a[j] && f[j]+1 > f[i])
					f[i] = f[j]+1;
			ans = max(ans, f[i]);
		}
		if (n == 1)
			ans = 1;
		cout << ans << endl;
		ans = 0;
	}
	return 0;
}