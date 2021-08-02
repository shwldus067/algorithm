#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int N, cnt, idx=0, *tp;
	cin>>N;
	int kids;
	int a[N];
	cin>>kids;
	a[0]=kids;
	cnt=1;
	for(int i=1;i<N;i++){
		cin>>kids;
		if(a[idx]<kids){
			a[++idx]=kids;
			cnt++;
		}
		else{
			tp=lower_bound(a, a+idx, kids);
			*tp=kids;
		}
	}
	cout<<N-cnt<<"\n";
}
