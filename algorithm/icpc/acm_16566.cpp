#include<iostream>
#include<algorithm>
using namespace std;
int N, M, K;
int card[4000000];
bool chk[4000001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M>>K;
	for(int i=0;i<M;++i){
		cin>>card[i];
	}
	sort(card, card+M);
	for(int i=0;i<K;++i){
		int t;
		cin>>t;
		int it=upper_bound(card, card+M, t)-card;
		while(chk[it])	it++;
		chk[it]=true;
		cout<<card[it]<<"\n";
	}
	return 0;
}
