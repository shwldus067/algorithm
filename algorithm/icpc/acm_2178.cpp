#include<cstdio>
#include<queue>
using namespace std;
typedef pair<int, int> pii;
int main(){
	int N, M, size, ans=1, flag=0;
	char arr[100][101];
	bool visit[100][100]={0, };
	scanf("%d %d", &N, &M);
	for(int i=0;i<N;++i)	scanf("%s", &arr[i]);
	queue<pii> Q;
	Q.push({0, 0});
	visit[0][0]=1;
	while(size=Q.size()){
		while(size--){
			int r=Q.front().first, c=Q.front().second;
			Q.pop();
			if(r==N-1 && c==M-1){
				flag=1;
				break;
			}
			for(int i=0;i<4;++i){
				int nr=r+"2101"[i]-'1', nc=c+"1210"[i]-'1';
				if(nr<0 || nr>=N || nc<0 || nc>=M)	continue;
				if(arr[nr][nc]=='0')	continue;
				if(visit[nr][nc])	continue;
				visit[nr][nc]=1;
				Q.push({nr, nc});
			}
		}
		if(flag)	break;
		ans++;
	}
	printf("%d\n", ans);
	return 0;
}
