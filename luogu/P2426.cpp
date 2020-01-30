#include <iostream>
#include <cmath>
using namespace std;

int n, a[110], f[110][110], ans;

int main() {
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		f[i][1] = a[i];
	}
	for (int j=2; j<=n; j++)
		for (int i=1; i<=n-j+1; i++) {
			f[i][j] = j*abs(a[i]-a[i+j-1]);
			for (int k=1; k<j; k++)
				f[i][j] = max(f[i][j], f[i][k]+f[k+i][j-k]);
		}
	for (int i=1; i<=n; i++) ans = max(ans, f[i][n]);
	cout << ans << endl;
	return 0;
}