#include<iostream>
using namespace std;
int N, d[1001];
bool s[1000];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=2;i<=N;++i){
		fill(s, s+i+1, 0);
		for(int j=0;j<i-1;++j){
			s[d[j]^d[i-j-2]]=1;
		}
		for(int j=0;j<=i;++j){
			if(!s[j]){
				d[i]=j;break;
			}
		}
	}
	if(d[N])	cout<<"1\n";
	else 	cout<<"2\n";
	return 0;
}
