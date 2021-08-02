#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
struct ss{
	char s[16];
	bool operator<(const ss a)const{
		return strcmp(s, a.s)<0;
	}
};
struct node{
	map<ss, node*> next;
};
ss arr[15];
node* insert(int n, int k, node *p){
	if(!p)	p=new node;
	map<ss, node*>::iterator iter=p->next.find(arr[k]);
	if(iter==p->next.end())	p->next.insert({arr[k], NULL}), iter=p->next.find(arr[k]);
	if(n-1>k)	iter->second=insert(n, k+1, iter->second);
	return p;
}
void print(node *p, int n){
	map<ss, node*>::iterator iter, end;
	end=p->next.end();
	for(iter=p->next.begin();iter!=end;++iter){
		for(int i=0;i<n;++i)	printf("--");
		printf("%s\n", iter->first.s);
		if(iter->second!=NULL)	print(iter->second, n+1);
	}
}
int main(){
	int N, K;
	node root;
	scanf("%d", &N);
	for(int i=0;i<N;++i){
		scanf("%d", &K);
		for(int j=0;j<K;++j)	scanf("%s", &arr[j].s);
		insert(K, 0, &root);
	}
	print(&root, 0);
	return 0;
}
