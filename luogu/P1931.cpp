#include <iostream>
#include <map>
using namespace std;

const int MAXN = 31;

int n, k, t;
double dis[MAXN][MAXN];
std::map<string, int> m;

bool floyd() {
	for (int k=1; k<=n; k++)
		for (int i=1; i<=n; i++)
			for (int j=1; j<=n; j++) {
				if (dis[i][k] * dis[k][j] > dis[i][j]) {
					dis[i][j] = dis[i][k] * dis[k][j];
				}
			}
	for (int i=1; i<=n; i++)
		if (dis[i][i] > 1) return true;
	return false;

}

void init() {
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++) {
			if (i == j) dis[i][j] = 1;
			else dis[i][j] = 0;
		}
}

int main() {
	while (++t) {
		cin >> n;
		if (n == 0) break;
		init();
		m.clear();
		for (int i=1; i<=n; i++) {
			string str;
			cin >> str;
			m[str] = i;
		}
		cin >> k;
		for (int i=1; i<=k; i++) {
			string s1, s2;
			double ch;
			cin >> s1 >> ch >> s2;
			dis[m[s1]][m[s2]] = ch;
		}
		if (floyd()) cout << "Case " << t << ": Yes" << endl;
		else cout << "Case " << t << ": No" << endl;
	}
	return 0;
}