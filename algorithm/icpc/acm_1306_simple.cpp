#include<iostream>
#include<deque>
using namespace std;
int N, M;
deque<pair<int, int> > dq;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	M=2*M-2;
	for(int i=0;i<N;++i){
		int x;
		cin>>x;
		while(dq.size() && (dq.front().first<i-M))
			dq.pop_front();
		while(dq.size() && (dq.back().second<=x))
			dq.pop_back();
		dq.push_back({i, x});
		if(i>=M)	cout<<dq.front().second<<" ";
	}
	return 0;
}
