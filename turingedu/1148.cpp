#include <iostream>
#include <algorithm>
using namespace std;

struct node {
	int l, r, num;
};
node a[1000010];
bool cmp(node a, node b) {
	if (a.l != b.l)
		return a.l > b.l;
	if (a.r != b.r)
		return a.r < b.r;
	return a.num > b.num;
}

int n;

int main() {
	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i].l >> a[i].r >> a[i].num;
	sort(a+1, a+1+n, cmp);
	cout << a[1].num << endl;
	return 0;
}