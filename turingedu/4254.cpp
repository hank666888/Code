#include <iostream>
#include <algorithm>
using namespace std;

struct node{
	int x, y;
};
node a[100010];
bool cmp(node m, node n) {
	if (m.x != n.x)
		return m.x <= n.x;
	return m.y <= n.y;
}

int n, ans = 0;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i].x >> a[i].y;
	sort(a+1, a+1+n, cmp);
	int last = 1;
	for (int i = 2; i <= n; i++) {
		if (a[last].y > a[i].x) {
			if (a[last].y >= a[i].y)
				last = i;
			++ans;
		}
		else {
			last = i;
		}
	}
	cout << ans << endl;
	return 0;
}