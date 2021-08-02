#include<iostream>
using namespace std;
struct shark{
	int r, c, s, d, z;
};
int R, C, M, ans;
shark arr[10001];
int board[101][101];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>R>>C>>M;
	++M;
	for(int i=1;i<M;++i){
		int r, c, s, d, z;
		cin>>r>>c>>s>>d>>z;
		arr[i]={r, c, s, d, z};
		board[r][c]=i;
	}
	R++, C++;
	for(int i=1;i<C;++i){
		for(int j=1;j<R;++j){
			if(board[j][i]){
				ans+=arr[board[j][i]].z;
				arr[board[j][i]].r=0;
				board[j][i]=0;
				break;
			}
		}
		for(int x=1;x<R;++x)for(int y=1;y<C;++y)	board[x][y]=0;
		for(int k=1;k<M;++k){
			if(arr[k].r==0)	continue;
			int d=arr[k].d, s=arr[k].s;
			int r=arr[k].r, c=arr[k].c;
			if(d==1){
				int f=0;
				if(s>=r-1){
					f=1, s-=r-1, r=1;
					f+=s/(R-2);
					if(f&1){
						d=2, r+=s%(R-2);
					}
					else{
						r=R-1-s%(R-2);
					}
				}
				else{
					r-=s;
				}
			}
			else if(d==2){
				int f=0;
				if(s>=R-r-1){
					f=1, s-=R-r-1, r=R-1;
					f+=s/(R-2);
					if(f&1){
						d=1, r-=s%(R-2);
					}
					else{
						r=1+s%(R-2);
					}
				}
				else{
					r+=s;
				}
			}
			else if(d==3){
				int f=0;
				if(s>=C-c-1){
					f=1, s-=C-c-1, c=C-1;
					f+=s/(C-2);
					if(f&1){
						d=4, c-=s%(C-2);
					}
					else{
						c=1+s%(C-2);
					}
				}
				else{
					c+=s;
				}
			}
			else{
				int f=0;
				if(s>=c-1){
					f=1, s-=c-1, c=1;
					f+=s/(C-2);
					if(f&1){
						d=3, c+=s%(C-2);
					}
					else{
						c=C-1-s%(C-2);
					}
				}
				else{
					c-=s;
				}
			}
			arr[k].r=r, arr[k].c=c, arr[k].d=d;
			if(board[r][c]){
				if(arr[k].z<arr[board[r][c]].z){
					arr[k].r=0;
				}
				else{
					arr[board[r][c]].r=0;
					board[r][c]=k;
				}
			}
			else{
				board[r][c]=k;
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}
