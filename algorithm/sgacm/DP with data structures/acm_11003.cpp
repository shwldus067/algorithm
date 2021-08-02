#include<iostream>
#include<deque>
using namespace std;
typedef pair<int, int> pii;
int N, L, a;
deque<pii> D;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>N>>L;
	for(int i=0;i<N;i++){
		cin>>a;
		if(D.size() && (D.front().second<=i-L))
			D.pop_front();
		while(D.size() && (D.back().first>a))
			D.pop_back();
		D.push_back({a, i});
		cout<<D.front().first<<" ";
	}
	return 0;
}
