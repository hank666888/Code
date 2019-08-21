#include<iostream>
using namespace std;

int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};

int ans;

bool rn(int y){
	if(y%4==0&&y%100!=0||y%400==0)
		return true;
	return false;
}

struct date{
	int y,m,d;
	bool operator <= (date x) const {
		if(y!=x.y)
			return y<x.y;
		if(m!=x.m)
			return m<x.m;
		if(d!=x.d)
			return d<x.d;
		return true;
	}
	
	bool operator >= (date x) const {
		if(y!=x.y)
			return y>x.y;
		if(m!=x.m)
			return m>x.m;
		if(d!=x.d)
			return d>x.d;
		return true;
	}
	
	bool is_valid(){
		if(m<1||m>12)
			return false;
		if(rn(y))
			month[1]=29;
		if(d<1||d>month[m-1])
			return false;
		return true;
	}
};

date d_s,d_e,d_crt;

//根据年份y,生成回文date 
date gen(int y){
	date d;
	d.y=y;
	int r_y=0;
	while(y>0){
		r_y=r_y*10+y%10;
		y/=10;
	}
	d.m=r_y/100;
	d.d=r_y%100;
	return d;
} 

int main(){
	int s,e;
	cin>>s>>e;
	d_s.y=s/10000;
	d_s.m=s%10000/100;
	d_s.d=s%100;
	d_e.y=e/10000;
	d_e.m=e%10000/100;
	d_e.d=e%100; 
	d_crt=gen(d_s.y);
	while(d_crt<=d_e){
		if(d_crt.is_valid()&&d_crt>=d_s)
			ans++;
		d_crt=gen(d_crt.y+1); 
	}
	cout<<ans<<endl;
	return 0;
}
