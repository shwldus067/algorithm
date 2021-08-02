#include<iostream>
using namespace std;
int N, M, sum;
char arr[52][52];
int dr[4]={1, -1, 0, 0}, dc[4]={0, 0, -1, 1};
bool chk[52][52], filled[52][52];
bool isnt(int r, int c){
	return r<=0 || r>N || c<=0 || c>M;
}
bool dfs(int r, int c, char d){
	if(isnt(r, c)){
		return false;
	}
	bool ret=1;
	chk[r][c]=1;
	sum+=d-arr[r][c];
	for(int i=0;i<4;++i){
		if(arr[r+dr[i]][c+dc[i]]<d && !chk[r+dr[i]][c+dc[i]])
			if(!dfs(r+dr[i], c+dc[i], d)) ret=0;
	}
	return ret;
}
void fill(int r, int c, char d){
	filled[r][c]=1;
	for(int i=0;i<4;++i){
		if(isnt(r+dr[i], c+dc[i]))	continue;
		if(arr[r+dr[i]][c+dc[i]]<d && !filled[r+dr[i]][c+dc[i]])
			fill(r+dr[i], c+dc[i], d);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	char m=0;
	int ans=0;
	for(int i=1;i<=N;++i){
		for(int j=1;j<=M;++j){
			cin>>arr[i][j];
			arr[i][j]-='0';
			m=max(m, arr[i][j]);
		}
	}
	for(char k=m;k>1;--k){
		for(int i=1;i<=N;++i)for(int j=1;j<=M;++j)	chk[i][j]=0;
		for(int i=1;i<=N;++i){
			for(int j=1;j<M;++j){
				if(filled[i][j])	continue;
				if(arr[i][j]<k && !chk[i][j]){
					sum=0;
					if(dfs(i, j, k)){
						ans+=sum;
						fill(i, j, k);
					}
				}
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}
