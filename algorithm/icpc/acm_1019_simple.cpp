#include<iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, cnt[10]={0, };
	cin>>N;
	int t=N, p=1;
	while(t){
		for(int i=0;i<10;++i){
			cnt[i]+=(t/10+(i?1:0))*p;
		}
		cnt[t%10]-=p-N%p-1;
		for(int i=1+t%10;i<10;++i){
			cnt[i]-=p;
		}
		p*=10;
		t/=10;
	}
	for(int i=0;i<10;++i)	cout<<cnt[i]<<" ";
	return 0;
}
