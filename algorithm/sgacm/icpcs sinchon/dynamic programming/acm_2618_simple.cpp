#include<iostream>
using namespace std;
const int inf=~(1<<31);
int N, W, d[1002], ans[1002], to[1002];
pair<int, int> pos[1002];
int dist(int i, int j){
	if(j==W+2)	return 0;
	return abs(pos[i].first-pos[j].first)+abs(pos[i].second-pos[j].second);
}
int main(){
	scanf("%d %d", &N, &W);
	for(int i=2;i<=W+1;++i){
		scanf("%d %d", &pos[i].first, &pos[i].second);
	}
	pos[0]={1, 1}, pos[1]={N, N};
	for(int i=W-1;i>=0;--i){
		d[i]=inf;
		int sum=0, tmp;	//sum=i+1~W+1
		for(int j=i+2;j<=W+2;++j){
			if(j>i+2)	sum+=dist(j-2, j-1);
			if(d[i]>(tmp=sum+dist(i, j)+d[j-1])){
				d[i]=tmp;
				to[i]=j;
			}
		}
	}
	int car=1, ind=0;
	while(ind<W){
		ans[ind]=car;
		ans[to[ind]]=car;
		car=3-car;
		for(int i=ind+1;i<to[ind];++i){
			ans[i]=car;
		}
		ind=to[ind]-1;
	}
	printf("%d\n", d[0]);
	for(int i=2;i<=W+1;i++){
		printf("%d\n", ans[i]);
	}
	return 0;
}
