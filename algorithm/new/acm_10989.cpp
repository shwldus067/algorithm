#include<iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, tmp, max=0;
	cin>>N;
	int ary[10001]={0, };
	for(int i=0;i<N;i++){
		cin>>tmp;
		ary[tmp]++;
		if(max<tmp)	max=tmp;
	}
	for(int i=1;i<=max;i++){
		if(ary[i]){
			for(int j=0;j<ary[i];j++)	cout<<i<<"\n";
		}
	}
}
