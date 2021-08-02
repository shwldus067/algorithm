#include<iostream>
using namespace std;
int N, M, K;
long long C[201][201]={1, };
char arr[201];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M>>K;
	int s=N+M;
	for(int i=1;i<=s;++i){
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;++j){
			C[i][j]=C[i-1][j-1]+C[i-1][j];
		}
	}
	if(C[s][N]<K){
		cout<<"-1\n";
		return 0;
	}
	int n=N, m=M;
	long long cur=0;
	for(int i=0;i<s;++i){
		if(n==0){
			for(;i<s;++i){
				arr[i]='z';
			}
			break;
		}
		if(m==0){
			for(;i<s;++i){
				arr[i]='a';
			}
			break;
		}
		if(cur+C[n+m-1][n-1]>=K)	arr[i]='a', n--;
		else	arr[i]='z', m--, cur+=C[n+m][n-1]+1;
	}
	cout<<arr<<"\n";
	return 0;
}
