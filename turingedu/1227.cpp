#include <iostream>
#include <string>
using namespace std;

int n, ans;
string str;
bool flag;

int main() {
    cin >> n;
    n++;
    while(cin >> str){
        ans++;
    }
    cout << ans << endl;
    return 0;
}
