#include<iostream>
using namespace std;
typedef pair<int, int> pii;
char arr[5][6];
int dr[4]={-1, 0, 1, 0}, dc[4]={0, 1, 0, -1};
int used[7], ans;
bool visit[5][5];
char chk[1<<22];
void sol(int n, int k, int y){
	if(chk[n/8] & (1<<(n%8)))	return;
	chk[n/8]|=(1<<(n%8));
	if(y>3)	return;
	if(k==7){
		++ans;
		return;
	}
	for(int j=0;j<k;++j){
		int r=used[j]/5, c=used[j]%5;
		for(int i=0;i<4;++i){
			int nr=r+dr[i], nc=c+dc[i];
			if(nr<0 || nr>4 || nc<0 || nc>4)	continue;
			if(visit[nr][nc])	continue;
			visit[nr][nc]=1;
			int t=5*nr+nc;
			used[k]=t;
			sol(n|(1<<t), k+1, y+(arr[nr][nc]=='Y'));
			visit[nr][nc]=0;
		}
	}
	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for(int i=0;i<5;++i)	cin>>arr[i];
	for(int r=0;r<5;++r){
		for(int c=0;c<5;++c){
			visit[r][c]=1;
			int t=5*r+c;
			used[0]=t;
			sol(1<<t, 1, arr[r][c]=='Y');
			visit[r][c]=0;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
