#include<iostream>
using namespace std;
int N, a[30];
char sol(int i, int n){
	if(i==0){
		if(n==1)	return 'm';
		else	return 'o';
	}
	if(n<a[i-1])	return sol(i-1, n);
	else if(n<a[i-1]+i+3){
		if(n==a[i-1]+1)	return 'm';
		else	return 'o';
	}
	else	return sol(i-1, n-a[i-1]-i-3);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	a[0]=3;
	int i;
	for(i=1;i<=30;++i){
		a[i]=a[i-1]+a[i-1]+i+3;
		if(a[i]>=N)	break;
	}
	cout<<sol(i, N)<<"\n";
	return 0;
}
