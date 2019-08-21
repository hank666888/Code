#include <iostream>
#include <algorithm>
using namespace std;

struct people {
	int t, id;
};
people a[100010];
bool cmp(people x, people y) {
	if (x.t != y.t)
		return x.t < y.t;
	return x.id < y.id;
}

int n, ans, s[100010];
double res;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].t;
		a[i].id = i;
	}
	sort(a+1, a+1+n, cmp);
	for (int i = 1; i <= n; i++)
		cout << a[i].id << " ";
	cout << endl;
	for (int i = 2; i <= n; i++) {
		s[i] = s[i-1] + a[i - 1]. t;
		ans += s[i];
	}
	double res = ans;
	res /= n;
	printf("%.2f\n", res);
	return 0;
}