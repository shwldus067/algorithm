#include<iostream>
using namespace std;
const int inf=~(1<<30);
int N, F;
int dr[]={-1, 0, 1, 1, 0, -1}, dc[]={1, 2, 1, -2, -2, -1};
int arr[12][22];
struct pos_{
	int r, c, k;
	pos_(int r, int c, int k):r(r), c(c), k(k){}
};
pos_ pos[100];
int cnt=0;
long long ans=0;
long long dfs(int cur, int num, int sum){
	if(num==0)	return 0;
	
	for(int i=0;i<6;++i){
		
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>F;
	for(int i=0;i<N;++i){
		int k=N-1-i;
		for(int j=0;j<(N+i)*2;j+=2){
			int t;
			cin>>t;
			arr[i][k+j]=t;
			if(t>0){
				pos[cnt++]=pos_(i, k+j, t);
			}
		}
	}
	for(int i=1;i<N;++i){
		int k=i;
		for(int j=0;j<(N+2-i)*2;j+=2){
			int t;
			cin>>t;
			arr[N-1+i][k+j]=t;
			if(t>0){
				pos[cnt++]=pos_(N-1_i, k+j, t);
			}
		}
	}
	if(cnt==N){
		for(int i=0;i<cnt;++i)
			ans+=(long long)pos[i].k;
		cout<<ans<<"\n";
		return 0;
	}
	else if(cnt==0){
		cout<<"0\n";
		return 0;
	}
	for(int i=0;i<cnt;++i){
		ans=max(ans, dfs(i, cnt, sum));
	}
	return 0;
}
