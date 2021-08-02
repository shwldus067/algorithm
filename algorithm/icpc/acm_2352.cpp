#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, s=0, t;
	cin>>n;
	int lis[n];
	int *iter;
	cin>>lis[s++];
	for(int i=1;i<n;i++){
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

