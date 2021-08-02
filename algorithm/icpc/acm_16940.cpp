#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N, arr[100000], idx=1;
vector<int> adj[100001];
int chk[100001];
int Q[100001], s, e=1;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=1;i<N;i++){
		int a, b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for(int i=0;i<N;i++)	cin>>arr[i];
	if(arr[0]!=1){
		cout<<"0\n";
		return 0;
	}
	Q[0]=1;
	chk[1]=1;
	int f=2;
	while(s!=e){
		int cur=Q[s++];
		int cnt=0;
		for(int next:adj[cur]){
			if(!chk[next]){
				chk[next]=f;
				cnt++;
			}
		}
		for(int i=idx;i<idx+cnt;++i){
			if(chk[arr[i]]!=f){
				cout<<"0\n";
				return 0;
			}
			else	Q[e++]=arr[i];
		}
		idx+=cnt;
		f++;
	}
	cout<<"1\n";
	return 0;
}
