#include<iostream>
using namespace std;
int N, d[62501];
int main(){
	scanf("%d", &N);
	for(int i=1;i<=250*N;++i){
		d[i]=1e9;
	}
	int sum=0;
	for(int i=0;i<N;++i){
		int x, y;
		scanf("%d %d", &x, &y);
		sum+=x;
		for(int j=sum;j>x-1;--j){
			d[j]=min(d[j], d[j-x]+y);
		}
	}
	int ans=1e9;
	for(int i=sum;i>=0;--i){
		ans=min(ans, max(sum-i, d[i]));
	}
	printf("%d\n", ans);
	return 0;
}
