#include <iostream>
#include <cstring>
using namespace std;

const int dir[4][2] = {{-1, 0}, {0, 1}, {0, -1}, {1, 0}};

int n, m, p[1010][1010], max_c;
bool vis[1010][1010], flag;

bool cango(int x, int y, int k) {
	return x >= 1 && x <= n && y >= 1 && y <= m && !vis[x][y] && p[x][y] <= k;
}

void dfs(int x, int y, int k) {
	if (x == n) {
		flag = true;
		return ;
	}
	for (int i=0; i<4; i++) {
		int nx = x + dir[i][0], ny = y + dir[i][1];
		if (cango(nx, ny, k)) {
			vis[nx][ny] = true;
			dfs(nx, ny, k);
		}
	} 
}

bool check(int mid) {
	memset(vis, false, sizeof(vis));
	flag = false;
	dfs(1, 1, mid);
	return flag;
}

int main() {
	cin >> n >> m;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++) {
			cin >> p[i][j];
			max_c = max(max_c, p[i][j]);
		}
	int l = 0, r = max_c;
	while(l <= r) {
		int mid = (l + r) / 2;
		if (check(mid)) r = mid - 1;
		else l = mid + 1;
	}
	cout << l << endl;
	return 0;
}