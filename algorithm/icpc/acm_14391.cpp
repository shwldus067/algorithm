#include<iostream>
using namespace std;
int N, M, res=0;
int A[4][4];
bool visit[4][4];
bool nextcoord(int* nr, int* nc){
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(visit[i][j]==false){
				*nr=i, *nc=j;
				return false;
			}
		}
	}
	return true;
}
void func(int r, int c, int s){
	int cur=0, nr, nc, i;
	for(i=0;r+i<N;i++){
		if(visit[r+i][c])	break;
		visit[r+i][c]=true;
		cur*=10;
		cur+=A[r+i][c];
		if(nextcoord(&nr, &nc))	res=res>s+cur ? res:s+cur;
		else	func(nr, nc, s+cur);
	}
	i--;
	for(;i>=1;i--)	visit[r+i][c]=false;
	cur=A[r][c];
	for(i=1;c+i<M;i++){
		if(visit[r][c+i])	break;
		visit[r][c+i]=true;
		cur*=10;
		cur+=A[r][c+i];
		if(nextcoord(&nr, &nc))	res=res>s+cur ? res:s+cur;
		else	func(nr, nc, s+cur);
	}
	i--;
	for(;i>=0;i--)	visit[r][c+i]=false;
	return ;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	char c;
	cin>>N>>M;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin>>c;
			A[i][j]=c-'0';
		}
	}
	func(0, 0, 0);
	cout<<res<<"\n";
	return 0;
}
