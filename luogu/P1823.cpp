#include <iostream>
#include <stack>
#include <cstdio>
using namespace std;

typedef pair<int, int> P; 

int n, h[500010];
stack<P> s;
long long ans;

int main() {
	scanf("%d", &n);
	for (int i=1; i<=n; i++) scanf("%d", &h[i]);
	for (int i=1; i<=n; i++) {
		int num = 1;
		while (!s.empty() && h[i]>=s.top().first) {
			if (h[i] == s.top().first) num+=s.top().second;
			ans+=s.top().second;
			s.pop();
		} 
		if (!s.empty()) ans++;
		s.push(P(h[i], num));
	}
	cout << ans << endl;
	return 0;
}