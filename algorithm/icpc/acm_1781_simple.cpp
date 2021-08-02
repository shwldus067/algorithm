#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
typedef pair<int, int> pii;
int N, ans=0;
pii arr[200001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>arr[i].first>>arr[i].second;
	}
	sort(arr, arr+N);
	priority_queue<int> PQ;
	for(int i=0;i<N;i++){
		PQ.push(-arr[i].second);
		while(PQ.size()>arr[i].first)	PQ.pop();
	}
	while(!PQ.empty()){
		ans-=PQ.top();
		PQ.pop();
	}
	cout<<ans<<"\n";
	return 0;
}
