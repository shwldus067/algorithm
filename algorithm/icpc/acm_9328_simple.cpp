#include<cstdio>
#include<vector>
using namespace std;
char arr[102][102];
int queue[10000];
int tc, h, w, head, tail;
int dr[]={-1, 0, 1, 0}, dc[]={0, 1, 0, -1};
vector<int> doors[26];
bool key[26];
int main(){
	scanf("%d", &tc);
	while(tc--){
		scanf("%d %d", &h, &w);
		head=0, tail=0;
		for(int i=0;i<26;i++){
			doors[i].clear();
			key[i]=false;
		}
		for(int i=1;i<=h;i++){
			for(int j=1;j<=w;j++){
				scanf("%1s", &arr[i][j]);
			}
		}
		scanf("%s", arr[0]);
		if(arr[0][0]!='0'){
			for(char *c=arr[0];*c>='a' && *c<='z';c++)
				key[*c-'a']=true;
		}
		for(int i=1;i<=w;i++){
			arr[0][i]='*';
			arr[h+1][i]='*';
			if(arr[1][i]!='*')	queue[tail++]=1000+i;
			if(arr[h][i]!='*')	queue[tail++]=h*1000+i;
		}
		for(int i=1;i<=h;i++){
			arr[i][0]='*';
			arr[i][w+1]='*';
			if(arr[i][1]!='*')	queue[tail++]=i*1000+1;
			if(arr[i][w]!='*')	queue[tail++]=i*1000+w;
		}
		int ans=0;
		while(head<tail){
			int cur=queue[head%10000];
			head++;
			int cr=cur/1000, cc=cur%1000;
			char c=arr[cr][cc];
			if(c=='*')	continue;
			if(c>='A' && c<='Z'){
				if(!key[c-'A']){
					doors[c-'A'].push_back(cur);
					continue;
				}
			}
			else if(c>='a' && c<='z'){
				if(!key[c-'a']){
					key[c-'a']=true;
					vector<int> &door=doors[c-'a'];
					for(int i=door.size()-1;i>=0;i--){
						queue[tail%10000]=door[i];
						tail++;
					}
				}
			}
			else if(c=='$')	ans++;
			arr[cr][cc]='*';
			for(int i=0;i<4;i++){
				int nr=cr+dr[i], nc=cc+dc[i];
				if(arr[nr][nc]!='*'){
					queue[tail%10000]=nr*1000+nc;
					tail++;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
