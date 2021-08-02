#include<iostream>
using namespace std;
int N, M;
char ans[100][100];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	char tmp;
	for(int i=0;i<N;++i){
		for(int j=1;j<=M;++j){
			cin>>tmp;
			switch(tmp){
				case '.':
					ans[M-j][i]='.';break;
				case 'O':
					ans[M-j][i]='O';break;
				case '-':
					ans[M-j][i]='|';break;
				case '|':
					ans[M-j][i]='-';break;
				case '/':
					ans[M-j][i]=92;break;
				case 92:
					ans[M-j][i]='/';break;
				case '^':
					ans[M-j][i]='<';break;
				case '<':
					ans[M-j][i]='v';break;
				case 'v':
					ans[M-j][i]='>';break;
				case '>':
					ans[M-j][i]='^';break;
			}
		}
	}
	for(int i=0;i<M;++i){
		for(int j=0;j<N;++j){
			cout<<ans[i][j];
		}
		cout<<"\n";
	}
	return 0;
}
