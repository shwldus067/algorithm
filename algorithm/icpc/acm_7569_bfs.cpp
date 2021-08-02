#include<iostream>
#include<queue>
using namespace std;
int dh[6]={1, -1, 0, 0, 0, 0};
int dn[6]={0, 0, 0, 0, 1, -1};
int dm[6]={0, 0, -1, 1, 0, 0};
int main(){
	int M, N, H, cnt=0, m, n, h, num_t=0, num_b=0, num_u=0;;
	bool unripen;
	queue<pair<int, pair<int, int> > > tom;
	cin>>M>>N>>H;
	int box[H][N][M];
	for(int i=0;i<H;i++){
		for(int j=0;j<N;j++){
			for(int k=0;k<M;k++){
				cin>>box[i][j][k];
				if(box[i][j][k]==0)	num_u++;
				else if(box[i][j][k]==1){
					num_t++;
					tom.push({i, {j, k}});
				}
				else	num_b++;
			}
		}
	}
	if(num_u==0){
		cout<<0<<"\n";
		return 0;
	}
	else if(num_t==0){
		cout<<-1<<"\n";
		return 0;
	}
	while(!tom.empty()){
		int size=tom.size();
		while(size--){
			h=tom.front().first;
			n=tom.front().second.first;
			m=tom.front().second.second;
			tom.pop();
			for(int j=0;j<6;j++){
				if(h+dh[j]<0 || h+dh[j]>=H ||
					n+dn[j]<0 || n+dn[j]>=N ||
					m+dm[j]<0 || m+dm[j]>=M)	continue;
				if(box[h+dh[j]][n+dn[j]][m+dm[j]]==0){
					box[h+dh[j]][n+dn[j]][m+dm[j]]=1;
					num_u--;
					tom.push({h+dh[j], {n+dn[j], m+dm[j]}});
				}
			}
		}
		cnt++;
	}
	if(num_u>0){
		cout<<-1<<"\n";
		return 0;
	}
	cout<<cnt-1<<"\n";
	return 0;
}
