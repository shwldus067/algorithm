#include<iostream>
using namespace std;
int d[30][30001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int R, C, N;
	char B[30000][31];
	cin>>R>>C;
	for(int i=0;i<R;++i)	cin>>B[i];
	for(int i=0;i<C;++i)	d[i][0]=0;
	cin>>N;
	while(N--){
		int a;
		cin>>a;
		--a;
		int r=0, c=a, tmp;
		int &size=d[a][0];
		while(1){
			if(!size)	break;
			tmp=d[a][size];
			c=tmp&31, r=tmp>>5;
			size--;
			if(B[r][c]=='.')	break;
		}
		while(1){
			d[a][++size]=(r<<5)+c;
			if(r==R-1 || B[r+1][c]=='X')	break;
			else if(B[r+1][c]=='O'){
				if(c>0 && B[r][c-1]=='.' && B[r+1][c-1]=='.')	c--;
				else if(c<C-1 && B[r][c+1]=='.' && B[r+1][c+1]=='.')	++c;
				else break;
			}
			++r;
		}
		B[r][c]='O';
		size--;
	}
	for(int i=0;i<R;++i)	cout<<B[i]<<"\n";
	return 0;
}
