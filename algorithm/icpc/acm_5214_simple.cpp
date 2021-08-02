#include<cstdio>
#include<queue>
using namespace std;
char buf[1<<17];
inline char read(){
	static int idx=1<<17;
	if(idx==1<<17){
		fread(buf, 1, 1<<17, stdin);
		idx=0;
	}
	return buf[idx++];
}
inline int readInt(){
	int sum=0;
	bool f=0;
	char cur=read();
	while(cur!='-' && (cur==10 || cur==32))	cur=read();
	if(cur=='-')	f=1, cur=read();
	while(cur>=48 && cur<=57){
		sum=sum*10+cur-48;
		cur=read();
	}
	if(f)	sum=-sum;
	return sum;
}
vector<int> adj[100001];
bool visit[100001], chk[1000];
int arr[1000][1000];
int main(){
	int N, K, M, ans=1, sz;
	N=readInt();K=readInt();M=readInt();
	if(N==1){
		printf("1\n");
		return 0;
	}
	for(int i=0;i<M;++i){
		for(int j=0;j<K;++j){
			arr[i][j]=readInt();
			adj[arr[i][j]].push_back(i);
		}
	}
	queue<int> Q;
	Q.push(1);
	visit[1]=1;
	while(sz=Q.size()){
		while(sz--){
			int cur=Q.front();Q.pop();
			if(cur==N){
				printf("%d\n", ans);return 0;
			}
			for(int nxt:adj[cur]){
				if(chk[nxt])	continue;
				chk[nxt]=1;
				for(int i=0;i<K;++i){
					int n=arr[nxt][i];
					if(visit[n])	continue;
					visit[n]=1;
					Q.push(n);
				}
			}
		}
		++ans;
	}
	printf("-1\n");
	return 0;
}
