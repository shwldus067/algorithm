#include<iostream>
using namespace std;
int d[1000001], n[1000001];
int sol(int x){
	if(x==1)	return 0;
	int &ret=d[x], t;
	if(ret)	return ret;
	ret=1e7;
	if(x%3==0){
		t=sol(x/3)+1;
		if(ret>t){
			ret=t;
			n[x]=x/3;
		}
	}
	if(x%2==0){
		t=sol(x/2)+1;
		if(ret>t){
			ret=t;
			n[x]=x/2;
		}
	}
	t=sol(x-1)+1;
	if(ret>t){
		ret=t;
		n[x]=x-1;
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin>>N;
	if(N==1){
		cout<<"0\n1\n";
		return 0;
	}
	cout<<sol(N)<<"\n";
	for(int i=N;i;i=n[i]){
		cout<<i<<" ";
	}
	cout<<"\n";
	return 0;
}
