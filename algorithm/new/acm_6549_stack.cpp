#include<iostream>
#include<stack>
using namespace std;

int main(){
	int n, tmp, left, right, h;
	int ary[100000];
	long long res;
	cin>>n;
	while(n!=0){
		stack<int> S;
		int ary[n];
		res=0;
		cin>>tmp;
		ary[0]=tmp;
		S.push(0);
		for(int i=1;i<n;i++){
			cin>>tmp;
			ary[i]=tmp;
			while(!S.empty() && ary[h=S.top()]>tmp){
				right=i-1;
				S.pop();
				if(S.empty())	left=0;
				else	left=S.top()+1;
				res=max(res, (long long)ary[h]*(long long)(right-left+1));
			}
			S.push(i);
		}
		right=n-1;
		while(S.size()>1){
			h=S.top();
			S.pop();
			left=S.top()+1;
			res=max(res, (long long)ary[h]*(long long)(right-left+1));
		}
		h=S.top();
		S.pop();
		res=max(res, (long long)ary[h]*(long long)n);
		cout<<res<<"\n";
		cin>>n;
	}
	return 0;
}
