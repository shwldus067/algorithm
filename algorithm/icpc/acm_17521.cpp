#include<iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, p, pre, f, s, i, m, M;
	long long W;
	cin>>N>>W;
	if(N==1){
		cout<<W<<"\n";
		return 0;
	}
	cin>>pre>>s;
	if(N==2){
		if(pre<s)	cout<<W/pre*s+W%pre<<"\n";
		else	cout<<W<<"\n";
		return 0;
	}
	m=pre;
	for(int i=2;i<N;){
		long long tmp=0;
		while(pre>=s){
			pre=s;
			m=s;
			if(i<N)	cin>>s;
			else	break;
			++i;
		}
		while(pre<s){
			pre=s;
			M=s;
			tmp=W/m*M+W%m;
			if(i<N)	cin>>s;
			else	break;
			++i;
		}
		if(tmp)	W=tmp;
	}
	cout<<W<<"\n";
	return 0;
}
