#include <iostream>
using namespace std;

int n, v[2010], f[2010][2010];

int main() {
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> v[i];
		f[i][i] = v[i]*n;
	}
	for (int i=2; i<=n; i++)
		for (int l=1; l<=n; l++) {
			int r = l+i-1;
			if (r > n) break;
			f[l][r] = max(f[l][r-1] + v[r]*(n-i+1), f[l+1][r] + v[l]*(n-i+1));
		}
	cout << f[1][n] << endl;
	return 0;
}