#include<cstdio>
using namespace std;
int a[10], f[9]={1, 1, 2, 6, 24, 120, 720, 5040, 40320};
int ch[363000], d[363000], q[363000];
int dx[]={-1, 1, -3, 3};
int num(int a[]){
	int ret=0;
	for(int i=0;i<9;i++)	ret=ret*10+a[i];
	return ret;
}
int chk(int a[]){
	int ret=0;
	for(int i=0;i<9;i++){
		int k=0;
		for(int j=i+1;j<9;j++){
			if(a[i]>a[j])	k++;
		}
		ret+=f[8-i]*k;
	}
	return ret;
}
int main(){
	for(int i=0;i<9;i++){
		scanf("%d", a+i);
		a[i]++;
	}
	int s=-1, e=-1, t[10], v, x, w, y, z;
	q[++e]=num(a);
	ch[chk(a)]=1;
	while(s<e){
		x=q[++s];
		if(x==234567891){
			printf("%d\n", d[s]);
			return 0;
		}
		for(int i=8;i>=0;i--){
			t[i]=x%10;
			x/=10;
			if(t[i]==1)	v=i;
		}
		for(int i=0;i<4;i++){
			w=v+dx[i];
			if(i>=2 && (w<0 || w>8))	continue;
			if(i<2 && (w<0 || w>8 || v/3!=w/3))	continue;
			y=t[v]; t[v]=t[w]; t[w]=y;
			z=chk(t);
			if(ch[z]==0){
				q[++e]=num(t);
				d[e]=d[s]+1;
				ch[z]=1;
			}
			y=t[v]; t[v]=t[w]; t[w]=y;
		}
	}
	printf("-1\n");
	return 0;
}
