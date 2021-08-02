#include<iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, arr[50], ans=0, res;
	long long dx, dy, ddx, ddy;
	cin>>N;
	for(int i=0;i<N;++i)	cin>>arr[i];
	for(int i=0;i<N;++i){
		res=0;
		dx=1, dy=1e10;
		for(int j=i-1;j>=0;--j){
			ddx=i-j, ddy=arr[i]-arr[j];
			if(dy*ddx>ddy*dx){
				dx=ddx, dy=ddy;
				++res;
			}
		}
		dx=1, dy=-1e10;
		for(int j=i+1;j<N;++j){
			ddx=j-i, ddy=arr[j]-arr[i];
			if(dy*ddx<ddy*dx){
				dx=ddx, dy=ddy;
				++res;
			}
		}
		ans=max(ans, res);
	}
	cout<<ans<<"\n";
	return 0;
}
