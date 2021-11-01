#include<iostream>
using namespace std;
int num[1000001], stu[100000];
int cnt[1000001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, t, M=0;
	cin>>N;
	for(int i=0;i<N;++i)	cin>>t, stu[i]=t, num[t]++, M=max(M, t);
	for(int i=M;i;--i){
		if(num[i]==0)	continue;
		for(int j=1;j*j<=i;++j){
			if(i%j==0){
				cnt[i]+=num[j];
				if(j*j!=i)	cnt[i]+=num[i/j];
			}
		}
	}
	for(int i=0;i<N;++i)	cout<<cnt[stu[i]]-1<<"\n";
	return 0;
}
