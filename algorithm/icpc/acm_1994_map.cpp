#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
typedef unsigned ui;
ui N, arr[2000], d[2000];
multimap<int, pair<int, int> > M;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;++i){
		cin>>arr[i];
	}
	sort(arr, arr+N);
	int ans=0;
	multimap<int, pair<int, int> >::iterator iter;
	for(int i=0;i<N-1;++i){
		for(int j=i+1;j<N;++j){
			int t=arr[j]-arr[i];
			iter=M.lower_bound(t);
			bool flag=true;
			while(iter!=M.end() && iter->first==t){
				if(iter->second.first==i){
					iter->second.first=j;
					iter->second.second+=1;
					flag=false;
				}
				iter++;
			}
			if(flag){
				M.insert(make_pair(t, make_pair(j, 1)));
			}
		}
	}
	for(iter=M.begin();iter!=M.end();iter++){
		if(ans<iter->second.second)	ans=iter->second.second;
	}
	if(ans==0)	cout<<"1\n";
	else	cout<<ans+1<<"\n";
	return 0;
}
