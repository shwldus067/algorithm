#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int N, tmp;
	cin>>N;
	int ary[N];
	for(int i=0;i<N;i++){
		cin>>ary[i];
	}
	sort(ary, ary+N);
	cout<<ary[0]<<" ";
	for(int i=1;i<N;i++){
		tmp=ary[i-1];
		if(tmp!=ary[i])	cout<<ary[i]<<" ";
	}
	cout<<"\n";
	return 0;
}
