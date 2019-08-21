#include <iostream>
using namespace std;

int n, c[25], f[35][100005], sum;

int main() {
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> c[i];
		sum += c[i];
	}
	for (int i=1; i<=n; i++)
		for (int j=0; j<=sum/2; j++)
			if (j >= c[i])
				f[i][j] = max(f[i-1][j], f[i-1][j-c[i]]+c[i]);
			else
				f[i][j] = f[i-1][j];
	cout << sum-2*f[n][sum/2] << endl;
	return 0;
}