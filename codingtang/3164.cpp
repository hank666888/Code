#include <iostream>
using namespace std;

int n, a[1010][1010], f[1010];

int main() {
	cin >> n;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=i; j++)
			cin >> a[i][j];
	for (int j=1; j<=n; j++)
		f[j] = a[n][j];
	for (int i=n-1; i>=1; i--)
		for (int j=1; j<=i; j++)
			f[j] = max(f[j], f[j+1]) + a[i][j];
	cout << f[1] << endl;
	return 0;
}