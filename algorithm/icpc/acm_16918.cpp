#include<iostream>
using namespace std;
int R, C, N;
int dr[4]={-1, 0, 1, 0}, dc[4]={0, 1, 0, -1};
bool A[2][200][200];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>R>>C>>N;
	for(int i=0;i<R;++i)for(int j=0;j<C;++j){
		char t;
		cin>>t;
		if(t=='O')	A[0][i][j]=A[1][i][j]=1;
	}
	--N;
	for(int i=0;i<N;++i){
		if(i&1){
			for(int i=0;i<R;++i)for(int j=0;j<C;++j){
				if(A[0][i][j]){
					A[1][i][j]=0;
					for(int d=0;d<4;++d){
						int r=i+dr[d], c=j+dc[d];
						if(r<0 || r>=R || c<0 || c>=C)	continue;
						A[1][r][c]=0;
					}
				}
			}
			for(int i=0;i<R;++i)for(int j=0;j<C;++j)	A[0][i][j]=A[1][i][j];
		}else{
			for(int i=0;i<R;++i)for(int j=0;j<C;++j) A[1][i][j]=1;
		}
	}
	int f=0;
	if(N&1)	f=1;
	for(int i=0;i<R;++i){
		for(int j=0;j<C;++j){
			if(A[f][i][j])	cout<<"O";
			else	cout<<".";
		}
		cout<<"\n";
	}
	return 0;
}
