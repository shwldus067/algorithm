#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin>>N;
	vector<ll> vec;
	for(int i=1;i<(1<<10);++i){
		ll num=0;
		for(int j=9;j>=0;--j){
			if(i&(1<<j))	num=num*10+j;
		}
		vec.push_back(num);
	}
	sort(vec.begin(), vec.end());
	cout<<((N>vec.size())?-1:vec[N-1])<<"\n";
	return 0;
}
