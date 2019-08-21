#include <iostream>
using namespace std;

int n, f[205][205];

int main() {
	cin >> n;
	f[0][0] = 1;
	for (int i=0; i<=n; i++)
		for (int j=1; j<=n; j++)
			if (i<j)
				f[i][j] = f[i][j-1];
			else
				f[i][j] = f[i-j][j-1]+f[i][j-1];
	cout << f[n][n]-1 << endl;
	return 0;
}