#include <iostream>
using namespace std;

int n, a[1010][1010], s[1010][1010], ans;

int main() {
	cin >> n;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			cin >> a[i][j];
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			s[i][j] = s[i-1][j]+a[i][j];
	for (int i=1; i<=n; i++)
		for (int j=i; j<=n; j++) {
			int res = 0;
			for (int k=1; k<=n; k++) {
				if (res < 0) res = 0;
				res += s[j][k] - s[i-1][k];
				ans = max(ans, res);
			}
		}
	cout << ans << endl;
	return 0;
}