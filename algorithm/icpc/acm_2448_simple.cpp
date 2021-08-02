#include<cstdio>
#include<cstring>
using namespace std;
int N;
char *arr;
void sol(int n, int x, int y, int w){
	if(n==3){
		char* p=arr+y*w+x;
		*(p+2)='*';
		p+=w;
		*(p+1)=*(p+3)='*';
		for(int i=0;i<5;i++)	*(p+w+i)='*';
		return;
	}
	int h=n/2;
	sol(h, x+h, y, w);
	sol(h, x, y+h, w);
	sol(h, x+n, y+h, w);
}
int main(){
	scanf("%d", &N);
	int m=N*2, l=m*N;
	arr=new char[l];
	memset(arr, ' ', l);
	for(int i=0;i<N-1;i++)	arr[(i+1)*m-1]='\n';
	arr[l-1]=0;
	sol(N, 0, 0, m);
	printf("%s", arr);
	return 0;
}
