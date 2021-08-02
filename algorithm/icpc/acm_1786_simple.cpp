#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
string t, p;
vector<int> res, pi;
void getpi(){
	int n=p.length();
	pi.resize(n);
	for(int i=1, j=0;i<n;++i){
		while(j && p[i]!=p[j])	j=pi[j-1];
		if(p[i]==p[j])	pi[i]=++j;
	}
}
void kmp(){
	int n=t.length(), m=p.length();
	for(int i=0, j=0;i<n;++i){
		while(j && t[i]!=p[j])	j=pi[j-1];
		if(t[i]==p[j]){
			if(++j==m){
				res.push_back(i-m+2);
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	getline(cin, t);
	getline(cin, p);
	getpi();
	kmp();
	cout<<res.size()<<"\n";
	for(int k:res){
		cout<<k<<" ";
	}
	return 0;
}
