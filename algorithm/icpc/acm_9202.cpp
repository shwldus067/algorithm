#include<iostream>
using namespace std;
struct node{
	int lv=0, end=0, f=0;
	node *v[26]={0, };
	node(){
		lv=end=f=0;
		for(int i=0;i<26;++i)	v[i]=0;
	}
};
node *root;
int score[9]={0, 0, 0, 1, 1, 2, 3, 5, 11}, ans, ml, cnt, turn;
int dr[8]={-1, -1, -1, 0, 1, 1, 1, 0};
int dc[8]={-1, 0, 1, 1, 1, 0, -1, -1};
char chr[10], board[4][5], out[10], tword[10];
bool visit[4][4];
void insert(node *vec, int n){
	if(chr[n]==0){
		vec->end=1;
		return;
	}
	int cw=chr[n]-'A';
	node *nxt=vec->v[cw];
	if(nxt==NULL){
		nxt=new node;
		vec->v[cw]=nxt;
		nxt->lv=vec->lv+1;
	}
	insert(nxt, n+1);
}
bool sol(){
	for(int i=0;i<ml;++i){
		if(tword[i]<out[i])	return true;
		else if(tword[i]>out[i])	return false;
	}
	return false;
}
void find(node *cur, int r, int c){
	int cw=board[r][c]-'A';
	tword[cur->lv-1]=board[r][c];
	if(cur->end && cur->f!=turn){
		ans+=score[cur->lv];
		++cnt;
		cur->f=turn;
		if(ml<cur->lv || (ml==cur->lv && sol())){
			ml=cur->lv;
			for(int i=0;i<ml;++i)	out[i]=tword[i];
			out[ml]=0;
		}
	}
	for(int i=0;i<8;++i){
		int nr=r+dr[i], nc=c+dc[i], nw;
		if(nr<0 || nr>3 || nc<0 || nc>3)	continue;
		nw=board[nr][nc]-'A';
		if(visit[nr][nc] || cur->v[nw]==NULL)	continue;
		visit[nr][nc]=1;
		find(cur->v[nw], nr, nc);
		visit[nr][nc]=0;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int w, b;
	cin>>w;
	root=new node;
	for(int i=0;i<w;++i){
		cin>>chr;
		insert(root, 0);
	}
	cin>>b;
	turn=1;
	while(b--){
		for(int i=0;i<4;++i)	cin>>board[i];
		ans=ml=cnt=0;
		for(int i=0;i<4;++i){
			for(int j=0;j<4;++j){
				int tm=board[i][j]-'A';
				if(root->v[tm]==0)	continue;
				visit[i][j]=1;
				find(root->v[tm], i, j);
				visit[i][j]=0;
			}
		}
		cout<<ans<<" "<<out<<" "<<cnt<<"\n";
		turn++;
	}
	return 0;
}
