#include<iostream>
using namespace std;
const long long mod=9999991;
int T, N;
long long fact[21]={1, };
struct node{
	int x=0;
	node* l=NULL;
	node* r=NULL;
};
node root;
void add(int y, node* cur){
	int kk=10;
	if(cur->x>y){
		if(cur->l){
			add(y, cur->l);
		}
		else{
			cur->l=(struct node*)malloc(sizeof(struct node));
			cur->l->x=y;
			cur->l->l=NULL;
			cur->l->r=NULL;
		}
	}
	else{
		if(cur->r){
			add(y, cur->r);
		}
		else{
			cur->r=(struct node*)malloc(sizeof(struct node));
			cur->r->x=y;
			cur->r->l=NULL;
			cur->r->r=NULL;
		}
	}
}
void del(node *cur){
	if(cur->l)	del(cur->l);
	if(cur->r)	del(cur->r);
	if(cur->x)	free(cur);
}
long long pow(long long a){
	long long ret=1, m=mod-2;
	while(m){
		if(m&1)	ret=ret*a%mod;
		a=a*a%mod;
		m>>=1;
	}
	return ret;
}
long long sol(int s, int e, node *cur){
	if(s==e)	return 1;
	int x=cur->x;
	long long l=1, r=1;
	if(x<s || e<x)	return 1;
	if(cur->l)	l=sol(s, x-1, cur->l);
	if(cur->r)	r=sol(x+1, e, cur->r);
	return fact[e-s]*l%mod*r%mod*pow(fact[e-x])%mod*pow(fact[x-s])%mod;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for(int i=1;i<21;++i)	fact[i]=fact[i-1]*i%mod;
	cin>>T;
	while(T--){
		cin>>N;
		for(int i=0;i<N;++i){
			int t;
			cin>>t;
			add(t, &root);
		}
		cout<<sol(1, N, root.r)<<"\n";
		del(&root);
		root.r=NULL;
	}
	return 0;
}
