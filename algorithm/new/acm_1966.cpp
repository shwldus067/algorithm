#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int main(){
	int T, N, M, cnt, priority, idx;
	cin>>T;
	for(int t=0;t<T;t++){
		cin>>N>>M;
		int doc[N];
		queue<pair<int, int> > Q;
		for(int i=0;i<N;i++){
			cin>>doc[i];
			Q.push({doc[i], i});
		}
		sort(doc, doc+N, greater<int>());
		cnt=0;
		while(!Q.empty()){
			priority=Q.front().first;
			idx=Q.front().second;
			Q.pop();
			if(priority==doc[cnt]){
				if(idx==M){
					cout<<cnt+1<<"\n";
					break;
				}
				cnt++;
			}
			else{
				Q.push({priority, idx});
			}
		}
	}
	return 0;
}
