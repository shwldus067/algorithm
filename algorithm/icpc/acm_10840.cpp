#include<iostream>
#include<cstring>
#include<vector>
#include<set>
using namespace std;
int N, M;
char A[1501], B[1501];
set<vector<int> > S;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>A>>B;
	N=strlen(A), M=strlen(B);
	int L=min(N, M), ans=0;
	for(int i=1;i<=L;++i){
		vector<int> cnt(26, 0);
		int s=0, e=i-1;
		for(int j=s;j<e;++j)	cnt[A[j]-'a']++;
		while(e<N){
			++cnt[A[e++]-'a'];
			S.insert(cnt);
			--cnt[A[s++]-'a'];
		}
	}
	for(int i=L;i>0;--i){
		vector<int> cnt(26, 0);
		int s=0, e=i-1;
		for(int j=s;j<e;++j)	cnt[B[j]-'a']++;
		while(e<M){
			++cnt[B[e++]-'a'];
			if(S.count(cnt)>0){
				cout<<i<<"\n";
				return 0;
			}
			--cnt[B[s++]-'a'];
		}
	}
	cout<<"0\n";
	return 0;
}
