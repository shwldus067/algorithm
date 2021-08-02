#include<iostream>
#include<algorithm>
using namespace std;
int N, A[200000];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, fx, fy, px, py;
	cin>>N>>fx>>fy;
	N*=2, px=fx+=1e6, py=fy+=1e6;
	for(int i=2;i<N;i+=2){
		int x, y;
		cin>>x>>y;
		x+=1e6, y+=1e6;
		if(x==px)	A[i]=min(y, py)*4+3, A[i+1]=max(y, py)*4+2;
		else A[i]=min(x, px)*4+1, A[i+1]=max(x, px)*4;
		px=x, py=y;
	}
	if(fx==px)	A[0]=min(py, fy)*4+3, A[1]=max(py, fy)*4+2;
	else	A[0]=min(px, fx)*4+1, A[1]=max(px, fx)*4;
	sort(A, A+N);
	int ans=0, a=0, b=0;
	for(int i=0;i<N;++i){
		ans=max(ans, A[i]&2 ? (A[i]&1 ? ++a:--a):(A[i]&1 ? ++b:--b));
	}
	cout<<ans<<"\n";
	return 0;
}
