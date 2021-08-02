#include<iostream>
#include<queue>
using namespace std;
struct str{
	int x, y, z;
	str(int x, int y, int z):x(x), y(y), z(z){}
};
bool operator<(str a, str b){
	return a.z>b.z;
}
int n, arr[500][500], d[500][500];
int dr[]={-1, 1, 0, 0}, dc[]={0, 0, -1, 1};
bool visit[500][500];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	priority_queue<str> Q;
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j){
			cin>>arr[i][j];
			Q.push(str(i, j, arr[i][j]));
		}
	int r, c, k, nr, nc, res=1;
	while(Q.size()){
		r=Q.top().x, c=Q.top().y, k=Q.top().z;
		Q.pop();
		int tmp=0;
		for(int i=0;i<4;i++){
			nr=r+dr[i], nc=c+dc[i];
			if(nr<0 || nr>=n || nc<0 || nc>=n)	continue;
			if(arr[nr][nc]<k){
				if(tmp<d[nr][nc]){
					tmp=d[nr][nc];
				}
			}
		}
		d[r][c]=tmp+1;
		if(res<d[r][c])	res=d[r][c];
	}
	cout<<res<<"\n";
	return 0;
}
