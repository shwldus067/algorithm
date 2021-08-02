#include<iostream>
using namespace std;

int main(){
	int N, a, b, c, i, j, k;
	cin>>N;
	int cost[N][3];
	int min[N][3];
	for(int i=0;i<N;i++){
		cin>>cost[i][0]>>cost[i][1]>>cost[i][2];
	}
	a=min[0][0]=cost[0][0];
	b=min[0][1]=cost[0][1];
	c=min[0][2]=cost[0][2];
	if(N==1){
		cout<<((a<b ? a:b)<c ? (a<b ? a:b):c);
		return 0;
	}
	for(i=1;i<N;i++){
		for(j=0;j<3;j++){
			min[i][j]=1000000;
			for(k=0;k<3;k++){
				if(j==k)	continue;
				a=min[i-1][k]+cost[i][j];
				if(a<min[i][j])	min[i][j]=a;
			}
		}
	}
	a=min[N-1][0];
	b=min[N-1][1];
	c=min[N-1][2];
	cout<<((a<b ? a:b)<c ? (a<b ? a:b):c);
	return 0;
}

