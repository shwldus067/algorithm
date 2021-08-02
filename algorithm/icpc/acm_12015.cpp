#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, s=0, t;
	cin>>N;
	int lis[N];
	int *iter;
	cin>>lis[s++];
	for(int i=1;i<N;i++){
		cin>>t;
		if(lis[s-1]<t)	lis[s++]=t;
		else{
			iter=lower_bound(lis, lis+s, t);
			*iter=t;
		}
	}
	cout<<s<<"\n";
	return 0;
}
