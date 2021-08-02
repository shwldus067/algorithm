#include<iostream>
using namespace std;
int R, C;
int d[30][30001];
char B[30000][31];
void update(int s){
	int r=0, c=s, tmp;
	int &size=d[s][0];
	if(size){
		tmp=d[s][size--];
		c=tmp&31, r=tmp>>5;
	}
	while(1){
		d[s][++size]=(r<<5)+c;
		if(r==R-1 || B[r+1][c]=='X')	return;
		else if(B[r+1][c]=='O'){
			if(c>0 && B[r][c-1]=='.' && B[r+1][c-1]=='.')	c--;
			else if(c<C-1 && B[r][c+1]=='.' && B[r+1][c+1]=='.')	++c;
			else return;
		}
		++r;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>R>>C;
	for(int i=0;i<R;++i)	cin>>B[i];
	int N;
	cin>>N;
	while(N--){
		int a;
		cin>>a;
		--a;
		int r, c, tmp;
		int &top=d[a][0];
		while(1){
			if(!top)	break;
			tmp=d[a][top];
			c=tmp&31, r=tmp>>5;
			if(B[r][c]=='.')	break;
			top--;
		}
		update(a);
		tmp=d[a][top];
		c=tmp&31, r=tmp>>5;
		B[r][c]='O';
		top--;
	}
	for(int i=0;i<R;++i)	cout<<B[i]<<"\n";
	return 0;
}
