#include<iostream>
using namespace std;
int abs(int x){
	return x<0 ? -x:x;
}
void swap(int x, int y, int arr[]){
	int tmp=arr[x];
	arr[x]=arr[y];arr[y]=tmp;
}
void swap1(int i, int x, int y, int arr[][2]){
	int tmp=arr[x][i];
	arr[x][i]=arr[y][i];arr[y][i]=tmp;
}
int mag(int x){
	return x==0 ? 0:x/abs(x);
}
int d[5][5], m[2];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int k=0, mm=125, minus=0;
	int p[5][2], dist[5], a[5][5], pt[5][2], loc[2];
	char chr;
	for(int i=0;i<5;++i)for(int j=0;j<5;++j){
		cin>>chr;
		if(chr=='*'){
			p[k][0]=i, p[k++][1]=j;
			for(int y=0;y<5;++y)for(int x=0;x<5;++x){
				d[y][x]+=(abs(j-x)+abs(i-y));
			}
		}
	}
	for(int i=0;i<5;++i)for(int j=0;j<5;++j){
		if(mm>d[i][j]){
			mm=d[i][j];m[0]=i;m[1]=j;
		}
	}
	for(int i=0;i<k;++i)	dist[i]=abs(p[i][0]-m[0])+abs(p[i][1]-m[1]);
	for(int x=0;x<k;++x)for(int y=0;y<k-1;++y){
		if(dist[y]>dist[y+1]){
			swap(y, y+1, dist);
			swap1(0, y, y+1, p);
			swap1(1, y, y+1, p);
		}
	}
	for(int i=0;i<k;++i){
		int tmp=0, dir;
		for(int x=0;x<5;++x)for(int y=0;y<5;++y)	a[x][y]=0;
		for(int x=0;x<k;++x)
			pt[x][0]=p[x][0]-m[0], pt[x][1]=p[x][1]-m[1];
		for(int j=0;j<k;++j){
			if(i==j)	continue;
			int py=pt[j][0], px=pt[j][1];
			loc[0]=m[0], loc[1]=m[1];
			if(px==0 && py==0)	continue;
			for(int x=0;x<dist[j];++x){
				int rl=abs(mag(px))*(1+a[loc[0]][loc[1]+mag(px)]);
				int ud=abs(mag(pt[j][0]))*(1+a[loc[0]+mag(pt[j][0])][loc[1]]);
				if(rl+ud==0)	break;
				else if(rl>ud)	dir=0;
				else if(rl<ud)	dir=1;
				else{
					for(int v=0;v<k;++v){
						if(mag(pt[v][1])==mag(px))	++rl;
						if(mag(pt[v][0])==mag(py))	++ud;
					}
					if(rl>ud)	dir=0;
					else	dir=1;
				}
				if(dir==0)	pt[j][1]-=mag(px), loc[1]+=mag(px);
				else	pt[j][0]-=mag(py), loc[0]+=mag(py);
				--tmp;
				if(a[loc[0]][loc[1]]==1)	continue;
				a[loc[0]][loc[1]]=1;
				pt[j][0]=pt[j][1]=0;
				break;
			}
		}
		if(tmp<minus)	minus=tmp;
	}
	cout<<mm+minus<<"\n";
	return 0;
}
