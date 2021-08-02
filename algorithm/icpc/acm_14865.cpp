#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
typedef pair<int, int> pii;
pii p[1000001], r[500000];
int ans1, ans2, idx, cnt;
bool cmp(pii &a, pii &b){
	if(a.second==b.second)	return a.first<b.first;
	return a.second<b.second;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, cnt=0, f=0;
	cin>>N;
	for(int i=0;i<N;++i){
		cin>>p[i].first>>p[i].second;
	}
	rotate(p, min_element(p, p+N, cmp), p+N);
	p[N]=p[0];
	for(int i=0;i<N;++i){
		if(p[i].second<0 && p[i+1].second>0){
			r[idx++]={p[i].first, cnt};
		}
		else if(p[i].second>0 && p[i+1].second<0){
			r[idx++]={p[i].first, cnt++};
		}
	}
	sort(r, r+idx);
	stack<pii> st;
	for(int i=0;i<idx;++i){
		int k=r[i].second;
		if(st.empty()){
			st.push({k, 0});
			ans1++;
		}
		else{
			if(st.top().first==k){
				if(!st.top().second){
					ans2++;
				}
				st.pop();
			}
			else{
				st.top().second=1;
				st.push({k, 0});
			}
		}
	}
	cout<<ans1<<" "<<ans2<<"\n";
	return 0;
}
