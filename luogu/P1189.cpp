#include <iostream>
#include <cstring>
using namespace std;

const int dir[5][2] = {{0, 0}, {-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int n, m, k;
char map[110][110];
bool ans[110][110], vis[110][110];

void search(int num) {
	memset(vis, false, sizeof(vis));
	for (int i=1; i<=n; i++) 
		for (int j=1; j<=m; j++) 
			if (ans[i][j] && !vis[i][j]) {
				int nx = i + dir[num][0], ny = j + dir[num][1];
				ans[i][j] = false;
				while (map[nx][ny] == '.' || map[nx][ny] == '*') {
					ans[nx][ny] = true;
					vis[nx][ny] = true;
					nx = nx + dir[num][0], ny = ny + dir[num][1];
				}
			}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++) {
			cin >> map[i][j];
			if (map[i][j] == '*') ans[i][j] = true;
		}
	cin >> k;
	while (k--) {
		string str;
		cin >> str;
		if (str == "NORTH") search(1);
		if (str == "EAST") search(2);
		if (str == "SOUTH") search(3);
		if (str == "WEST") search(4);
	}
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			if (ans[i][j]) cout << "*";
			else if (map[i][j] == '*')
				cout << ".";
			else cout << map[i][j];
		}
		cout << endl;
	}
	return 0;
}