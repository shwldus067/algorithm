#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
	int T, N, K, X, Y, W;
	cin>>T;
	for(int t=0;t<T;t++){
		cin>>N>>K;
		int time[N+1];
		int min[N+1]={0, };
		int pre[N+1]={0, };
		vector<int> order[N+1];
		for(int n=0;n<N;n++){
			cin>>time[n+1];
		}
		for(int k=0;k<K;k++){
			cin>>X>>Y;
			pre[Y]++;
			order[X].push_back(Y);
		}
		cin>>W;
		queue<int> Q;
		for(int n=1;n<=N;n++){
			if(pre[n]==0)	Q.push(n);
		}
		while(pre[W]>0){
			int t=Q.front();
			Q.pop();
			for(int n=0;n<order[t].size();n++){
				int next=order[t][n];
				min[next]=min[next]>min[t]+time[t] ? min[next]:min[t]+time[t];
				pre[next]--;
				if(pre[next]==0)	Q.push(next);
			}
		}
		
		cout<<min[W]+time[W]<<"\n";
	}
}
