#include<iostream>
#include<string>
#include<vector>
using namespace std;
int f[1000001], tlen, plen;
string t, p;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	getline(cin, t);
	getline(cin, p);
	tlen=t.length(), plen=p.length();
	for(int i=1, j=0;i<plen;++i){
		while(j && p[i]!=p[j])	j=f[j-1];
		if(p[i]==p[j])	f[i]=++j;
	}
	vector<int> ans;
	for(int i=0, j=0;i<tlen;++i){
		while(j && t[i]!=p[j])	j=f[j-1];
		if(t[i]==p[j]){
			if(j==plen-1){
				ans.push_back(i-plen+2);
				j=f[j];
			}
			else ++j;
		}
	}
	cout<<ans.size()<<"\n";
	for(int k:ans)	cout<<k<<" ";
	return 0;
}
