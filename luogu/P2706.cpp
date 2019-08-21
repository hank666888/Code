#include<iostream>
using namespace std;
const int SIZE=300;
long long matrix[SIZE+1][SIZE+1];//读入的矩阵
long long rowsum[SIZE+1][SIZE+1];//每行的前缀和
long long n,m,area,ans;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            cin>>matrix[i][j];
            if(matrix[i][j]==0)
                matrix[i][j]=-1e6;
        }//读入+初始化
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            rowsum[i][j]=rowsum[i][j-1]+matrix[i][j];//统计前缀和部分
    for(int first=1;first<=m;first++)
        for(int last=first;last<=m;last++)
        {
            area=0;//记得清零！
            for(int i=1;i<=n;i++)
            {
                area+=rowsum[i][last]-rowsum[i][first-1];//统计矩阵和
                ans=max(area,ans);//更新答案
                if(area<0)
                    area=0;//记得清零！
            }
        }//计算最大子矩阵部分
    cout<<ans<<endl;//输出
    return 0;//完结撒花！
}