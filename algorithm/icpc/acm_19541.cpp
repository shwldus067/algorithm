#include<iostream>
#include<vector>
using namespace std;
bool inf[100001], chk[100001], res[100001];
vector<int> gr[100000];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M, k;
	cin>>N>>M;
	for(int i=0;i<M;++i){
		cin>>k;gr[i].resize(k);
		for(int &j:gr[i]){
			cin>>j;
		}
	}
	for(int i=1;i<=N;++i)	cin>>inf[i], chk[i]=inf[i];
	int ans=1, f;
	for(int i=M-1;i>=0;--i){
		f=0;
		for(int j:gr[i]){
			if(!chk[j]){
				f=1;break;
			}
		}
		if(f){
			for(int j:gr[i]){
				chk[j]=0;
			}
		}
	}
	for(int i=1;i<=N;++i)	res[i]=chk[i];
	for(int i=0;i<M;++i){
		f=0;
		for(int j:gr[i]){
			if(chk[j]){
				f=1;break;
			}
		}
		if(f){
			for(int j:gr[i]){
				chk[j]=1;
			}
		}
	}
	for(int i=1;i<=N;++i){
		if(chk[i]!=inf[i]){
			ans=0;break;
		}
	}
	if(ans){
		cout<<"YES\n";
		for(int i=1;i<=N;++i)	cout<<res[i]<<" ";
		cout<<"\n";
	}
	else	cout<<"NO\n";
	return 0;
}
