#include<iostream>
#include<algorithm>
using namespace std;
int T, N, M;
bool comp(pair<int, int> a, pair<int, int> b){
	if(a.second==b.second)	return a.first<b.first;
	return a.second<b.second;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		cin>>N>>M;
		bool ch[N+1]={false, };
		pair<int, int> book[M];
		for(int i=0;i<M;i++){
			cin>>book[i].first>>book[i].second;
		}
		sort(book, book+M, comp);
		int res=0;
		for(int i=0;i<M;i++){
			for(int j=book[i].first;j<=book[i].second;j++){
				if(!ch[j]){
					res++;
					ch[j]=true;
					break;
				}
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}
