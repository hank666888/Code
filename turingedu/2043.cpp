#include <iostream>
#include <algorithm>
using namespace std;

int n, k, a[100010];

bool check(int x) {
	int res = 1, last = 1;
	for (int i = 2; i <= n; i++)
		if (a[i] - a[last] >= x) {
			last = i;
			res++;
		}
	return res >= k;
}

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a+1, a+1+n);
	int l = 1, r = a[n]-a[1], mid = (l+r) / 2;
	while (l < r) {
		mid = (l+r) / 2;
		if(check(mid))
			l = mid+1;
		else
			r = mid;
	}
	cout << l-1 << endl;
	return 0;
}