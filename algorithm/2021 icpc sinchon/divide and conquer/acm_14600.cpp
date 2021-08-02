#include<iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int K, x, y, arr[4][4]={{1, 1, 2, 2}, {1, 3, 3, 2}, {4, 3, 3, 5}, {4, 4, 5, 5}};
	cin>>K>>x>>y;
	K=1<<K;
	--x, y=K-y;
	if(K==2){
		for(int i=0;i<2;++i){
			for(int j=0;j<2;++j){
				if(i==y && j==x)	cout<<"-1 ";
				else	cout<<"1 ";
			}
			cout<<"\n";
		}
	}else{
		if(0<y && y<3 && 0<x && x<3)	arr[y][x]=-1;
		else{
			int r=y, c=x;
			if(y==0)	++r;
			else if(y==3)	--r;
			if(x==0)	++c;
			else if(x==3)	--c;
			arr[r][c]=arr[y][x];
			arr[y][x]=-1;
		}
		for(int i=0;i<4;++i){
			for(int j=0;j<4;++j)	cout<<arr[i][j]<<" ";
			cout<<"\n";
		}
	}
	return 0;
}
