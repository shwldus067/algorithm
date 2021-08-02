#include<iostream>
#include<stack>
using namespace std;
int N, arr[100001];
long long sum[100001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	cin>>arr[0];
	sum[0]=arr[0];
	stack<int> S;
	S.push(0);
	int x;
	long long r, l;
	long long res=0;
	for(int i=1;i<=N;++i){
		if(i!=N){
			cin>>arr[i];
			sum[i]=sum[i-1]+(long long)arr[i];
		}
		while(!S.empty() && arr[i]<arr[x=S.top()]){
			r=sum[i-1];
			S.pop();
			if(S.empty())	l=0;
			else	l=sum[S.top()];
			res=max(res, (long long)arr[x]*(r-l));
		}
		S.push(i);
	}
	cout<<res<<"\n";
	return 0;
}
