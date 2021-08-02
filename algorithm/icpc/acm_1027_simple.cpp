#include<iostream>
using namespace std;
int b[50];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, a[50], ans=0;
	cin>>N;
	for(int i=0;i<N;++i)	cin>>a[i];
	for(int i=0;i<N;++i){
		double tan=-1e10, cur;
		for(int j=i+1;j<N;++j){
			cur=(double)(a[j]-a[i])/(j-i);
			if(cur>tan)	tan=cur, b[i]++, b[j]++;
		}
	}
	for(int i=0;i<N;++i)	ans=max(ans, b[i]);
	cout<<ans<<"\n";
	return 0;
}
