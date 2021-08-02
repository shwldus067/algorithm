#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, C, M;
	cin>>N>>C;
	vector<int> v[C+1];
	int arr[N+1];
	for(int i=1;i<=N;++i){
		cin>>arr[i];
		v[arr[i]].push_back(i);
	}
	cin>>M;
	int a, b, sz, r;
	while(M--){
		cin>>a>>b;
		sz=b-a+1;
		int f=0;
		for(int i=0;i<17;++i){
			r=(rand()%sz)+a;
			r=arr[r];
			int cnt=upper_bound(v[r].begin(), v[r].end(), b)-lower_bound(v[r].begin(), v[r].end(), a);
			if(cnt>sz/2){
				f=r;break;
			}
		}
		if(f)	cout<<"yes "<<r<<"\n";
		else	cout<<"no\n";
	}
	return 0;
}
