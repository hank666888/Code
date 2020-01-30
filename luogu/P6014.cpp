#include <iostream>
#include <cstdio>
#define _for(i, a, b) for (int i=(a); i<=(b); i++)
#define _rep(i, a, b) for (int i=(a); i<(b); i++)
using namespace std;

const int MAXN = 1e6;

int a[MAXN], t[11], n, sum, ans;
bool flag;

int main() {
	scanf("%d", &n);
	_for (i, 1, n) {
		scanf("%d", &a[i]);
		sum += a[i];
		t[a[i]] ++;
	}
	_for (i, 1, 10) {
		_for (j, 1, 10) {
			if (i == j && t[i] >= 2 && (sum-i-j) % 10 == 0) {
				ans = (i+j)%10 == 0 ? 10 : (i+j)%10;
				flag = true;
				break;
			}
			if (i != j && t[i] >= 1 && t[j] >= 1 && (sum-i-j) % 10 == 0) {
				ans = (i+j)%10 == 0 ? 10 : (i+j)%10;
				flag = true;
				break;
			}
		}
		if (flag) break;
	}
	if (flag) cout << ans << endl;
	else cout << 0 << endl;
	return 0;
}