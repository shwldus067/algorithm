#include<iostream>
#include<vector>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, K, v[100000];
	cin>>N>>K;
	for(int i=0;i<N;++i)	v[i]=i+K;
	vector<vector<int>> ans;
	vector<int> cnt;
	for(int i=0;i<20;++i){
		vector<int> tmp;
		int t=1<<i;
		for(int j=0;j<N;++j)if(v[j]&t)	tmp.push_back(j);
		if(tmp.size()){
			for(int j=0;j<20;++j){
				if(j==i)	continue;
				bool chk=1;
				int tp=1<<j;
				for(int k:tmp)if(!(v[k]&(1<<j))) chk=0;
				if(chk)	t+=tp;
			}
			for(int k:tmp)	v[k]-=t;
			cnt.push_back(t);
			ans.push_back(tmp);
		}
	}
	cout<<cnt.size()<<'\n';
	for(int i=0;i<ans.size();++i){
		cout<<ans[i].size()<<' '<<cnt[i]<<'\n';
		for(int j:ans[i])	cout<<j+1<<' ';
		cout<<'\n';
	}
	return 0;
}
