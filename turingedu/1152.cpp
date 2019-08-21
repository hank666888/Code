#include <iostream>
#include <algorithm>
using namespace std;

struct node {
	int pt, id;
};
node p[10010];
bool cmp(node a, node b) {
	if (a.pt != b.pt)
		return a.pt > b.pt;
	return a.id < b.id;
}

int n, a[10010], rk = 1;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		p[i].pt = a[i];
		p[i].id = i;
	}
	sort(p+1, p+1+n, cmp);
	for (int i = 1; i <= n; i++) {
		cout << rk << " " << p[i].id << " " << p[i].pt << endl;
		if (p[i+1].pt != p[i].pt) {
			rk = i+1;
			if (rk > 10)
				break;
		}
	}
	return 0;
}