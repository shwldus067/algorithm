#include<iostream>
using namespace std;
int N, d[1<<16][16], w[16][16], b[1<<16];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;++i)for(int j=0;j<N;++j)	cin>>w[i][j];
	for(int i=0;i<N;++i)	b[1<<i]=i;	//몇 번째 bit가 켜져 있는지 저장 
	int last=(1<<N)-1;	//모두 방문했을 때의 bit 
	fill(&d[0][0], &d[last][16], 1e9);	//최소값을 찾기 위해 큰 값으로 초기화 
	d[1][0]=0;	//첫 방문하는 도시를 index 0인 도시로 하고 그 때의 비용은 0 
	for(int i=1;i<=last;++i){
		for(int j=i;j;j&=j-1){	//현재 방문한 도시 차례로 선택  //j&=j-1 -> 1인 bit 중 가장 끝의 bit off 
			int k=j&(-j);	//1인 bit중 가장 끝의 bit 선택 
			k=b[k];	//그 bit가 몇 번째 bit인지 
			if(d[i][k]!=1e9){
				for(int jj=last&~i;jj;jj&=jj-1){	//방문하지 않은 도시 선택 
					int kk=jj&(-jj);	//1인 bit중 가장 끝의 bit 선택 
					kk=b[kk];	//그 bit가 몇 번째 bit인지 
					int l=i|(1<<kk);	//방문한 도시의 bit 설정 
					if(w[k][kk])	d[l][kk]=min(d[l][kk], d[i][k]+w[k][kk]);	//k도시에서 kk도시를 방문했을 때의 dp값 update 
				}
			}
		}
	}
	int ans=1e9;
	for(int i=1;i<N;++i){
		if(w[i][0])	ans=min(ans, d[last][i]+w[i][0]);
	}
	cout<<ans<<"\n";
	return 0;
}
