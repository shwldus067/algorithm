#include<iostream>
using namespace std;
const int inf=~(1<<31);
int N, W, d[1002][1002], pos[1002];
int dis(int pre, int cur){
	int dr=pre/10000-cur/10000;
	if(dr<0)	dr=-dr;
	int dc=pre%10000-cur%10000;
	if(dc<0)	dc=-dc;
	return dr+dc;
}
int sol(int c1, int c2){
	int cur=c1>c2 ? c1:c2;
	int &ret=d[c1][c2];
	if(cur==W+1)	return ret=0;
	if(ret!=-1)	return ret;
	int f=sol(cur+1, c2)+dis(pos[c1], pos[cur+1]);
	int s=sol(c1, cur+1)+dis(pos[c2], pos[cur+1]);
	return ret=min(f, s);
}
void print(int c1, int c2){
	int cur=c1>c2 ? c1:c2;
	if(cur==W+1)	return;
	int f=d[cur+1][c2]+dis(pos[c1], pos[cur+1]);
	if(f==d[c1][c2]){
		cout<<"1\n";
		print(cur+1, c2);
	}
	else{
		cout<<"2\n";
		print(c1, cur+1);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>W;
	int a, b;
	pos[0]=10001, pos[1]=10000*N+N;
	for(int i=2;i<=W+1;++i){
		cin>>a>>b;
		pos[i]=10000*a+b;
	}
	fill(&d[0][0], &d[W+1][W+2], -1);
	cout<<sol(0, 1)<<"\n";
	print(0, 1);
	return 0;
}
