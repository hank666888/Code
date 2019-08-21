#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int n, a[2510];
double f[2510];

int main() {
	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	for (int i=1; i<=n; i++)
		if (a[i] != 0)
			f[i] = f[i-1];
		else {
			f[i] = 1e9;
			for (int j=1; j<=i; j++)
				f[i] = min(f[i], f[i-j]+sqrt(j));
		}
	printf("%.3f\n", f[n]);
	return 0;
}