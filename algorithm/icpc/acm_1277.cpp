#include<iostream>
#include<queue>
#include<cmath>
using namespace std;
typedef pair<double, int> pdi;
double cost[1000][1000];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, W, x[1000], y[1000];
	double M;
	int ans=0;
	cin>>N>>W>>M;
	for(int i=0;i<N;++i)	cin>>x[i]>>y[i];
	for(int i=0;i<N;++i)for(int j=0;j<N;++j)	cost[i][j]=1e9;
	if(N==1){
		cout<<"0\n";
		return 0;
	}
	int a, b;
	priority_queue<pdi> pq;
	for(int i=0;i<W;++i){
		cin>>a>>b;
		a--;b--;
		cost[a][b]=cost[b][a]=0;
	}
	for(int i=1;i<N;++i){
		if(cost[0][i]==0)	pq.push({0, i});
		else{
			int dx=x[0]-x[i], dy=y[0]-y[i];
			double dist=sqrt(1ll*dx*dx+1ll*dy*dy);
			if(dist<=M){
				pq.push({-dist, i});
				cost[0][i]=dist;
			}
		}
	}
	cost[0][0]=0;
	while(pq.size()){
		double cur=-pq.top().first;
		int k=pq.top().second;
		pq.pop();
		if(k==N-1){
			ans=(int)(cur*1000);
			break;
		}
		if(cur!=cost[0][k])	continue;
		for(int i=0;i<N;++i){
			if(k==i)	continue;
			if(cost[k][i]==0){
				if(cost[0][i]>cur){
					cost[0][i]=cur;
					pq.push({-cur, i});
				}
			}
			else{
				int dx=x[k]-x[i], dy=y[k]-y[i];
				double dist=sqrt(1ll*dx*dx+1ll*dy*dy);
				if(dist<=M && cost[0][i]>cur+dist){
					cost[0][i]=cur+dist;
					pq.push({-cost[0][i], i});
				}
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}
