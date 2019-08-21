#include <iostream>
#include <algorithm>
using namespace std;

int n, a[10010], q;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	int k;
	cin >> n;
	cin >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a+1, a+1+n, cmp);
	while(k--) {
		cin >> q;
		int rk, same = 1;
		bool flag = false;
		for (int i = 1; i <= n; i++) {
			if (flag && a[i] == a[rk])
				same++;
			if (a[i] == q && !flag) {
				rk = i;
				flag = true;
			}
		}
		if (!flag)
			cout << "fail" << endl;
		else
			cout << rk << " " << same << endl;
	}
	return 0;
}