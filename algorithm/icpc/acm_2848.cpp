#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
int N, res, ind[26], cnt, idx;
char a[2][16], ans[28];
bool chk[26];
vector<int> adj[26];
queue<int> Q;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	int t=1;
	cin>>a[0];
	for(int k=0;k<strlen(a[0]);++k){
		chk[a[0][k]-'a']=true;
	}
	--N;
	while(N--){
		cin>>a[t];
		int i, l=strlen(a[t]), m=strlen(a[t^1]);
		for(i=0;i<l;++i){
			chk[a[t][i]-'a']=true;
		}
		int n=min(l, m);
		for(i=0;i<n;++i){
			if(a[0][i]!=a[1][i]){
				adj[a[t^1][i]-'a'].push_back(a[t][i]-'a');
				ind[a[t][i]-'a']++;
				break;
			}
		}
		if(i==n && l<m)	res=1;
		t^=1;
	}
	if(res==1){
		cout<<"!\n";
		return 0;
	}
	for(int k=0;k<26;++k){
		if(chk[k]){
			if(ind[k]==0)	Q.push(k);
			cnt++;
		}
	}
	while(Q.size()){
		if(Q.size()>1)	res=1;
		int cur=Q.front();
		Q.pop();
		ans[idx++]=cur+'a';
		for(int x:adj[cur]){
			if(--ind[x]==0){
				Q.push(x);
			}
		}
	}
	if(idx<cnt)	cout<<"!\n";
	else if(res==1)	cout<<"?\n";
	else{
		cout<<ans<<"\n";
	}
	return 0;
}
