#include<iostream>
#include<vector>
using namespace std;
int find(int i, vector<int> &p){
	return i==p[i] ? i:p[i]=find(p[i], p);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		int N, M;
		cin>>N>>M;
		vector<int> p(N);
		for(int i=0;i<N;++i)	p[i]=i;
		bool chk[N]={0, };
		while(M--){
			int a, b;
			cin>>a>>b;
			a--, b--;
			chk[b]=true;
			p[find(a, p)]=find(b, p);
		}
		vector<vector<int> > des(N);
		for(int i=0;i<N;++i){
			des[find(i, p)].push_back(i);
		}
		int ans=0;
		for(int i=0;i<N;++i){
			if(des[i].empty())	continue;
			int cnt=0;
			for(int n:des[i]){
				if(!chk[n])	cnt++;
			}
			ans+=max(1, cnt);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
