#include <iostream>
#include <algorithm>
#define _for(i, a, b) for(int i=(a); i<=(b); i++)
using namespace std;

const int MAXN = 2010;

int a[MAXN], b[MAXN], n, la, lb, ra, rb, ans;

int main() {
	cin >> n;
	_for(i, 1, n) cin >> a[i];
	_for(i, 1, n) cin >> b[i];
	sort(a+1, a+1+n);
	sort(b+1, b+1+n);
	la = lb = 1, ra = rb = n;
	_for(i, 1, n) {
		if (a[ra] > b[rb]) ans += 200, ra--, rb--;
		else if (a[ra] < b[rb]) ans -= 200, la++, rb--;
		else if (a[la] > b[lb]) ans += 200, la++, lb++;
		else {
			if (a[la] < b[rb]) ans -= 200;
			la++, rb--;
		}
	}
	cout << ans << endl;
	return 0;
}