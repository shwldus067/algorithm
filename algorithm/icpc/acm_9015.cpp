#include<iostream>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;
int T, N;
pii point[3000];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		cin>>N;
		for(int i=0;i<N;++i){
			cin>>point[i].first>>point[i].second;
		}
		sort(point, point+N);
		int ans=0;
		for(int i=0;i<N;++i){
			for(int j=i+1;j<N;++j){
				int a=point[j].first-point[i].first;
				int b=point[j].second-point[i].second;
				if(a*a+b*b<=ans)	continue;
				pii p1={-b+point[i].first, a+point[i].second};
				pii p2={a-b+point[i].first, a+b+point[i].second};
				if(binary_search(point, point+N, p1) && binary_search(point, point+N, p2)){
					ans=a*a+b*b;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
