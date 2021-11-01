#include<iostream>
#include<vector>
using namespace std;
int cnt[100001], in[100001];
vector<int> nxt[100001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M, K, X, Y;
	cin>>N>>M>>K;
	while(M--){
		cin>>X>>Y;
		nxt[X].push_back(Y);
		in[Y]++;
	}
	while(K--){
		cin>>X>>Y;
		if(X==1){
			if(in[Y]>0){
				cout<<"Lier!\n";
				return 0;
			}
			cnt[Y]++;
			for(int v:nxt[Y]){
				in[v]--;
			}
		}else{
			if(cnt[Y]<=0){
				cout<<"Lier!\n";
				return 0;
			}
			cnt[Y]--;
			for(int v:nxt[Y]){
				in[v]++;
			}
		}
	}
	cout<<"King-God-Emperor\n";
	return 0;
}
