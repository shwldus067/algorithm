#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N, M, K, A[10][10], soil[10][10], dead[10][10];
int dr[8]={-1, -1, -1, 0, 0, 1, 1, 1};
int dc[8]={-1, 0, 1, -1, 1, -1, 0, 1};
vector<int> tree[2][10][10];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M>>K;
	for(int i=0;i<N;++i)for(int j=0;j<N;++j)	cin>>A[i][j];
	for(int i=0;i<N;++i)for(int j=0;j<N;++j)	soil[i][j]=5;
	for(int i=0;i<M;++i){
		int x, y, z;
		cin>>x>>y>>z;
		tree[0][x-1][y-1].push_back(z);
	}
	int ans=M;
	while(K--){
		for(int i=0;i<N;++i){
			for(int j=0;j<N;++j){
				if(tree[0][i][j].empty())	continue;
				sort(tree[0][i][j].begin(), tree[0][i][j].end());
				int rem=soil[i][j], age, n=0, sum=0;
				while(n<tree[0][i][j].size() && rem>=(age=tree[0][i][j][n])){
					rem-=age;
					tree[1][i][j].push_back(age+1);
					++n;
				}
				soil[i][j]=rem;
				while(n<tree[0][i][j].size()){
					sum+=(tree[0][i][j][n])>>1;
					++n;
					ans--;
				}
				soil[i][j]+=sum;
				tree[0][i][j].clear();
			}
		}
		for(int i=0;i<N;++i){
			for(int j=0;j<N;++j){
				int n=0;
				while(n<tree[1][i][j].size()){
					if(!(tree[1][i][j][n]%5)){
						for(int d=0;d<8;++d){
							int r=i+dr[d], c=j+dc[d];
							if(r<0 || r>=N || c<0 || c>=N)	continue;
							tree[0][r][c].push_back(1);
							ans++;
						}
					}
					tree[0][i][j].push_back(tree[1][i][j][n]);
					++n;
				}
				tree[1][i][j].clear();
			}
		}
		for(int i=0;i<N;++i)for(int j=0;j<N;++j)	soil[i][j]+=A[i][j];
	}
	cout<<ans<<"\n";
	return 0;
}
