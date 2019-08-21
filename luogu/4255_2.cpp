#include <iostream>
using namespace std;

int n, g[100010], c[100010];

void dfs(int x,int ed) {
	if (x == ed) {
		return ;
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> g[i];
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	for (int i = 1; i <= n; i++) {
		int k = g[i];
		for (int j = 1; j <= n; j++) {
			if (i == j)
				continue;
			if (d[j] < k) {
				dfs(j, i);
			}
		}
	}
}