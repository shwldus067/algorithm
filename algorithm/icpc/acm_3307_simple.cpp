#include<cstdio>
#include<stack>
using namespace std;
typedef double db;
pair<int, db> st[200001];
int top;
int main(){
	int n;
	scanf("%d", &n);
	for(int i=0;i<n;++i){
		int x, r;
		scanf("%d %d", &x, &r);
		db a=r;
		while(top){
			db b=(double)x-st[top-1].first;
			b=b*b/4/st[top-1].second;
			if(b<a)	a=b;
			if(a<st[top-1].second)	break;
			else	top--;
		}
		st[top++]={x, a};
		printf("%.4lf\n", a);
	}
	return 0;
}
