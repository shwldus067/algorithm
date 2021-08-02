#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N;
int A[1000001];
int p[1000001];
vector<int> v;
vector<int> ans;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=1;i<=N;++i)	cin>>A[i];
	v.push_back(A[1]);
	int idx = 0;
	for(int i=2;i<=N;++i){
		if(v[idx]<A[i]){
			v.push_back(A[i]);
			p[i]=++idx;
		}
		else{
			int pos=lower_bound(v.begin(), v.end(), A[i])-v.begin();
			v[pos]=A[i];
			p[i]=pos;
		}
	}
	cout<<idx+1<<"\n";
	for(int i=N;i>=1 && idx>=0;i--) {
		if(p[i]==idx) {
			ans.push_back(A[i]);
			idx--;
		}
	}
	for(int i=ans.size()-1;i>=0;i--) {
		cout<<ans[i]<<" ";
	}
	return 0;
}
