#include<iostream>
using namespace std;

int main(){
	int N, K, cnt, tmp;
	cin>>N>>K;
	int cost[N];
	for(int i=0;i<N;i++){
		cin>>cost[i];
	}
	tmp=K;
	cnt=0;
	for(int i=N-1;i>=0;i--){
		if(cost[i]>tmp)	continue;
		int j=1;
		while(cost[i]*j<=tmp){
			j++;
		}
		j--;
		cnt+=j;
		tmp-=cost[i]*j;
	}
	cout<<cnt;
	return 0;
}
