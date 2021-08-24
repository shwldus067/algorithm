#include<iostream>
using namespace std;
int A[1000000];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, l=0, r;
	cin>>N;
	r=N;
	for(int i=0;i<N;++i)	A[i]=i;
	while(r-l>1){
		l++;
		if(r-l==1)	break;
		A[r++]=A[l++];
	}
	cout<<A[l]+1<<"\n";
	return 0;
}
