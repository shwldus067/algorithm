#include<iostream>
#include<deque>
using namespace std;
int N, M, C, a[1000000], idx;
deque<int> mins;
deque<int> maxs;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M>>C;
	for(int i=0;i<N;++i)	cin>>a[i];
	for(int i=0;i<N;++i){
		while(mins.size() && mins.front()<=i-M)
			mins.pop_front();
		while(maxs.size() && maxs.front()<=i-M)
			maxs.pop_front();
		while(mins.size() && a[mins.back()]>=a[i])
			mins.pop_back();
		while(maxs.size() && a[maxs.back()]<=a[i])
			maxs.pop_back();
		mins.push_back(i);
		maxs.push_back(i);
		if(i>=M-1 && a[maxs.front()]-a[mins.front()]<=C)
			cout<<i-M+2<<"\n", idx=1;
	}
	if(idx==0)	cout<<"NONE\n";
	return 0;
}
