#include <iostream>
using namespace std;

int a[3010], b[3010], n, f[3010][3010], ans;

int main() {
	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	for (int j=1; j<=n; j++)
		cin >> b[j];
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			if (a[i] == b[j]) {
				int res = 0;
				for (int k=1; k<j; k++) 
					if (b[k] < b[j]) res = max(res, f[i-1][k]);
				f[i][j] = res+1;
			}
			else f[i][j] = f[i-1][j];
		}
	}
	for (int j=1; j<=n; j++)
		ans = max(ans, f[n][j]);
	cout << ans << endl;
	return 0;
}