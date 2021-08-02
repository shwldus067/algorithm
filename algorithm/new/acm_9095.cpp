#include<iostream>
using namespace std;

int main(){
	int n, T;
	int ary[11];
	cin>>T;
	ary[1]=1;
	ary[2]=2;
	ary[3]=4;
	for(int i=4;i<11;i++){
		ary[i]=ary[i-1]+ary[i-2]+ary[i-3];
	}
	for(int i=0;i<T;i++){
		cin>>n;
		cout<<ary[n]<<endl;
	}
	return 0;
}
