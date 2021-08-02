#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	vector<string> par, com;
	cin>>N;
	string t;
	for(int i=0;i<N;++i){
		cin>>t;
		par.push_back(t);
	}
	for(int i=1;i<N;++i){
		cin>>t;
		com.push_back(t);
	}
	sort(par.begin(), par.end());
	sort(com.begin(), com.end());
	for(int i=0;i<N-1;++i){
		if(par[i]!=com[i]){
			cout<<par[i]<<"\n";
			return 0;
		}
	}
	cout<<par[N-1]<<"\n";
	return 0;
}
