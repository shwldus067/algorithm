#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, C[1001], t, mon[1001];
	char room[1001];
	vector<vector<int> > adj(1001, vector<int>());
	queue<pair<int, int> > Q;
	while(1){
		cin>>n;
		if(n==0)	break;
		adj=vector<vector<int> >(1001);
		Q=queue<pair<int, int> >();
		for(int i=1;i<=n;++i){
			cin>>room[i]>>C[i];
			while(1){
				cin>>t;
				if(t==0)	break;
				adj[i].push_back(t);
			}
			mon[i]=-1;
		}
		int money=0, fin=0;
		if(room[1]=='L')	money+=C[1];
		else if(room[1]=='T'){
			cout<<"No\n";
			continue;
		}
		mon[1]=money;
		Q.push({1, money});
		while(Q.size()){
			pair<int, int> cur=Q.front();Q.pop();
			if(cur.first==n){
				fin=1;
				break;
			}
			for(int nxt:adj[cur.first]){
				if(room[nxt]=='E'){
					if(mon[nxt]>=cur.second)	continue;
					mon[nxt]=cur.second;
					Q.push({nxt, cur.second});
				}else if(room[nxt]=='L'){
					if(mon[nxt]>=max(cur.second, C[nxt]))	continue;
					mon[nxt]=max(cur.second, C[nxt]);
					Q.push({nxt, mon[nxt]});
				}else{
					if(C[nxt]<=cur.second && mon[nxt]<cur.second-C[nxt]){
						mon[nxt]=cur.second-C[nxt];
						Q.push({nxt, mon[nxt]});
					}
				}
			}
		}
		if(fin)	cout<<"Yes\n";
		else	cout<<"No\n";
	}
	return 0;
}
