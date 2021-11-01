#include<iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	bool chk[6][6]={0, };
	int r=-1, c=-1, nr, nc, sr, sc, dr, dc;
	char ch;
	cin>>ch>>sc;
	r=sr=ch-'A';
	c=--sc;
	for(int i=1;i<36;++i){
		cin>>ch>>nc;
		nr=ch-'A';
		nc--;
		dr=abs(r-nr), dc=abs(c-nc);
		if(chk[nr][nc] || dr>2 || dc>2 || dr+dc!=3){
			cout<<"Invalid\n";
			return 0;
		}
		r=nr, c=nc;
		chk[r][c]=1;
	}
	dr=abs(r-sr), dc=abs(c-sc);
	if(dr>2 || dc>2 || dr+dc!=3){
		cout<<"Invalid\n";
		return 0;
	}
	cout<<"Valid\n";
	return 0;
}
