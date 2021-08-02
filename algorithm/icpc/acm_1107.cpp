#include<iostream>
using namespace std;
bool out[10]={false, };
bool fun(int i){
	if(i==0 && out[i]) return false;
	int n=i;
	while(n>0){
		if(out[n%10]){
			return false;
		}
		n/=10;
	}
	return true;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, M, t, res, n, k, cnt=0;
	cin>>N>>M;
	for(int i=0;i<M;i++)	cin>>t, out[t]=true;
	if(N==100){
		cout<<0<<"\n";
		return 0;
	}
	res=N-100;
	res=res>0 ? res:-res;
	if(M==10){
		cout<<res<<"\n";
		return 0;
	}
	k=0;
	while(1){
		if(res<=k){
			break;
		}
		if(N-k>=0 && fun(N-k)){
			n=N-k;
			break;
		}
		else if(fun(N+k)){
			n=N+k;
			break;
		}
		else{
			k++;
		}
	}
	t=1;
	if(n==0)	cnt=1;
	while(n/t!=0){
		t*=10;
		cnt++;
	}
	res=res<cnt+k ? res:cnt+k;
	cout<<res<<"\n";
	return 0;
}
