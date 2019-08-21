#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int t[100010], n, s[100010], ans;

int main() {
	cin >> n; 
	for (int i = 1; i <= n; i++)
		cin >> t[i];
	sort(t+1, t+1+n);
	for (int i = 2; i <= n; i++) {
		s[i] = s[i-1] + t[i-1];
		ans += s[i];
	}
	double res = ans;
	res /= n;
	printf("%.2f\n", res);
	return 0;
}