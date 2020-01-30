#include <iostream>
#define _for(i, a, b) for(int i=(a); i<=(b); i++)
using namespace std;

const int MAXN = 100010;
int f[MAXN], n, q;

void init() {
	_for(i, 1, n) f[i] = i;
}

int find(int x) {
	if (f[x] != x) f[x] = find(f[x]);
	return f[x];
}

void unite(int x, int y) {
	x = find(x), y = find(y);
	if (x == y) return ;
	f[x] = y;
}

bool same(int x, int y) {
	return find(x) == find(y);
}

int main() {
	cin >> n >> q;
	init();
	_for(i, 1, q) {
		int k, x, y;
		cin >> k >> x >> y;
		if (!k) unite(x, y);
		else {
			if (same(x, y)) cout << "Yes\n";
			else cout << "No\n";
		}
	}
	return 0;
}