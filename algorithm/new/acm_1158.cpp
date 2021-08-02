#include<iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, K, cur, cnt;
	cin>>N>>K;
	bool visit[N+1]={0, };
	cout<<"<"<<K;
	cur=K;
	visit[K]=true;
	for(int i=0;i<N-1;i++){
		cnt=0;
		while(cnt!=K){
			cur=(cur+1)%N;
			if(cur==0)	cur=N;
			if(visit[cur]==false)	cnt++;
		}
		cout<<", "<<cur;
		visit[cur]=true;
	}
	cout<<">\n";
	return 0;
}
