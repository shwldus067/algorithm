#include<iostream>
using namespace std;
int N, ans;
int gr[11][4], bl[4][11];
void scoregr();
void scorebl();
void downgr(int x1, int y1, int x2, int y2, int c);
void downbl(int x1, int y1, int x2, int y2, int c);
void refillgr(int f, int n){
	for(int i=0;i<n;++i){
		for(int j=0;j<4;++j){
			if(gr[f-i][j]==5)
				gr[f-i+1][j]=1;
			else if(gr[f-i][j]==6)
				gr[f-i-1][j]=1;
			gr[f-i][j]=0;
		}
	}
	for(int i=f-n;i>3;--i){
		for(int j=0;j<4;++j){
			if(gr[i][j]==0)	continue;
			else if(gr[i][j]==1){
				gr[i][j]=0;
				downgr(i, j, i, j, 1);
			}
			else if(gr[i][j]==3){
				gr[i][j]=gr[i][j+1]=0;
				downgr(i, j, i, j+1, 3);
			}
			else if(gr[i][j]==6){
				gr[i][j]=gr[i-1][j]=0;
				downgr(i-1, j, i, j, 5);
			}
			else	continue;
		}
	}
	scoregr();
}
void refillbl(int f, int n){
	for(int i=0;i<n;++i){
		for(int j=0;j<4;++j){
			if(bl[j][f-i]==3)
				bl[j][f-i+1]=1;
			else if(bl[j][f-i]==4)
				bl[j][f-i-1]=1;
			bl[j][f-i]=0;
		}
	}
	for(int j=f-n;j>3;--j){
		for(int i=0;i<4;++i){
			if(bl[i][j]==0)	continue;
			else if(bl[i][j]==1){
				bl[i][j]=0;
				downbl(i, j, i, j, 1);
			}
			else if(bl[i][j]==5){
				bl[i][j]=bl[i+1][j]=0;
				downbl(i, j, i+1, j, 5);
			}
			else if(bl[i][j]==4){
				bl[i][j]=bl[i][j-1]=0;
				downbl(i, j-1, i, j, 3);
			}
			else continue;
		}
	}
	scorebl();
}
void downgr(int x1, int y1, int x2, int y2, int c){
	int t=0;
	for(;x2+t<10;++t){
		if(gr[x1+t][y1] || gr[x2+t][y2])	break;
	}
	--t;
	gr[x2+t][y2]=c+1;
	gr[x1+t][y1]=c;
}
void downbl(int x1, int y1, int x2, int y2, int c){
	int t=0;
	for(;y2+t<10;++t){
		if(bl[x1][y1+t] || bl[x2][y2+t])	break;
	}
	--t;
	bl[x2][y2+t]=c+1;
	bl[x1][y1+t]=c;
}
void scoregr(){
	for(int i=6;i<10;++i){
		int f=1;
		for(int j=0;j<4;++j){
			if(!gr[i][j]){
				f=0;break;
			}
		}
		if(f){
			refillgr(i, 1); ++ans; break;
		}
	}
}
void scorebl(){
	for(int i=6;i<10;++i){
		int f=1;
		for(int j=0;j<4;++j){
			if(!bl[j][i]){
				f=0;break;
			}
		}
		if(f){
			refillbl(i, 1); ++ans; break;
		}
	}
}
void checkgr(){
	scoregr();
	int n=0;
	for(int i=4;i<6;++i){
		int f=0;
		for(int j=0;j<4;++j){
			if(gr[i][j]){
				f=1; break;
			}
		}
		if(f)	++n;
	}
	if(n)	refillgr(9, n);
}
void checkbl(){
	scorebl();
	int n=0;
	for(int j=4;j<6;++j){
		int f=0;
		for(int i=0;i<4;++i){
			if(bl[i][j]){
				f=1; break;
			}
		}
		if(f)	++n;
	}
	if(n)	refillbl(9, n);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	while(N--){
		int t, x, y;
		cin>>t>>x>>y;
		if(t==1)	downgr(x, y, x, y, 1), downbl(x, y, x, y, 1);
		else if(t==2)	downgr(x, y, x, y+1, 3), downbl(x, y, x, y+1, 3);
		else	downgr(x, y, x+1, y, 5), downbl(x, y, x+1, y, 5);
		checkgr(), checkbl();
	}
	int fill=0;
	for(int i=6;i<10;++i){
		for(int j=0;j<4;++j){
			if(gr[i][j])	++fill;
			if(bl[j][i])	++fill;
		}
	}
	cout<<ans<<"\n"<<fill<<"\n";
	return 0;
}
