#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<functional>
using namespace std;
typedef vector<pair<int, int> > vii;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, K, a, b, s;
	long long res=0;
	cin>>N>>K;
	multiset<int> C;
	vii jw(N);
	for(int i=0;i<N;i++){
		cin>>a>>b;
		jw[i]=make_pair(b, a);
	}
	sort(jw.begin(), jw.end(), greater<pair<int, int> >());
	while(K--){
		cin>>a;
		C.insert(a);
	}
	multiset<int>::iterator iter;
	for(int i=0;i<N;i++){
		iter=C.lower_bound(jw[i].second);
		if(iter!=C.end()){
			res+=jw[i].first;
			C.erase(iter);
		}
	}
	cout<<res<<"\n";
	return 0;
}
