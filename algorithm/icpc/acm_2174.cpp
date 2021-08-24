#include<iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int A, B, N, M, X[101], Y[101], D[101], R, C;
	int dy[4]={-1, 0, 1, 0}, dx[4]={0, 1, 0, -1};
	int arr[101][101]={0, };
	char O;
	cin>>A>>B>>N>>M;
	for(int i=1;i<=N;++i){
		cin>>X[i]>>Y[i]>>O;
		if(O=='S')	D[i]=0;
		else if(O=='E')	D[i]=1;
		else if(O=='N')	D[i]=2;
		else	D[i]=3;
		arr[Y[i]][X[i]]=i;
	}
	while(M--){
		cin>>R>>O>>C;
		if(O=='L')	D[R]=(D[R]+C)%4;
		else if(O=='R')	D[R]=(D[R]-C+100)%4;
		else{
			int nx=X[R], ny=Y[R], d=D[R];
			while(C--){
				nx+=dx[d];ny+=dy[d];
				if(nx<=0 || nx>A || ny<=0 || ny>B){
					cout<<"Robot "<<R<<" crashes into the wall\n";
					return 0;
				}
				if(arr[ny][nx]){
					cout<<"Robot "<<R<<" crashes into robot "<<arr[ny][nx]<<"\n";
					return 0;
				}
			}
			arr[Y[R]][X[R]]=0;
			arr[ny][nx]=R;
			Y[R]=ny;X[R]=nx;
		}
	}
	cout<<"OK\n";
	return 0;
}
