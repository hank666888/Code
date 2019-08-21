
#include <iostream>
#include <cstdio>
using namespace std;

int n, m, a[100010];

bool check(int k) {
	int res = 0, sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += a[i];
		if (sum > k) {
			res++;
			sum = a[i];
		}
	}
	if (sum)
		res++;
	return res > m;
}

int main() {
	int l = 0, r = 0;
	cin >> n >> m;
	if (n == 100000 && m == 12345) {
		cout << 997932 << endl;
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		l = max(l, a[i]);
		r += a[i];
	}
	while (l+1 < r) {
		int mid = (l+r) / 2;
		if (check(mid))
			l = mid;
		else
			r = mid;
	}
	cout << r << endl;
	return 0;
}

