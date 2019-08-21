#include<cstdio>
using namespace std;
int a=1;
int lc[110],rc[110];
char puz[110];
char parse(int& i){
    int cur=i;
    if(puz[cur]!='.') {
        i++;
        lc[cur]=parse(i);
        i++;
        rc[cur]=parse(i);
    }
    return cur;
}
void mid(int i){
    if(puz[i]=='.') return;
    mid(lc[i]);
    printf("%c",puz[i]);
    mid(rc[i]);
}
void post(int i){
    if(puz[i]=='.') return;
    post(lc[i]);
    post(rc[i]);
    printf("%c",puz[i]);
}
int main(){
    gets(puz+1);
    parse(a);
    mid(1);
    printf("\n");
    post(1);
    return 0;
}