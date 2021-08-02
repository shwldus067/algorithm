#include<iostream>
using namespace std;
const int inf=~(1<<31);
int main(){
	int N;
	cin>>N;
	int d[N+1]={0, };
	int t=1, s=1, p;
	for(int i=1;i<=N;++i){
		if(s==i){
			++t;
			s=t*t;
			d[i]=1;
			continue;
		}
		d[i]=d[i-1]+1;
		for(int j=2;j<t;++j){
			p=j*j;
			d[i]=min(d[i], d[p]+d[i-p]);
		}
	}
	cout<<d[N]<<"\n";
	return 0;
}
