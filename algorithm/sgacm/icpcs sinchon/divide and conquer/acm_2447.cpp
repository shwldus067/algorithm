#include<iostream>
#include<cstring>
using namespace std;
int N;
char *arr;
void sol(int n, int x, int y){
	if(n==3){
		char *p=arr+y*(N+1)+x;
		for(int i=0;i<3;++i){
			for(int j=0;j<3;++j){
				*(p+i*(N+1)+j)='*';
			}
		}
		*(p+N+2)=' ';
		return;
	}
	int next=n/3;
	for(int i=0;i<3;++i){
		for(int j=0;j<3;++j){
			if(i==1 && j==1)	continue;
			sol(next, x+i*next, y+j*next);
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	int size=N*(N+1);
	arr=new char[size];
	memset(arr, ' ', size);
	for(int i=0;i<N-1;++i)	arr[(i+1)*(N+1)-1]='\n';
	arr[size-1]=0;
	sol(N, 0, 0);
	cout<<arr<<"\n";
	return 0;
}
