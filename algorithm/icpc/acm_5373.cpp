#include<iostream>
using namespace std;
int tc, N, num[26];
int chg[6][4]={{2, 4, 3 ,5},
		{2, 5, 3, 4},
		{0, 5, 1, 4},
		{0, 4, 1, 5},
		{0, 2, 1, 3},
		{0, 3, 1, 2}
};
int dir[6][4][3]={{{0, 1, 2}, {0, 1, 2}, {0, 1, 2}, {0, 1, 2}},
		{{4, 5, 6}, {4, 5, 6}, {4, 5, 6}, {4, 5, 6}},
		{{6, 5, 4}, {0, 7, 6}, {2, 1, 0}, {4, 3, 2}},
		{{0, 1, 2}, {6, 7, 0}, {4, 5, 6}, {2, 3, 4}},
		{{0, 7, 6}, {0, 7, 6}, {0, 7, 6}, {4, 3, 2}},
		{{2, 3, 4}, {6, 7, 0}, {2, 3, 4}, {2, 3, 4}}
};
char color[6]={'w', 'y', 'r', 'o', 'g', 'b'};
char cube[6][8];
void cw(int idx, int r){
	int k[4]={0, 1, 2, 3};
	if(idx!=r){
		k[1]=3;
		k[3]=1;
	}
	int t=chg[idx][3];
	char tmp[4][3];
	for(int i=0;i<3;++i){
		tmp[0][i]=cube[t][dir[r][k[3]][i]];
	}
	for(int i=0;i<3;++i){
		t=chg[idx][i];
		for(int j=0;j<3;++j){
			tmp[i+1][j]=cube[t][dir[r][k[i]][j]];
		}
	}
	for(int i=0;i<4;++i){
		t=chg[idx][i];
		for(int j=0;j<3;++j){
			cube[t][dir[r][k[i]][j]]=tmp[i][j];
		}
	}
}
void turn(int idx, char d){
	if(d=='+'){
		char tmp[8];
		for(int i=0;i<6;++i){
			tmp[i+2]=cube[idx][i];
		}
		tmp[0]=cube[idx][6], tmp[1]=cube[idx][7];
		for(int i=0;i<8;++i){
			cube[idx][i]=tmp[i];
		}
		cw(idx, idx);
	}
	else{
		int o=(idx&1 ? idx-1:idx+1);
		char tmp[8];
		for(int i=2;i<8;++i){
			tmp[i-2]=cube[idx][i];
		}
		tmp[6]=cube[idx][0], tmp[7]=cube[idx][1];
		for(int i=0;i<8;++i){
			cube[idx][i]=tmp[i];
		}
		cw(o, idx);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	num['U'-'A']=0;
	num['D'-'A']=1;
	num['F'-'A']=2;
	num['B'-'A']=3;
	num['L'-'A']=4;
	num['R'-'A']=5;
	cin>>tc;
	while(tc--){
		for(int i=0;i<6;++i){
			for(int j=0;j<8;++j){
				cube[i][j]=color[i];
			}
		}
		cin>>N;
		while(N--){
			char c, d;
			cin>>c>>d;
			turn(num[c-'A'], d);
		}
		cout<<cube[0][0]<<cube[0][1]<<cube[0][2]<<"\n";
		cout<<cube[0][7]<<"w"<<cube[0][3]<<"\n";
		cout<<cube[0][6]<<cube[0][5]<<cube[0][4]<<"\n";
	}
	return 0;
}
