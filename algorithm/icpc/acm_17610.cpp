#include<iostream>
using namespace std;
bool chk[2600001];
int k, g[15];
int dd[3]={-1, 0, 1}, cnt=0;
void sol(int idx, int sum){
	if(idx==k){
		if(sum>0 && !chk[sum]){
			chk[sum]=1;
			cnt++;
		}
		return;
	}
	for(int i=0;i<3;++i){
		sol(idx+1, sum+dd[i]*g[idx]);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int Sum=0;
	cin>>k;
	for(int i=0;i<k;++i)	cin>>g[i], Sum+=g[i];
	sol(0, 0);
	cout<<Sum-cnt<<"\n";
	return 0;
}
