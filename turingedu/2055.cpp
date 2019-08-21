#include <iostream>
#include <cstring>
using namespace std;

int n, m;
bool G[110][110], visited[110];

void dfs(int x) {
	visited[x] = true;
	for (int i=1; i<=n; i++) {
		if (G[x][i] && !visited[i])
			dfs(i);
	}
}

int main() {
	cin >> n >> m;
	while (m--) {
		int q;
		cin >> q;
		if (q == 1) {
			int x, y;
			cin >> x >> y;
			G[x][y] = G[y][x] = true;
		}
		else {
			int s, t;
			cin >> s >> t;
			dfs(s);
			if (visited[t] == true)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
			memset(visited, false, sizeof(visited));
		}
	}
	return 0;
}