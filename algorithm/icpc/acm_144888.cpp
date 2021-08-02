#include<iostream>
using namespace std;
int N, A[11], B[4];
pair<int, int> m=make_pair(-1000000000, 1000000000);
void func(int n, int s){
	if(n==N){
		m.first=m.first>s ? m.first:s;
		m.second=m.second<s ? m.second:s;
		return ;
	}
	if(n==1){
		for(int i=0;i<4;i++){
			if(B[i]==0)	continue;
			B[i]--;
			switch(i){
				case 0 : func(n+1, A[n-1]+A[n]);
						 break;
				case 1 : func(n+1, A[n-1]-A[n]);
						break;
				case 2 : func(n+1, A[n-1]*A[n]);
						 break;
				case 3 : func(n+1, A[n-1]/A[n]);
						 break;
			}
			B[i]++;
		}
		return ;
	}
	for(int i=0;i<4;i++){
		if(B[i]==0)	continue;
		B[i]--;
		switch(i){
			case 0 : func(n+1, s+A[n]);
					 break;
			case 1 : func(n+1, s-A[n]);
					break;
			case 2 : func(n+1, s*A[n]);
					 break;
			case 3 : func(n+1, s/A[n]);
					 break;
		}
		B[i]++;
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>N;
	for(int i=0;i<N;i++)	cin>>A[i];
	for(int i=0;i<4;i++)	cin>>B[i];
	func(1, 0);
	cout<<m.first<<"\n";
	cout<<m.second<<"\n";
	return 0;
}
