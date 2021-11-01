#include<iostream>
#include<cstring>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	char str[51], word[50][51];
	int cnt[50][26]={0, }, len[50], dp[50];
	int N, M;
	cin>>str;
	cin>>N;
	for(int i=0;i<N;++i){
		cin>>word[i];
		len[i]=strlen(word[i]);
		for(int j=len[i]-1;j>=0;--j){
			cnt[i][word[i][j]-'a']++;
		}
	}
	M=strlen(str);
	for(int i=0;i<M;++i)	dp[i]=100;
	for(int i=0;i<M;++i){
		int acnt[50]={0, };
		for(int j=i;j>=0;--j){
			acnt[str[j]-'a']++;
			for(int w=0;w<N;++w){
				int f=1;
				for(int k=0;k<26;++k){
					if(cnt[w][k]!=acnt[k]){
						f=0;break;
					}
				}
				if(f && (j==0 || dp[j-1]!=100)){
					int cost=0;
					for(int l=0;l<len[w];++l){
						if(str[j+l]!=word[w][l])	++cost;
					}
					if(j==0)	dp[i]=min(dp[i], cost);
					else	dp[i]=min(dp[i], dp[j-1]+cost);
				}
			}
		}
	}
	if(dp[M-1]==100)	cout<<"-1\n";
	else	cout<<dp[M-1]<<"\n";
	return 0;
}
