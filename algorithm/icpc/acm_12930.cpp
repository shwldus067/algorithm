#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N, w[2][20][20];
bool chk[20][200][200];
vector<int> adj[20];
struct dij{
	int v, w1, w2, cost;
	dij(){}
	dij(int v, int w1, int w2, int cost):v(v), w1(w1), w2(w2), cost(cost){}
};
bool operator<(dij d1, dij d2){
	return d1.cost>d2.cost;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	char t;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++){
			cin>>t;
			if(t=='.')	continue;
			w[0][i][j]=t-'0';
			adj[i].push_back(j);
		}
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			cin>>t;
			if(t=='.')	continue;
			w[1][i][j]=t-'0';
		}
	}
	priority_queue<dij> pq;
	pq.push(dij(0, 0, 0, 0));
	chk[0][0][0]=1;
	dij cur;
	int v, w1, w2, cost, nv, nw1, nw2, ncost, fail=1;
	while(pq.size()){
		cur=pq.top();
		pq.pop();
		v=cur.v, w1=cur.w1, w2=cur.w2, cost=cur.cost;
		if(v==1){
			fail=0;
			break;
		}
		for(int i=0;i<adj[v].size();i++){
			nv=adj[v][i];
			nw1=w1+w[0][v][nv];
			nw2=w2+w[1][v][nv];
			ncost=nw1*nw2;
			if(chk[nv][nw1][nw2])	continue;
			pq.push(dij(nv, nw1, nw2, ncost));
			chk[nv][nw1][nw2]=1;
		}
	}
	if(fail)	cout<<"-1\n";
	else	cout<<cur.cost<<"\n";
	return 0;
}
