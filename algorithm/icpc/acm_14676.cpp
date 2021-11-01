#include<iostream>
using namespace std;
int nxt[100001][3], in[100001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M, K, X, Y;
	int chk[100001]={0, };
	int pos[100001]={0, };
	cin>>N>>M>>K;
	while(M--){
		cin>>X>>Y;
		if(nxt[X][0]==0)	nxt[X][0]=Y;
		else if(nxt[X][1]==0)	nxt[X][1]=Y;
		else	nxt[X][2]=Y;
		in[Y]++;
	}
	while(K--){
		cin>>X>>Y;
		if(X==1){
			if(pos[Y]==in[Y] || in[Y]==0){
				chk[Y]++;
				if(chk[Y]>1)	continue;
				for(int i=0;i<3;++i)	pos[nxt[Y][i]]++;
			}else{
				cout<<"Lier!\n";
				return 0;
			}
		}else{
			if(!chk[Y]){
				cout<<"Lier!\n";
				return 0;
			}else{
				chk[Y]--;
				if(chk[Y])	continue;
				for(int i=0;i<3;++i)	pos[nxt[Y][i]]--;
			}
		}
	}
	cout<<"King-God-Emperor\n";
	return 0;
}
