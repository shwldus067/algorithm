#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
const int mod=9999991;
int T, N, tree[21][2], cnt[21][2], root;
ll c[21][21]={1, };
void bintree(int x, int y){
	if(x>y){
		cnt[x][0]++;
		if(tree[x][0])	bintree(tree[x][0], y);
		else	tree[x][0]=y;
	}
	else{
		cnt[x][1]++;
		if(tree[x][1])	bintree(tree[x][1], y);
		else	tree[x][1]=y;
	}
}
ll sol(int cur){
	ll l=1, r=1;
	if(tree[cur][0])	l=sol(tree[cur][0]);
	if(tree[cur][1])	r=sol(tree[cur][1]);
	return c[cnt[cur][0]+cnt[cur][1]][cnt[cur][1]]*l%mod*r%mod;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for(int i=1;i<21;++i){
		for(int j=0;j<=i;++j){
			if(i==j || j==0)	c[i][j]=1;
			else	c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
		}
	}
	cin>>T;
	while(T--){
		cin>>N;
		for(int i=1;i<=N;++i){
			for(int j=0;j<2;++j){
				tree[i][j]=cnt[i][j]=0;
			}
		}
		cin>>root;
		for(int i=1;i<N;++i){
			int t;
			cin>>t;
			bintree(root, t);
		}
		cout<<sol(root)<<"\n";
	}
	return 0;
}
