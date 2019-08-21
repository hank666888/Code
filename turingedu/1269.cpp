#include <iostream>
using namespace std;

int n, v, c[110], w[110], f[110][1010]; 

int main() {
	cin >> v >> n;
	for (int i = 1; i <= n; i++)
		cin >> c[i] >> w[i];
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= v; j++)
			if (c[i] <= j)
				f[i][j] = max(f[i-1][j], f[i-1][j-c[i]]+w[i]);
			else
				f[i][j] = f[i-1][j];
	cout << f[n][v] << endl;
	return 0;
}