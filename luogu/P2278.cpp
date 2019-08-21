#include<iostream>
#include<queue>
using namespace std;

struct cpu{
    int num,arrive_time,need_time,level;
    bool operator > (const cpu&a) const {
        if(arrive_time!=a.arrive_time)
            return arrive_time>a.arrive_time;
        return level<a.level;          
    }
};

priority_queue<cpu> pq;
int a,b,c,d;
int t;

void swap(cpu a,cpu b){
    cpu temp;
    temp=a;
    
}

int main(){
    while(cin>>a>>b>>c>>d!=EOF){
        pq.push((cpu){a,b,c,d});
    }
    while(!q.empty()){
        cpu now=q.top();
        q.pop();
        cpu second=q.top();
        if(t+now.need_time>second.arrive_time&&second.level>now.level){
            now.need_time-=second.arrive_time;
            
        }
    }
    
}