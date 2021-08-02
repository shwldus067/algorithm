#include<iostream>
using namespace std;
long long adj[8][8]={{0, 1, 1, 0, 0, 0, 0, 0},
					{1, 0, 1, 1, 0, 0, 0 ,0},
					{1, 1, 0, 1, 1, 0, 0, 0},
					{0, 1, 1, 0, 1, 1, 0, 0},
					{0, 0, 1, 1, 0, 1, 0, 1},
					{0, 0, 0, 1, 1, 0, 1, 0},
					{0, 0, 0, 0, 0, 1, 0, 1},
					{0, 0, 0, 0, 1, 0, 1, 0}};
int main(){
	int D;
	cin>>D;
	long long route[8][8]={{1, 0, 0, 0, 0, 0, 0, 0},
							{0, 1, 0, 0, 0, 0, 0, 0},
							{0, 0, 1, 0, 0, 0, 0, 0},
							{0, 0, 0, 1, 0, 0, 0, 0},
							{0, 0, 0, 0, 1, 0, 0, 0},
							{0, 0, 0, 0, 0, 1, 0, 0},
							{0, 0, 0, 0, 0, 0, 1, 0},
							{0, 0, 0, 0, 0, 0, 0, 1}};
	long long tmp[8][8];
	while(D){
		if(D%2){
			copy(&route[0][0], &route[7][8], &tmp[0][0]);
			for(int i=0;i<8;i++){
				for(int j=0;j<8;j++){
					route[i][j]=0;
					for(int k=0;k<8;k++){
						route[i][j]+=adj[i][k]*tmp[k][j];
						route[i][j]%=1000000007;
					}
				}
			}
		}
		copy(&adj[0][0], &adj[7][8], &tmp[0][0]);
		for(int i=0;i<8;i++){
			for(int j=0;j<8;j++){
				adj[i][j]=0;
				for(int k=0;k<8;k++){
					adj[i][j]+=tmp[i][k]*tmp[k][j];
					adj[i][j]%=1000000007;
				}
			}
		}
		D>>=1;
	}
	cout<<route[0][0]<<"\n";
}
