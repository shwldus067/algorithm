#include<iostream>
using namespace std;
int N, arr[1000000], ans=-1, cnt;
int check(int idx){
	int ret=0;
	for(int i=idx, j=N-1;i>=0;--i, --j){
		if(arr[i]!=arr[j])	return ret;
		ret++;
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;++i)	cin>>arr[i];
	for(int i=N-2;i>=0;--i){
		if(arr[N-1]==arr[i]){
			int tmp=check(i);
			if(ans==tmp)	cnt++;
			else if(ans<tmp){
				ans=tmp;
				cnt=1;
			}
		}
	}
	if(ans==-1)	cout<<"-1\n";
	else	cout<<ans<<" "<<cnt<<"\n";
	return 0;
}
