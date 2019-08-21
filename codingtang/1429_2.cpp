#include<iostream>
using namespace std;

int L,A,B;
int Aans,Bans,X,Y;
bool f;
int main(){
    cin>>A>>B>>L;
    Aans=L,Bans=1;
    for(X=1;X<=L;X++)
        for(int Y=1;Y<=L;Y++)
            if(A*Y<=X*B&&Aans*Y>X*Bans){
                Aans=X;
                Bans=Y;
            }
    cout<<Aans<<" "<<Bans;
    return 0;
}
