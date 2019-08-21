#include <iostream>
using namespace std;

int n, v, w[110], f[21][200001];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> w[i];
		v += w[i];
	}
	int s = v;
	v /= 2;
	for (int i = 1; i <= n; i++) 
		for (int j = 0; j <= v; j++)
			if (j < w[i])
				f[i][j] = f[i-1][j];
			else
				f[i][j] = max(f[i-1][j], f[i-1][j-w[i]]+w[i]);
	cout << s-2*f[n][v] << endl;
	return 0;
}