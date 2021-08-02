#include<iostream>
using namespace std;
const int ninf=1<<31;
const int inf=ninf-1;
int N, maxc[10][10], minc[10][10];
char expr[20];
int cal(int a, int b, char o){
	switch(o){
		case '+':
			return a+b;
		case '-':
			return a-b;
		case '*':
			return a*b;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>expr;
	for(int i=0;i<10;++i)for(int j=0;j<10;++j){
		maxc[i][j]=ninf, minc[i][j]=inf;
	}
	int M=N/2+1;
	for(int i=0;i<M;++i)	maxc[i][i]=minc[i][i]=expr[i*2]-'0';
	for(int m=1;m<M;++m){	//구간의 길이 
		for(int idx=0;idx<M-m;++idx){	//구간의 시작 인덱스 
			for(int i=0;i<m;++i){	//중간 인덱스 
				char op=expr[(idx+i)*2+1];
				int a=cal(maxc[idx][idx+i], maxc[idx+i+1][idx+m], op);
				int b=cal(maxc[idx][idx+i], minc[idx+i+1][idx+m], op);
				int c=cal(minc[idx][idx+i], maxc[idx+i+1][idx+m], op);
				int d=cal(minc[idx][idx+i], minc[idx+i+1][idx+m], op);
				maxc[idx][idx+m]=max(maxc[idx][idx+m], max(a, max(b, max(c, d))));
				minc[idx][idx+m]=min(minc[idx][idx+m], min(a, min(b, min(c, d))));
			}
		}
	}
	cout<<maxc[0][M-1]<<"\n";
	return 0;
}
