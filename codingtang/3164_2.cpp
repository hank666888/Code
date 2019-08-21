#include <iostream>
using namespace std;

int n, f[1010][1010], a[1010][1010]; 

int main() {
	cin >> n;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=i; j++)
			cin >> a[i][j];
	for (int j=1; j<=n; j++)
		f[n][j] = a[n][j];
	for (int i=n-1; i>=1; i--)
		for (int j=1; j<=i; j++)
			f[i][j] = max(f[i+1][j], f[i+1][j+1]) + a[i][j];
	cout << f[1][1] << endl;
	return 0;
}