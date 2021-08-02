#include<iostream>
using namespace std;
int N;
int f[1000001];
char a[2000001];
bool chk(int i){
	for(int j=i;j<N;j+=i){	//j개의 배열 비교 
		for(int k=0;k<i;++k){	//0~i-1 배열과 j~i+j-1배열 비교 
			if(a[k]!=a[j+k])	return false;
		}
	}
	return true;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	cin.get(a[0]);
	cin.getline(a, 2000001);
	for(int i=0, j=0;a[i];++i)if(a[i]!=' ')	a[j++]=a[i];
	int M=N/2+1;
	for(int i=1;i<M;++i){
		if(N%i)	continue;
		if(chk(i)){
			cout<<1<<'/'<<i<<'\n';
			return 0;
		}
	}
	cout<<1<<'/'<<N<<'\n';
	return 0;
}
