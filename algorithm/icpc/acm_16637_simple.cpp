#include<iostream>
using namespace std;
int N, ans=-(1<<31);
char exp[20];
int cal(int a, int b, char o){
	if(o=='+')	return a+b;
	if(o=='-')	return a-b;
	if(o=='*')	return a*b;
}
void sol(int k, int t){
	if(k<N-1){
		sol(k+2, cal(t, exp[k+2], exp[k+1]));
		if(k+4<=N-1)
			sol(k+4, cal(t, cal(exp[k+2], exp[k+4], exp[k+3]), exp[k+1]));
	}
	else{
		if(ans<t)	ans=t;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	cin>>exp;
	for(int i=0;i<N;i+=2){
		exp[i]=exp[i]-'0';
	}
	sol(0, exp[0]);
	cout<<ans<<"\n";
	return 0;
}
