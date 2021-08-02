#include<iostream>
using namespace std;
int N, a[50001];
bool c[50001], v[50001];
bool sol(int x){
	if(x==N)	return true;
	if(v[x])	return sol(x+1);
	for(int i=-1;i<2;++i){
		if(a[x]+i>0 && !c[a[x]+i]){
			int t=x;
			for(int j=x+1;j<N;++j)if(a[j]==a[x]+i){
				t=j;break;
			}
			c[a[x]]=c[a[t]]=1;
			v[t]=1;
			swap(a[x], a[t]);
			if(sol(x+1))	return true;
			c[a[x]]=c[a[t]]=0;
			swap(a[x], a[t]);
			v[t]=0;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;++i)	cin>>a[i];
	sol(0);
	for(int i=0;i<N;++i)	cout<<a[i]<<"\n";
	return 0;
}
