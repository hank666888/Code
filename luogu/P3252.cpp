#include <iostream>
#include <vector>
using namespace std;

struct node
{
	int data;
	vector<int> son;//题面中并没说该树是什么类型的树，有可能会有多个孩子
					//且如果用数组开的话，空间会爆炸
					//故使用不定长数组vector存储孩子节点信息
};

int n;

int s;

node tree[100010];

int ans;

void dfs(int id,int sum){//id指当前节点的编号，sum指到当前节点所枚举的路径的和
	if(sum>s)
		return ;//上文所述的剪枝
	if(sum==s){
		ans++;
		return ;
	}//如果等于s,说明存在这样的路径,ans++,并返回
	if(id==0)
		return ;//如果当前节点为空，返回
	for(int i=0;i<tree[id].son.size();i++){//枚举孩子节点
		dfs(tree[id].son[i],sum+tree[tree[id].son[i]].data);//往下搜
	}
}

int main(){
	cin>>n>>s;
	for(int i=1;i<=n;i++){
		cin>>tree[i].data;
	}//输入树上节点的信息
	for(int i=1;i<=n-1;i++){
		int x,y;
		cin>>x>>y;
		tree[x].son.push_back(y);
	}//存储这棵树的信息
	for(int i=1;i<=n;i++){
		dfs(i,tree[i].data);
	}//每个节点枚举着搜
	cout<<ans<<endl;//输出答案
	return 0;//完结撒花
}