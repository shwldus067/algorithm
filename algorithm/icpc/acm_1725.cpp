#include<iostream>
#include<stack>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, left, right, arr[100001], x;
	long long res=0;
	cin>>n;
	stack<int> S;
	cin>>arr[0];
	S.push(0);
	for(int i=1;i<=n;++i){
		if(i==n)	arr[i]=0;
		else	cin>>arr[i];
		while(!S.empty() && arr[x=S.top()]>arr[i]){
			right=i-1;
			S.pop();
			if(S.empty())	left=0;
			else	left=S.top()+1;
			res=max(res, (long long)arr[x]*(long long)(right-left+1));
		}
		S.push(i);
	}
	cout<<res<<"\n";
	return 0;
}
