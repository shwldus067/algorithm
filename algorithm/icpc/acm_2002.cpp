#include<iostream>
#include<string>
#include<map>
using namespace std;
int N, tree[1001], out[1001];
map<string, int> car;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;++i){
		string t;
		cin>>t;
		car.insert({t, i});
	}
	for(int i=0;i<N;++i){
		string t;
		cin>>t;
		out[i]=car[t];
	}
	int ans=0;
	for(int i=0;i<N;++i){
		for(int j=i+1;j<N;++j){
			if(out[j]<out[i]){
				++ans;
				break;
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}
