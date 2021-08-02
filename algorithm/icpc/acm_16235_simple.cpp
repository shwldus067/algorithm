#include<iostream>
#include<cstring>
#include<list>
#include<algorithm>
using namespace std;
int N, M, K, A[10][10], soil[10][10], treec[10][10];
int dr[8]={-1, -1, -1, 0, 0, 1, 1, 1};
int dc[8]={-1, 0, 1, -1, 1, -1, 0, 1};
list<pair<int, int> > tree[10][10];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M>>K;
	for(int i=0;i<N;++i)for(int j=0;j<N;++j){
		cin>>A[i][j];
		soil[i][j]=5;
	}
	while(M--){
		int x, y, z;
		cin>>x>>y>>z;
		tree[x-1][y-1].push_back({z, 1});
	}
	while(K--){
		memset(treec, 0, sizeof(treec));
		for(int i=0;i<N;++i)for(int j=0;j<N;++j){
			int f=0, rem;
			list<pair<int, int> >::iterator iter=tree[i][j].begin();
			for(;iter!=tree[i][j].end();++iter){
				int &age=(*iter).first;
				int &cnt=(*iter).second;
				if(soil[i][j]<age*cnt){
					rem=cnt-soil[i][j]/age;
					cnt=soil[i][j]/age;
					f=true;
				}
				soil[i][j]-=age*cnt;
				age++;
				if(age%5==0 && cnt){
					for(int d=0;d<8;++d){
						int r=i+dr[d], c=j+dc[d];
						if(r<0 || r>=N || c<0 || c>=N)	continue;
						treec[r][c]+=cnt;
					}
				}
				if(f)	break;
			}
			if(!f)	continue;
			soil[i][j]+=(((*iter).first-1)/2)*rem;
			list<pair<int, int> >::iterator tmp=iter;
			if((*tmp).second!=0)	++tmp;
			for(iter++;iter!=tree[i][j].end();iter++){
				soil[i][j]+=((*iter).first/2)*(*iter).second;
			}
			tree[i][j].erase(tmp, tree[i][j].end());
		}
		for(int i=0;i<N;++i)for(int j=0;j<N;++j){
			if(treec[i][j]){
				tree[i][j].push_front({1, treec[i][j]});
			}
			soil[i][j]+=A[i][j];
		}
	}
	int ans=0;
	for(int i=0;i<N;++i)for(int j=0;j<N;++j){
		for(pair<int, int> tp:tree[i][j]){
			ans+=tp.second;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
