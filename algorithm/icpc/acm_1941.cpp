#include<iostream>
using namespace std;
typedef pair<int, int> pii;
char arr[5][6];
int ans;
int dr[4]={-1, 0, 1, 0}, dc[4]={0, 1, 0, -1};
bool chk[5][5];
pii Q[10];
void sol(int r, int c, int k, int y){
	if(y>3)	return;
	if(k==7){
		int front=0, rear=0;
		bool visit[5][5]={0, };
		if(c==0)	r--, c=4;
		else	c--;
		Q[rear++]={r, c};
		visit[r][c]=1;
		while(front<rear){
			pii cur=Q[front++];
			for(int i=0;i<4;++i){
				int nr=cur.first+dr[i], nc=cur.second+dc[i];
				if(nr<0 || nr>4 || nc<0 || nc>4)	continue;
				if(visit[nr][nc])	continue;
				if(chk[nr][nc]){
					visit[nr][nc]=1;
					Q[rear++]={nr, nc};
				}
			}
		}
		if(rear==7)	++ans;
		return;
	}
	if(k+25-(5*r+c)<7)	return;
	int rr=r, cc=c+1;
	if(cc==5)	rr++, cc=0;
	sol(rr, cc, k, y);
	chk[r][c]=1;
	if(arr[r][c]=='Y')	sol(rr, cc, k+1, y+1);
	else	sol(rr, cc, k+1, y);
	chk[r][c]=0;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for(int i=0;i<5;++i)	cin>>arr[i];
	sol(0, 0, 0, 0);
	cout<<ans<<"\n";
	return 0;
}
