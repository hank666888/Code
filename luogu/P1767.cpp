#include <iostream>
#include <string>
using namespace std;

const int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int n, ans;
string str[110];
bool map[110][210];

bool cango(int x, int y) {
	return x >= 1 && x <= n && y >= 0 && y < str[x].size() && map[x][y];
}

void dfs(int x, int y) {
	for (int i=0; i<4; i++) {
		int nx = x + dir[i][0], ny = y + dir[i][1];
		if (cango(nx, ny)) {
			map[nx][ny] = false;
			dfs(nx, ny);
		}
	}
}

int main() {
	cin >> n;
	getline(cin, str[0]);
	for (int i=1; i<=n; i++) {
		getline(cin, str[i]);
		for (int j=0; j<str[i].size(); j++) 
			if (str[i][j] >= 'a' && str[i][j] <= 'z') map[i][j] = true;
	}
	for (int i=1; i<=n; i++) 
		for (int j=0; j<str[i].size(); j++)
			if (map[i][j]) {
				map[i][j] = false;
				dfs(i, j);
				ans++;
			}
	cout << ans << endl;
	return 0;
}