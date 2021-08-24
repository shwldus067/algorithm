#include<iostream>
#include<vector>
#include<queue>
using namespace std;
bool visit[100001], chk[1000];
vector<int> vec[100001];
int H[1000][1000];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int K, M, N, size, ans=1, t;
	cin>>N>>K>>M;
	for(int i=0;i<M;++i){
		for(int j=0;j<K;++j){
			cin>>t;
			H[i][j]=t;
			vec[t].push_back(i);
		}
	}
	queue<int> Q;
	Q.push(1);
	visit[1]=1;
	while(size=Q.size()){
		while(size--){
			int cur=Q.front();
			Q.pop();
			if(cur==N){
				cout<<ans<<"\n";
				return 0;
			}
			for(int m:vec[cur]){
				if(chk[m])	continue;
				chk[m]=1;
				for(int i=0;i<K;++i){
					t=H[m][i];
					if(visit[t])	continue;
					visit[t]=1;
					Q.push(t);
				}
			}
		}
		++ans;
	}
	cout<<"-1\n";
	return 0;
}
