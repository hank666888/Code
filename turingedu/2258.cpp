#include <iostream>
#include <cmath>
using namespace std;

int m, n, ans;

bool prime(int a) {
    if (a == 0 || a == 1 || a == 2)
        return false;
    for (int  i = 2; i <= sqrt(a); i++)
        if (a % i == 0)
            return false;
    return true;
}

bool check(int a) {
    int num[11], cnt = 0;
    while (a != 0) {
        num[++cnt] = a % 10;
        a /= 10;
    }
    for (int i = 1; i <= cnt; i++)
        if (num[i] != num[cnt - i + 1])
            return false;
    return true;
}

int main() {
    cin >> m >> n;
    for (int i = m; i <= n; i++) {
        if (prime(i) && check(i))
            ans++;
    }
    cout << ans << endl;
    return 0;
}
