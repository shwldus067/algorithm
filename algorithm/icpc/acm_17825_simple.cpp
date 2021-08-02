#include<iostream>
using namespace std;
struct node{
	int v, n1, n2;
};
node board[33];
int h[4], ans, arr[10];
int check(int idx, int d){
	int c=h[idx];
	if(c && !(c%5) && c<16)	c=board[c].n2;
	else	c=board[c].n1;
	--d;
	for(int i=0;i<d;++i)
		c=board[c].n1;
	if(c==32)	return 32;
	for(int i=0;i<4;++i)
		if(h[i]==c)	return 0;
	return c;
}
void dfs(int cnt, int sum){
	if(cnt>9){
		if(ans<sum)	ans=sum;
		return;
	}
	for(int i=0;i<4;++i){
		int c=h[i], n;
		if(i && !h[i-1])	break;
		n=check(i, arr[cnt]);
		if(!n)	continue;
		h[i]=n;
		dfs(cnt+1, sum+board[n].v);
		h[i]=c;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for(int i=0;i<31;++i)
		board[i]={i*2, i+1, 0};
	for(int i=5;i<16;i+=5)
		board[i].n2=18+i/5*3;
	--board[15].n2;
	for(int i=21;i<25;++i)
		board[i].v=13+(i-21)*3;
	board[23].n1=29;
	board[25]={24, 29, 0};
	for(int i=26;i<30;++i)
		board[i].v=28-i+26;
	board[30].v=30;
	board[31]={35, 20, 0};
	board[20].n1=32;
	board[32]={0, 32, 32};
	for(int i=0;i<10;++i)
		cin>>arr[i];
	dfs(0, 0);
	cout<<ans<<"\n";
	return 0;
}
