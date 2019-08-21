#include <iostream>
#include <algorithm>
using namespace std;

struct speak{
    int st, ed, len;
};
speak a[10010];
bool cmp(speak x, speak y) {
    return x.st < y.st;
}

int n, f[10010], ans;

int main() {
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> a[i].st >> a[i].ed;
        a[i].len = a[i].ed-a[i].st;
    }
    sort(a+1, a+1+n, cmp);
    for (int i=1; i<=n; i++) {
        f[i] = a[i].len;
        for (int j=1; j<i; j++) {
            if (a[j].ed <= a[i].st && f[i] < f[j]+a[i].len)
                f[i] = f[j]+a[i].len;
        }
        ans = max(ans, f[i]);
    }
    cout << ans << endl;
    return 0;
}