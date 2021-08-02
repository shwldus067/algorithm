#include<iostream>
#include<cstring>
using namespace std;
int arr[10][10], dp[6][6][6][6][6][10][10];
int ispossible(int y, int x, int k){
	int f=1;
	if(y+k>10 || x+k>10)	return 0;
	for(int i=y;i<y+k;++i){
		for(int j=x;j<x+k;++j){
			if(!arr[i][j]){
				f=0;break;
			}
		}
		if(!f)	break;
	}
	if(f){
		for(int i=y;i<y+k;++i){
			for(int j=x;j<x+k;++j){
				arr[i][j]=0;
			}
		}
	}
	return f;
}
void refill(int y, int x, int k){
	for(int i=y;i<y+k;++i){
		for(int j=x;j<x+k;++j){
			arr[i][j]=1;
		}
	}
}
int sol(int a, int b, int c, int d, int e, int y, int x){
	if(a<0 || b<0 || c<0 || d<0 || e<0)	return 26;
	int &ret=dp[a][b][c][d][e][y][x];
	if(ret!=-1)	return ret;
	ret=26;
	int Y=-1, X=-1;
	for(int i=0;i<10;++i){
		for(int j=0;j<10;++j){
			if(arr[i][j]){
				Y=i, X=j;break;
			}
		}
		if(Y!=-1)	break;
	}
	if(Y==-1)	return ret=0;
	for(int i=1;i<6;++i){
		if(ispossible(Y, X, i)){
			switch(i){
				case 1:
					ret=min(ret, sol(a-1, b, c, d, e, Y, X)+1);
					break;
				case 2:
					ret=min(ret, sol(a, b-1, c, d, e, Y, X)+1);
					break;
				case 3:
					ret=min(ret, sol(a, b, c-1, d, e, Y, X)+1);
					break;
				case 4:
					ret=min(ret, sol(a, b, c, d-1, e, Y, X)+1);
					break;
				case 5:
					ret=min(ret, sol(a, b, c, d, e-1, Y, X)+1);
					break;
			}
			refill(Y, X, i);
		}
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for(int i=0;i<10;++i)for(int j=0;j<10;++j)	cin>>arr[i][j];
	memset(dp, -1, sizeof(dp));
	int ans=sol(5, 5, 5, 5, 5, 0, 0);
	if(ans>25)	cout<<"-1\n";
	else	cout<<ans<<"\n";
	return 0;
}
