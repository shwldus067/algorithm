#include<iostream>
#include<vector>
using namespace std;
int N, K;
bool visit[500001][2];
vector<int> v[2];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>K;
	visit[N][0]=true;
	v[0].push_back(N);
	for(int cnt=1;K<=500000;cnt++){
		int cur=cnt&1, bef=(cnt+1)&1;
		vector<int> &vnow=v[cur], &vbef=v[bef];
		if(visit[K][bef]){
			cout<<cnt-1<<"\n";
			return 0;
		}
		K+=cnt;
		vnow.clear();
		int next, size=vbef.size(), i;
		for(i=0;i<size;i++){
			next=vbef[i];
			if(next-1>=0 && !visit[next-1][cur]){
				visit[next-1][cur]=true;
				vnow.push_back(next-1);
			}
			if(next+1<=500000 && !visit[next+1][cur]){
				visit[next+1][cur]=true;
				vnow.push_back(next+1);
			}
			if((next<<1)<=500000 && !visit[next<<1][cur]){
				visit[next<<1][cur]=true;
				vnow.push_back(next<<1);
			}
		}
	}
	cout<<"-1\n";
	return 0;
}
