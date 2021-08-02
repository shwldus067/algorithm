#include<iostream>
#include<vector>
using namespace std;
typedef vector<vector<int> > mat;
int N, ans=0;
void sol(int cnt, mat &a){
	if(cnt==5){
		for(int i=0;i<N;++i){
			for(int j=0;j<N;++j){
				if(ans<a[i][j])	ans=a[i][j];
			}
		}
	}
	else{
		mat nxt(N, vector<int>(N, 0));
		for(int i=0;i<N;++i){
			int t=0, j=0, p=0;
			for(;j<N;++j){
				if(a[i][j]==0);
				else if(a[i][j]==p)
					nxt[i][t++]=p+p, p=0;
				else if(p==0)
					p=a[i][j];
				else	nxt[i][t++]=p, p=a[i][j];
			}
			if(p)	nxt[i][t++]=p;
		}
		sol(cnt+1, nxt);
		nxt=mat(N, vector<int>(N, 0));
		for(int i=0;i<N;++i){
			int t=0, j=0, p=0;
			for(;j<N;++j){
				if(a[j][i]==0);
				else if(a[j][i]==p)
					nxt[t++][i]=p+p, p=0;
				else if(p==0)
					p=a[j][i];
				else	nxt[t++][i]=p, p=a[j][i];
			}
			if(p)	nxt[t++][i]=p;
		}
		sol(cnt+1, nxt);
		nxt=mat(N, vector<int>(N, 0));
		for(int i=0;i<N;++i){
			int t=N-1, j=N-1, p=0;
			for(;j>=0;--j){
				if(a[i][j]==0);
				else if(a[i][j]==p)
					nxt[i][t--]=p+p, p=0;
				else if(p==0)
					p=a[i][j];
				else	nxt[i][t--]=p, p=a[i][j];
			}
			if(p)	nxt[i][t--]=p;
		}
		sol(cnt+1, nxt);
		nxt=mat(N, vector<int>(N, 0));
		for(int i=0;i<N;++i){
			int t=N-1, j=N-1, p=0;
			for(;j>=0;--j){
				if(a[j][i]==0);
				else if(a[j][i]==p)
					nxt[t--][i]=p+p, p=0;
				else if(p==0)
					p=a[j][i];
				else	nxt[t--][i]=p, p=a[j][i];
			}
			if(p)	nxt[t--][i]=p;
		}
		sol(cnt+1, nxt);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	mat arr(N, vector<int>(N));
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			cin>>arr[i][j];
		}
	}
	if(N<2){
		cout<<arr[0][0]<<"\n";
		return 0;
	}
	sol(0, arr);
	cout<<ans<<"\n";
	return 0;
}
