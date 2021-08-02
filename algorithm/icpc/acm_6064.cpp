#include<iostream>
using namespace std;
long long lcm(long long f, long long s){
	long long a=f, b=s, res=0;
	while(1){
		res=a%b;
		if(res==0)	break;
		a=b;
		b=res;
	}
	return f*s/b;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long t, M, N, x, y, g, f, s, a, b, c;
	cin>>t;
	while(t--){
		cin>>M>>N>>x>>y;
		if(M>N)	f=M, s=N, a=x, b=y;
		else	f=N, s=M, a=y, b=x;
		g=lcm(f, s);
		while(a<=g){
			c=a%s;
			if(c==0)	c=s;
			if(c==b)	break;
			a+=f;
		}
		if(a>g)	cout<<-1<<"\n";
		else	cout<<a<<"\n";
	}
	return 0;
}
