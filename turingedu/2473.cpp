#include <iostream>
#include <string>
using namespace std;

int n, a;

int main() {
    while(cin >> a) {
        long long ans = a;
        while(true) {
            if(cin.get() != ' ')
                break;
            cin >> a;
            ans += a;
        }
        cout << ans << endl;
    }
    return 0;
}
