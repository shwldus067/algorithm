#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool compare(pair<int, int> a,  pair<int, int> b){
	if(a.first==b.first)	return a.second<b.second;
	return a.first<b.first;
}
int main(){
	int N, x, y;
	cin>>N;
	vector<pair<int, int> > cdn;
	for(int i=0;i<N;i++){
		cin>>x>>y;
		cdn.push_back({x, y});
	}
	sort(cdn.begin(), cdn.end(), compare);
	for(int i=0;i<N;i++){
		cout<<cdn[i].first<<" "<<cdn[i].second<<"\n";
	}
	return 0;
}
