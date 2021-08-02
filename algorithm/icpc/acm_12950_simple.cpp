#include<iostream>
using namespace std;
int N, M;
char g[21][21];
int d[21][21];
int inf=~(1<<31);
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	int u, v;
	char c;
	while(M--){
		cin>>u>>v>>c;
		g[u][v]=c;
		g[v][u]=c;
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(i==j)	d[i][j]=0;
			else if(g[i][j]!=0)	d[i][j]=1;
			else	d[i][j]=inf;
		}
	}
	for(int i=1;i<=N;i++)
		for(int u=0;u<N;u++)
			for(int v=0;v<N;v++)
				if(d[u][v]!=inf)
					for(int pu=0;pu<N;pu++)
						if(g[pu][u])
							for(int pv=0;pv<N;pv++)
								if(g[pv][v])
									if(g[pu][u]==g[pv][v])
										d[pu][pv]=min(d[pu][pv], d[u][v]+2);
	if(d[0][1]<inf)	cout<<d[0][1]<<"\n";
	else	cout<<"-1\n";
	return 0;
}
