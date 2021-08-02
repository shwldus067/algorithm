#include<iostream>
using namespace std;
int n, tree[10001][2], cost[10001][2];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	int a, b, c;
	for(int i=1;i<n;++i){
		cin>>a>>b>>c;
		tree[b][0]=a;
		tree[b][1]=c;
	}
	int p, res=0;
	for(int i=n;i>1;i--){
		p=tree[i][0];
		c=tree[i][1]+cost[i][0];
		if(cost[p][0]<c){
			cost[p][1]=cost[p][0];
			cost[p][0]=c;
		}
		else if(cost[p][1]<c){
			cost[p][1]=c;
		}
		if(res<(cost[p][0]+cost[p][1]))
			res=cost[p][0]+cost[p][1];
	}
	cout<<res<<"\n";
	return 0;
}
