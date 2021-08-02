#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M, tmp;
	vector<int> card;
	vector<int>::iterator low;
	vector<int>::iterator high;
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>tmp;
		card.push_back(tmp);
	}
	sort(card.begin(), card.end());
	cin>>M;
	for(int i=0;i<M;i++){
		cin>>tmp;
		low=lower_bound(card.begin(), card.end(), tmp);
		high=lower_bound(card.begin(), card.end(), tmp+1);
		cout<<high-low<<" ";
	}
	cout<<"\n";
	return 0;
}
