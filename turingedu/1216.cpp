#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n, k, a[1000010];

int main() {
	scanf("%d%d",&n,&k);
	for (int i=1; i<=n; i++)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	int cnt = 0;
	for (int i=1; i<=n; i++) {
		if (a[i] != a[i-1]) cnt++;
		if (cnt == k) {
			cout << a[i] << endl;
			return 0;
		}
	}
	cout << "NO RESULT" << endl;
	return 0;
}
