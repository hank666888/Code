#include <iostream>
#include <algorithm>
using namespace std;

int n, a[10010], q;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a+1, a+1+n, cmp);
	cin >> q;
	for (int i = 1; i <= n; i++)
		if (a[i] == q) {
			cout << i << endl;
			return 0;
		}
	cout << -1 << endl;
	return 0;
}