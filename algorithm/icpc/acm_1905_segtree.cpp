#include<iostream>
using namespace std;
int Lx, Ly, N, size=1024;
int seg1[2048][2048], seg2[2048][2048], seg3[2048][2048], seg4[2048][2048];
int query1(int x1, int x2, int y1, int y2){
	int ret=0;
	for(x1+=size-1, x2+=size;x1/2!=x2/2;x1/=2, x2/=2){
		if(x1%2==0){
			for(int l=y1+size-1, r=y2+size;l/2!=r/2;l/=2, r/=2){
				if(l%2==0)	ret=max(ret, seg1[x1+1][l+1]);
				if(r%2)	ret=max(ret, seg1[x1+1][r-1]);
			}
		}
		if(x2%2){
			for(int l=y1+size-1, r=y2+size;l/2!=r/2;l/=2, r/=2){
				if(l%2==0)	ret=max(ret, seg1[x2-1][l+1]);
				if(r%2)	ret=max(ret, seg1[x2-1][r-1]);
			}
		}
	}
	return ret;
}
int query2(int x, int y){
	int ret=0;
	for(int i=x+size;i;i/=2){
		for(int j=y+size;j;j/=2){
			ret=max(ret, seg2[i][j]);
		}
	}
	return ret;
}
int query3(int x, int y1, int y2){
	int ret=0;
	for(x+=size;x;x/=2){
		for(int l=y1+size-1, r=y2+size;l/2!=r/2;l/=2, r/=2){
			if(l%2==0)	ret=max(ret, seg3[x][l+1]);
			if(r%2)	ret=max(ret, seg3[x][r-1]);
		}
	}
	return ret;
}
int query4(int x1, int x2, int y){
	int ret=0;
	for(x1+=size-1, x2+=size;x1/2!=x2/2;x1/=2, x2/=2){
		if(x1%2==0){
			for(int i=y+size;i;i/=2)
				ret=max(ret, seg4[x1+1][i]);
		}
		if(x2%2){
			for(int i=y+size;i;i/=2)
				ret=max(ret, seg4[x2-1][i]);
		}
	}
	return ret;
}
void update1(int x, int y, int d){
	for(int i=x+size;i;i/=2){
		for(int j=y+size;j;j/=2){
			seg1[i][j]=max(seg1[i][j], d);
		}
	}
}
void update2(int x1, int x2, int y1, int y2, int d){
	for(x1+=size-1, x2+=size;x1/2!=x2/2;x1/=2, x2/=2){
		if(x1%2==0){
			for(int l=y1+size-1, r=y2+size;l/2!=r/2;l/=2, r/=2){
				if(l%2==0)	seg2[x1+1][l+1]=max(d, seg2[x1+1][l+1]);
				if(r%2)	seg2[x1+1][r-1]=max(d, seg2[x1+1][r-1]);
			}
		}
		if(x2%2){
			for(int l=y1+size-1, r=y2+size;l/2!=r/2;l/=2, r/=2){
				if(l%2==0)	seg2[x2-1][l+1]=max(d, seg2[x2-1][l+1]);
				if(r%2)	seg2[x2-1][r-1]=max(d, seg2[x2-1][r-1]);
			}
		}
	}
}
void update3(int x1, int x2, int y, int d){
	for(x1+=size-1, x2+=size;x1/2!=x2/2;x1/=2, x2/=2){
		if(x1%2==0){
			for(int i=y+size;i;i/=2)
				seg3[x1+1][i]=max(d, seg3[x1+1][i]);
		}
		if(x2%2){
			for(int i=y+size;i;i/=2)
				seg3[x2-1][i]=max(d, seg3[x2-1][i]);
		}
	}
}
void update4(int x, int y1, int y2, int d){
	for(x+=size;x;x/=2){
		for(int l=y1+size-1, r=y2+size;l/2!=r/2;l/=2, r/=2){
			if(l%2==0)	seg4[x][l+1]=max(d, seg4[x][l+1]);
			if(r%2)	seg4[x][r-1]=max(d, seg4[x][r-1]);
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>Lx>>Ly>>N;
	int ans=0;
	while(N--){
		int lx, ly, lz, px, py;
		cin>>lx>>ly>>lz>>px>>py;
		int tmp=max(max(query1(px, px+lx, py, py+ly), query2(px, py)),
				max(query3(px, py, py+ly), query4(px, px+lx, py)))+lz;
		if(ans<tmp)	ans=tmp;
		update1(px, py, tmp);
		update2(px, px+lx, py, py+ly, tmp);
		update3(px, px+lx, py, tmp);
		update4(px, py, py+ly, tmp);
	}
	cout<<ans<<"\n";
	return 0;
}
