#include<iostream>
#include<stack>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, tmp, left, h;
	int ary[100000];
	long long res;
	cin>>n;
	while(n!=0){
		stack<int> S;
		int ary[n];
		res=0;
		cin>>ary[0];
		S.push(0);
		for(int i=1;i<=n;i++){
			if(i==n)	tmp=0;
			else{
				cin>>tmp;
				ary[i]=tmp;
			}
			while(!S.empty() && ary[h=S.top()]>tmp){
				S.pop();
				if(S.empty())	left=0;
				else	left=S.top()+1;
				res=max(res, (long long)ary[h]*(long long)(i-left));
			}
			S.push(i);
		}
		cout<<res<<"\n";
		cin>>n;
	}
	return 0;
}
