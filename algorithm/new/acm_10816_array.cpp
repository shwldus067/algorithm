#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M, tmp;
	int *low, *high;
	cin>>N;
	int card[N];
	for(int i=0;i<N;i++){
		cin>>card[i];
	}
	sort(card, card+N);
	cin>>M;
	for(int i=0;i<M;i++){
		cin>>tmp;
		low=lower_bound(card, card+N, tmp);
		high=lower_bound(card, card+N, tmp+1);
		cout<<high-low<<" ";
	}
	cout<<"\n";
	return 0;
}
