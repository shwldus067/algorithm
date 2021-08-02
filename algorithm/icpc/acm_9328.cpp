#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int tc, h, w;
int dr[]={-1, 0, 1, 0}, dc[]={0, 1, 0, -1};
char arr[102][102];
bool key[26];
bool visit[102][102];
bool chk(int nr, int nc){
	return nr>=0 && nr<=h+1 && nc>=0 && nc<=w+1;
}
int bfs(void){
	int r, c, nr, nc, nk, ans=0;
	queue<pair<int, int> > Q;
	queue<pair<int, int> > wq[26];
	Q.push({0, 0});
	visit[0][0]=true;
	while(!Q.empty()){
		r=Q.front().first, c=Q.front().second;
		Q.pop();
		for(int i=0;i<4;i++){
			nr=r+dr[i], nc=c+dc[i];
			if(!chk(nr, nc))	continue;
			if(arr[nr][nc]=='*')	continue;
			if(visit[nr][nc])	continue;
			visit[nr][nc]=true;
			if(arr[nr][nc]=='$'){
				ans++;
			}
			else if(arr[nr][nc]>='A' && arr[nr][nc]<='Z'){
				nk=arr[nr][nc]-'A';
				if(key[nk]==false){
					wq[nk].push({nr, nc});
					continue;
				}
			}
			else if(arr[nr][nc]>='a' && arr[nr][nc]<='z'){
				nk=arr[nr][nc]-'a';
				key[nk]=true;
				while(!wq[nk].empty()){
					int kr=wq[nk].front().first, kc=wq[nk].front().second;
					wq[nk].pop();
					Q.push({kr, kc});
				}
			}
			Q.push({nr, nc});
		}
	}
	return ans;
}
int main(){
	scanf("%d", &tc);
	for(int i=0;i<102;i++){
		arr[0][i]='.';
	}
	while(tc--){
		memset(arr, 0, sizeof(arr));
		memset(key, false, sizeof(key));
		memset(visit, false, sizeof(visit));
		int i, j;
		scanf("%d %d", &h, &w);
		for(i=1;i<=h;i++){
			for(j=1;j<=w;j++){
				char temp;
				scanf("%1s", &temp);
				if(temp!='.')	arr[i][j]=temp;
			}
		}
		char k[30];
		scanf("%s", k);
		for(int i=0;i<(int)strlen(k);i++){
			if(key[i]=='0')	break;
			key[k[i]-'a']=true;
		}
		printf("%d\n", bfs());
	}
	return 0;
}
