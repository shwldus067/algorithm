#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int> > vii;
void update(vi& t, int i){
	while(i<t.size()){
		t[i]+=1;
		i+=(i&-i);
	}
}
int sum(vi& t, int i){
	int res=0;
	while(i>0){
		res+=t[i];
		i-=(i&-i);
	}
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, i, k;
	cin>>N;
	vii arr(N);
	int A[N];
	for(int i=0;i<N;i++){
		cin>>arr[i].first;
		arr[i].second=i;
	}
	sort(arr.begin(), arr.end());
	for(int i=0;i<N;i++){
		A[arr[i].second]=i+1;
	}
	vi fw(N+1, 0);
	for(i=0;i<N;i++){
		cout<<i+1-sum(fw, A[i])<<"\n";
		update(fw, A[i]);
	}
	return 0;
}
