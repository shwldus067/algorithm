#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	int R, C, r, c, cnt=0, bomb[10000], bc, tt=0, nt=1;
	pair<int, int> crazy[10000];
	char arr[2][100][101], str[101];
	int dr[10]={0, 1, 1, 1, 0, 0, 0, -1, -1, -1};
	int dc[10]={0, -1, 0, 1, -1, 0, 1, -1, 0, 1};
	scanf("%d %d", &R, &C);
	for(int i=0;i<R;++i){
		scanf("%s", arr[0][i]+0);
		for(int j=0;j<C;++j){
			if(arr[0][i][j]=='I')	r=i, c=j;
			else if(arr[0][i][j]=='R')	crazy[cnt++]={i, j};
		}
	}
	scanf("%s", str);
	for(int k=0;str[k];++k){
		for(int i=0;i<R;++i)for(int j=0;j<C;++j)	arr[nt][i][j]='.';
		int d=(int)(str[k]-'0');
		arr[tt][r][c]='.';
		r=r+dr[d];c=c+dc[d];
		if(arr[tt][r][c]!='.'){
			printf("kraj %d\n", k+1);
			return 0;
		}
		arr[nt][r][c]='I';
		bc=0;
		for(int i=0;i<cnt;++i){
			if(crazy[i].first==-1)	continue;
			int rr=crazy[i].first, cc=crazy[i].second;
			if(arr[tt][rr][cc]!='R'){
				crazy[i].first=-1;
				continue;
			}
			if(rr<r)	++rr;
			else if(rr>r)	--rr;
			if(cc<c)	++cc;
			else if(cc>c)	--cc;
			if(rr==r && cc==c){
				printf("kraj %d\n", k+1);
				return 0;
			}
			if(arr[nt][rr][cc]=='R'){
				bomb[bc++]=i;
			}
			arr[nt][rr][cc]='R';
			crazy[i]={rr, cc};
		}
		for(int i=0;i<bc;++i){
			arr[nt][crazy[bomb[i]].first][crazy[bomb[i]].second]='.';
		}
		nt=tt;tt^=1;
	}
	for(int i=0;i<R;++i)	printf("%s\n", arr[tt][i]);
	return 0;
}
