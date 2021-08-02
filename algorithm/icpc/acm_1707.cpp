#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int K, V, E, a, b, size, f;
	int chk[20001];
	vector<int> adj[20001];
	queue<int> Q;
	cin>>K;
	while(K--){
		cin>>V>>E;
		for(int i=1;i<=V;++i)	adj[i]=vector<int>(), chk[i]=2;
		while(E--){
			cin>>a>>b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		Q=queue<int>();
		f=0;
		for(int i=1;i<=V;++i){
			if(chk[i]!=2)	continue;
			Q.push(i);
			chk[i]=0;
			b=0;
			while(size=Q.size()){
				while(size--){
					a=Q.front();
					Q.pop();
					for(int c:adj[a]){
						if(chk[c]==b){
							f=1;
							break;
						}
						else if(chk[c]==2){
							chk[c]=b^1;
							Q.push(c);
						}
					}
				}
				if(f)	break;
				b^=1;
			}
			if(f)	break;
		}
		if(f)	cout<<"NO\n";
		else	cout<<"YES\n";
	}
	return 0;
}
