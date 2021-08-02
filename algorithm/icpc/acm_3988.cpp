#include<iostream>
#include<algorithm>
#include<deque>
using namespace std;
int N, K, V[1000000];
deque<int> dq;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>K;
	for(int i=0;i<N;++i)	cin>>V[i];
	sort(V, V+N);
	int M=N-K;
	int res=2e7;
	for(int i=1;i<N;++i){
		int t=V[i]-V[i-1], p=i-M+1;
		while(dq.size() && dq.front()<=p)
			dq.pop_front();
		while(dq.size() && V[dq.back()]-V[dq.back()-1]>=t)
			dq.pop_back();
		dq.push_back(i);
		if(p>=0)
			res=min(res, V[dq.front()]-V[dq.front()-1]+V[i]-V[p]);
	}
	cout<<res<<"\n";
	return 0;
}
