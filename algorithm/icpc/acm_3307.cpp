#include<cstdio>
#include<stack>
using namespace std;
typedef double db;
db x[200000], r[200000];
int main(){
	int n;
	scanf("%d", &n);
	for(int i=0;i<n;++i){
		scanf("%lf %lf", &x[i], &r[i]);
	}
	stack<int> S;
	for(int i=0;i<n;++i){
		db a=r[i];
		while(S.size()){
			int j=S.top();
			db b=x[i]-x[j];
			b=b*b/4/r[j];
			if(b<a)	a=b;
			if(a>r[j])	S.pop();
			else	break;
		}
		r[i]=a;
		S.push(i);
	}
	for(int i=0;i<n;++i)	printf("%lf\n", r[i]);
	return 0;
}
