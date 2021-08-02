#include<iostream>
using namespace std;
typedef long long ll;
int n, t;
int camel[3][200000];
int order[3][200000];
int tree[200001];
ll query(int i){
	ll res=0;
	while(i>0){
		res+=tree[i];
		i-=(i&-i);
	}
	return res;
}
void update(int i){
	while(i<=n){
		tree[i]++;
		i+=(i&-i);
	}
}
ll inversion(int i, int j){
	ll res=0;
	fill(tree, tree+n+1, 0);
	for(int c=n-1;c>=0;c--){
		res+=query(camel[j][order[i][c]]);
		update(camel[j][order[i][c]]);
	}
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll cnt=0;
	cin>>n;
	for(int i=0;i<3;i++){
		for(int j=0;j<n;j++){
			cin>>order[i][j];
			order[i][j]--;
			camel[i][order[i][j]]=j+1;
		}
	}
	for(int i=0;i<2;i++)
		for(int j=i+1;j<3;j++)	cnt+=inversion(i, j);
	cout<<(ll)n*(ll)(n-1)/2-cnt/2<<"\n";
	return 0;
}
