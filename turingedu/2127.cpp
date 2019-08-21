#include <iostream>
#include <string>
using namespace std;

int n;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++){
        long long a, ans = 0;
        while(true) {
            cin >> a;
            ans += a;
            if(cin.get() != ' ')
                break;
        }
        cout << ans << endl;
    }
    return 0;
}
