#include<iostream>
using namespace std;
int N, W[10];
bool ch[10];
int func(int n, int s){
	if(n==2)	return s;
	int ret=0, i, j, k, t;
	for(i=1;i<N-1;i++){
		if(ch[i])	continue;
		ch[i]=true;
		for(j=i-1;j>=0;j--){
			if(ch[j]==false)	break;
		}
		for(k=i+1;k<N;k++){
			if(ch[k]==false)	break;
		}
		t=func(n-1, s+W[j]*W[k]);
		ret=ret>t ? ret:t;
		ch[i]=false;
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>N;
	for(int i=0;i<N;i++)	cin>>W[i];
	cout<<func(N, 0)<<"\n";
	return 0;
}
