#include <iostream>
using namespace std;

const char c[4] = {' ', 'a', 'b', 'c'}; //定义“a,b,c“字符数组

int n;

void dfs(int step, string ans) {
	if (step == n) {
		cout << ans << endl;
		return ;
	}//边界情况，记得换行和return
	for (int i=1; i<=3; i++) dfs(step+1, ans+c[i]); //枚举三个字母
}

int main() {
	cin >> n;
	dfs(0, "");//初始时操作步数为0，答案串为空。
	return 0;//完结撒花！
}