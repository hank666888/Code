#include <iostream>
#define _for(i, a, b) for (int i=(a); i<=(b); i++)
#define _rep(i, a, b) for (int i=(a); i<(b); i++)
using namespace std;

const int MAXN = 110;

int n, m, dis[MAXN][MAXN], ans;

void floyd() {
	_for (k, 1, n)
		_for (i, 1, n)
			_for (j, 1, n) 
				dis[i][j] = dis[i][j] || dis[i][k]&&dis[k][j];
}

int main() {
	cin >> n >> m;
	_for (i, 1, m) {
		int u, v, c;
		cin >> u >> v;
		dis[u][v] = 1;
	}
	floyd();
	_for (i, 1, n) {
		int x = 1;
		_for (j, 1, n) {
			if (i == j) continue;
			x = x && (dis[i][j]||dis[j][i]);
		}
		ans += x;
	}
	cout << ans << endl;
	return 0;
}