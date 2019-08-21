#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 1e9;

struct node {
	int x, s;
};
node a[400010];
bool cmp(node a, node b) {
	return a.x < b.x;
}

int n, ans, first[800010], s[400010];
char c;


int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].x >> c;
		if (c == 'B') 
			a[i].s = 1;		
		else
			a[i].s = -1;
	}
	sort(a+1, a+1+n, cmp);
	for (int i = 1; i <= n; i++) s[i] = s[i-1] + a[i].s;
	for (int i = 1; i <= n; i++)
		if (first[s[i] + 400000] == 0)
			first[s[i] + 400000] = i;
	first[400000] = 0;
	a[n+1].x = INF;
	for (int i = 2; i <= n; i++)
		ans = max(ans, a[i].x - a[first[ s[i] + 400000 ] + 1].x);
	int start = 1;
	for (int i = 2; i <= n; i++) {
		if (a[i-1].s != a[i].s) {
			ans = max(ans, a[i-1].x - a[start].x);
			start = i;
		}
	}
	ans = max(ans, a[n].x - a[start].x);
	cout << ans << endl;
	return 0;
}