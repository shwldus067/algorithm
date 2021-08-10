#include<iostream>
using namespace std;
int N, M, PR, PC;
int dr[4]={-1, 0, 1, 0}, dc[4]={0, 1, 0, -1};
int S[4]={1, 0, 3, 2}, R[4]={3, 2, 1, 0};
char dirr[5]="URDL";
char arr[502][503];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=1;i<=N;++i)	cin>>arr[i]+1;
	cin>>PR>>PC;
	int dir=0, ans=0;
	for(int i=0;i<4;++i){
		int r=PR, c=PC, cnt=1, d=i;
		while(arr[r+dr[d]][c+dc[d]] && arr[r+dr[d]][c+dc[d]]!='C'){
			r+=dr[d];c+=dc[d];
			if(arr[r][c]=='/')	d=S[d];
			else if(arr[r][c]=='\\') d=R[d];
			cnt++;
			if(r==PR && c==PC && d==i){
				cout<<dirr[i]<<"\nVoyager\n";
				return 0;
			}
		}
		if(ans<cnt){
			ans=cnt;
			dir=i;
		}
	}
	cout<<dirr[dir]<<"\n"<<ans<<"\n";
	return 0;
}
